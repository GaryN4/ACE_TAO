/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
// 
// = FILENAME
//   ACE_Strategies_T.h 
//
// = AUTHOR
//    Doug Schmidt 
// 
// ============================================================================

#if !defined (ACE_STRATEGIES_T_H)
#define ACE_STRATEGIES_T_H

#include "ace/Service_Config.h"
#include "ace/Synch_Options.h"

template <class SVC_HANDLER>
class ACE_Creation_Strategy
  // = TITLE
  //     Defines the interface for specifying a creation strategy for
  //     a SVC_HANDLER.  
  //
  // = DESCRIPTION
  //     The default behavior is to make a new SVC_HANDLER.  However,
  //     subclasses can override this strategy to perform SVC_HANDLER
  //     creation in any way that they like (such as creating subclass
  //     instances of SVC_HANDLER, using a singleton, dynamically
  //     linking the handler, etc.).
{
public:
  // = Initialization and termination methods.

  ACE_Creation_Strategy (ACE_Thread_Manager * = 0);
  // Default constructor.

  int open (ACE_Thread_Manager * = 0);
  // A <Thread_Manager> is useful when creating active objects.

  virtual ~ACE_Creation_Strategy (void);

  // = Factory method.
  virtual int make_svc_handler (SVC_HANDLER *&sh);
  // Create a SVC_HANDLER with the appropriate creation strategy.  The
  // default behavior of this method is to make a new <SVC_HANDLER> if
  // <sh> == 0 (passing in the <Thread_Manager>), else <sh> is
  // unchanged.  Returns -1 on failure, else 0.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  ACE_Thread_Manager *thr_mgr_;
  // Pointer to a thread manager.
};

template <class SVC_HANDLER>
class ACE_Singleton_Strategy : public ACE_Creation_Strategy<SVC_HANDLER>
  // = TITLE
  //     Defines the interface for specifying a creation strategy for
  //     a <SVC_HANDLER> that always returns the same <SVC_HANDLER> (i.e.,
  //     it's a Singleton).  
  //
  // = DESCRIPTION
  //     Note that this class takes over the ownership of the
  //     SVC_HANDLER passed into it as a parameter and it becomes
  //     responsible for deleting this object.
{
public:
  // = Initialization and termination methods.
  ACE_Singleton_Strategy (SVC_HANDLER * = 0,
			  ACE_Thread_Manager * = 0);
  int open (SVC_HANDLER *,
	    ACE_Thread_Manager * = 0);
  virtual ~ACE_Singleton_Strategy (void);
  
  // = Factory method.
  virtual int make_svc_handler (SVC_HANDLER *&);
  // Create a Singleton SVC_HANDLER by always returning the same
  // SVC_HANDLER.  Returns -1 on failure, else 0.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:  
  SVC_HANDLER *svc_handler_;
  // Pointer to the Singleton svc_handler.
};

template <class SVC_HANDLER>
class ACE_DLL_Strategy : public ACE_Creation_Strategy<SVC_HANDLER>
  // = TITLE
  //     Defines the interface for specifying a creation strategy for
  //     a SVC_HANDLER based on dynamic linking of the SVC_HANDLER.
{
public:
  // = Intialization and termination methods.

  ACE_DLL_Strategy (void);
  // "Do-nothing" constructor.

  ACE_DLL_Strategy (const char svc_dll_info[],
		    ACE_Service_Config *,
		    ACE_Thread_Manager * = 0);
  // Initialize the DLL strategy based upon the service's DLL
  // information contained in the <svc_dll_info> string.

  int open (const char svc_dll_info[],
	    ACE_Service_Config *,
	    ACE_Thread_Manager * = 0);
  // Initialize the DLL strategy based upon the service's DLL
  // information contained in the <svc_dll_info> string.

  // = Factory method.
  virtual int make_svc_handler (SVC_HANDLER *&);
  // Create a SVC_HANDLER by dynamically linking it from a DLL.
  // Returns -1 on failure, else 0.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  typedef ACE_Creation_Strategy<SVC_HANDLER> inherited;

  char shared_library_[MAXPATHLEN];
  // Name of the shared library to dynamically link.

  char factory_function_[MAXPATHLEN];
  // Name of the factory function in the shared library to use to
  // obtain a pointer to the new SVC_HANDLER.

  char svc_name[MAXNAMELEN];
  // Name of the service.

  ACE_Service_Config *svc_config_;
  // Pointer to the Service_Configurator. 
};

template <class SVC_HANDLER>
class ACE_Concurrency_Strategy
  // = TITLE
  //     Defines the interface for specifying a concurrency strategy
  //     for a SVC_HANDLER.
  //
  // = DESCRIPTION
  //     Default behavior is to activate the SVC_HANDLER by calling
  //     its open() method (which allows the SVC_HANDLER to define its
  //     own concurrency strategy).  However, subclasses can override
  //     this default strategy to do more sophisticated concurrency
  //     activations (such as creating the SVC_HANDLER as an active
  //     object via multi-threading or multi-processing).
{
public:
  // = Factory method.
  virtual int activate_svc_handler (SVC_HANDLER *svc_handler,
				    void *arg = 0);
  // Activate the <svc_handler> with an appropriate concurrency
  // strategy.  The default behavior of this method is to activate the
  // SVC_HANDLER by calling its open() method (which allows the
  // SVC_HANDLER to define its own concurrency strategy).

  virtual ~ACE_Concurrency_Strategy (void);

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.
};

template <class SVC_HANDLER>
class ACE_Reactive_Strategy : public ACE_Concurrency_Strategy <SVC_HANDLER>
  // = TITLE
  //     Defines the interface for specifying a Reactive concurrency
  //     strategy for a SVC_HANDLER.
  //
  // = DESCRIPTION
  //     This class provides a strategy that registers the
  //     <SVC_HANDLER> with a <Reactor>.
{
public:
  // = Intialization and termination methods.
  ACE_Reactive_Strategy (void);
  // "Do-nothing constructor"

  ACE_Reactive_Strategy (ACE_Reactor *reactor,
			 ACE_Reactor_Mask = ACE_Event_Handler::READ_MASK);
  // Initialize the strategy.

  virtual int open (ACE_Reactor *reactor,
		    ACE_Reactor_Mask = ACE_Event_Handler::READ_MASK);
  // Initialize the strategy.

  virtual ~ACE_Reactive_Strategy (void);
  // Destructor.

  // = Factory method.
  virtual int activate_svc_handler (SVC_HANDLER *svc_handler,
				    void *arg = 0);
  // Activate the <svc_handler> by registering it with the <Reactor>
  // and then calling it's <open> hook.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  typedef ACE_Concurrency_Strategy<SVC_HANDLER> inherited;

  ACE_Reactor *reactor_;
  // Pointer to the Reactor we'll use to register the <SVC_HANDLER>.
  
  ACE_Reactor_Mask mask_;
  // The mask that we pass to the <Reactor> when we register the
  // <SVC_HANDLER>.
};

template <class SVC_HANDLER>
class ACE_Thread_Strategy : public ACE_Concurrency_Strategy<SVC_HANDLER>
  // = TITLE
  //     Defines the interface for specifying a concurrency strategy
  //     for a <SVC_HANDLER> based on multithreading.
  //
  // = DESCRIPTION
  //     This class provides a strategy that manages the creation of
  //     threads to handle requests from clients concurrently.  It
  //     behaves as a "thread factory", spawning threads "on-demand"
  //     to run the service specified by a user-supplied
  //     <SVC_HANDLER>.
{
public:
  // = Intialization and termination methods.
  ACE_Thread_Strategy (void);
  // "Do-nothing constructor"

  ACE_Thread_Strategy (ACE_Thread_Manager *tm,
		       long thr_flags,
		       size_t n_threads = 1);
  // Initialize the strategy.

  virtual int open (ACE_Thread_Manager *tm,
		    long thr_flags,
		    size_t n_threads = 1);
  // Initialize the strategy.
  
  virtual ~ACE_Thread_Strategy (void);

  // = Factory method.
  virtual int activate_svc_handler (SVC_HANDLER *svc_handler,
				    void *arg = 0);
  // Activate the <svc_handler> with an appropriate concurrency
  // strategy.  This method activates the SVC_HANDLER by first calling
  // its open() method and then calling its activate() method to turn
  // it into an active object.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  typedef ACE_Concurrency_Strategy<SVC_HANDLER> inherited;

  ACE_Thread_Manager *thr_mgr_;
  // Thread manager for this class (must be provided).

  long thr_flags_;
  // Flags to pass into the SVC_HANDLER::activate() method.

  size_t n_threads_;
  // Number of threads to spawn.
};

template <class SVC_HANDLER>
class ACE_Process_Strategy : public ACE_Concurrency_Strategy<SVC_HANDLER>
  // = TITLE
  //     Defines the interface for specifying a concurrency strategy
  //     for a <SVC_HANDLER> based on multiprocessing.
  //
  // = DESCRIPTION
  //     This class provides a strategy that manages the creation of
  //     processes to handle requests from clients concurrently.  It
  //     behaves as a "process factory", forking threads "on-demand"
  //     to run the service specified by a user-supplied
  //     <SVC_HANDLER>.
{
public:
  // = Intialization and termination methods.

  ACE_Process_Strategy (size_t n_processes = 1,
			ACE_Event_Handler *acceptor = 0,
			ACE_Reactor * = 0);
  // Initialize the strategy.

  virtual int open (size_t n_processes = 1,
		    ACE_Event_Handler *acceptor = 0,
		    ACE_Reactor * = 0);
  // Initialize the strategy.
  
  virtual ~ACE_Process_Strategy (void);

  // = Factory method.
  virtual int activate_svc_handler (SVC_HANDLER *svc_handler,
				    void *arg = 0);
  // Activate the <svc_handler> with an appropriate concurrency
  // strategy.  This method activates the SVC_HANDLER by first forking
  // and then calling the open() method of the SVC_HANDLER in the
  // child.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  typedef ACE_Concurrency_Strategy<SVC_HANDLER> inherited;

  size_t n_processes_;
  // Number of processes to spawn.
  
  ACE_Event_Handler *acceptor_;
  // This is the <Acceptor> in the parent is listening on.  We need to
  // make sure that we remove it from the Reactor and close it down in
  // the child.

  ACE_Reactor *reactor_;
  // This is the <Reactor> the child is using in conjunction with the
  // <Acceptor>.  We need to remove the <Acceptor> from this <Reactor>
  // in the child.
};

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
class ACE_Accept_Strategy 
  // = TITLE
  //     Defines the interface for specifying a passive connection
  //     acceptance strategy for a SVC_HANDLER.
  //
  // = DESCRIPTION
  //     This class provides a strategy that manages passive
  //     connection acceptance of a client.
{
public:
  // = Initialization and termination methods.
  ACE_Accept_Strategy (void);
  // Default constructor.

  ACE_Accept_Strategy (const ACE_PEER_ACCEPTOR_ADDR &local_addr,
		       int restart = 0);
  // Initialize the <peer_acceptor_> with <local_addr>.

  virtual int open (const ACE_PEER_ACCEPTOR_ADDR &local_addr, 
		    int restart = 0);
  // Initialize the <peer_acceptor_> with <local_addr>.

  virtual ACE_HANDLE get_handle (void) const;
  // Return the underlying ACE_HANDLE of the <peer_acceptor_>.

  virtual ACE_PEER_ACCEPTOR &acceptor (void) const;
  // Return a reference to the <peer_acceptor_>.

  virtual ~ACE_Accept_Strategy (void);

  // = Factory method.
  virtual int accept_svc_handler (SVC_HANDLER *);
  // The default behavior delegates to the <accept> method of the
  // PEER_ACCEPTOR. 

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  ACE_PEER_ACCEPTOR acceptor_;     
  // Factory that establishes connections passively.
};

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1>
class ACE_Connect_Strategy 
  // = TITLE
  //     Defines the interface for specifying an active 
  //     connection establishment strategy for a SVC_HANDLER.
  //
  // = DESCRIPTION
  //     This class provides a strategy that manages active 
  //     connection establishment to a server.
{
public:
  // = Initialization and termination methods.
  ACE_Connect_Strategy (void);
  // Default constructor.

  virtual ACE_PEER_CONNECTOR &connector (void) const;
  // Return a reference to the <peer_connector_>.

  virtual ~ACE_Connect_Strategy (void);

  // = Factory method.
  virtual int connect_svc_handler (SVC_HANDLER *&sh,
				   const ACE_PEER_CONNECTOR_ADDR &remote_addr,
				   ACE_Time_Value *timeout,
				   const ACE_PEER_CONNECTOR_ADDR &local_addr,
				   int reuse_addr,
				   int flags,
				   int perms);
  // The default behavior delegates to the <connect> method of the
  // <PEER_CONNECTOR::connect>.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  ACE_PEER_CONNECTOR connector_;     
  // Factory that establishes connections actively.
};

template <class SVC_HANDLER>
class ACE_Scheduling_Strategy
  // = TITLE
  //     Defines the interface for specifying how to suspend and
  //     resume a service .
  //
  // = DESCRIPTION
  //     This class provides a strategy that allows arbitrarily
  //     sophisticated service suspension and resumption.  The default
  //     behavior is to do nothing...
{
public:
  // = Initialization and termination methods.

  ACE_Scheduling_Strategy (SVC_HANDLER * = 0);
  // Constructor

  virtual ~ACE_Scheduling_Strategy (void);
  // Destructor

  // = Scheduling methods

  virtual int suspend (void);
  // Suspend hook.

  virtual int resume (void);
  // Resume hook.

  virtual void dump (void) const;
  // Dump the state of the object.

protected:
  SVC_HANDLER *scheduler_;
  // Points to the scheduler strategy object...

  int delete_scheduler_;
  // Keeps track of whether we need to delete this or not...
};

template <class SVC_HANDLER>
class ACE_Schedule_All_Reactive_Strategy : public ACE_Scheduling_Strategy<SVC_HANDLER>
  // = TITLE
  //     Defines the interface for specifying how to suspend and
  //     resume a single-threaded reactive service .
  //
  // = DESCRIPTION
  //     This class provides a strategy that suspends and resumes all
  //     the Event_Handlers in a Reactor in one fell swoop.
{
public:
  // = Initialization and termination methods.
  ACE_Schedule_All_Reactive_Strategy (SVC_HANDLER * = 0);
  // Constructor

  // = Scheduling methods

  virtual int suspend (void);
  // Suspend hook.

  virtual int resume (void);
  // Resume hook.

  virtual void dump (void) const;
  // Dump the state of the object.
};

template <class SVC_HANDLER>
class ACE_Schedule_All_Threaded_Strategy : public ACE_Scheduling_Strategy<SVC_HANDLER>
  // = TITLE
  //     Defines the interface for specifying how to suspend and
  //     resume a multithreaded service .
  //
  // = DESCRIPTION
  //     This class provides a strategy that suspends and resumes all
  //     the Event_Handlers controlled by a Thread_Manager in one fell swoop.
{
public:
  // = Initialization and termination methods.
  ACE_Schedule_All_Threaded_Strategy (SVC_HANDLER * = 0);
  // Constructor

  // = Scheduling methods

  virtual int suspend (void);
  // Suspend hook.

  virtual int resume (void);
  // Resume hook.

  virtual void dump (void) const;
  // Dump the state of the object.
};

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Strategies_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Strategies_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* ACE_STRATEGIES_T_H */
