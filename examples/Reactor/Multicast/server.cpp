// server.C (written by Tim Harrison)
// $Id$

// 
// listens to multicast address.  after first message received, will
// listen for 5 more seconds.  prints Mbits/sec received from client.

#include "ace/SOCK_Dgram.h"
#include "ace/INET_Addr.h"
#include "ace/Log_Msg.h"
#include "ace/SOCK_Dgram_Mcast.h"
#include "ace/Reactor.h"
#include "Log_Wrapper.h"

#if defined (ACE_HAS_IP_MULTICAST)
class Server_Events : public ACE_Event_Handler
{
public:
  Server_Events (u_short port, 
		 const char *mcast_addr, 
		 long time_interval = 0);
  ~Server_Events (void);

  virtual int handle_input (ACE_HANDLE fd);
  virtual ACE_HANDLE get_handle (void) const;

  ACE_Time_Value *wait_time (void);

private:
  char *message_;
  Log_Wrapper::ACE_Log_Record *log_record_;
  char buf_[4*BUFSIZ];

  int interval_;
  // time interval to log messages

  ACE_Time_Value *how_long_;
  ACE_Reactor    *reactor_;
  ACE_SOCK_Dgram_Mcast mcast_dgram_;
  ACE_INET_Addr  remote_addr_;
  ACE_INET_Addr  mcast_addr_;

  // = statistics on messages received
  double total_bytes_received_;
  int total_messages_received_;
  int last_sequence_number_;
};

ACE_HANDLE
Server_Events::get_handle (void) const
{
  return this->mcast_dgram_.get_handle ();
}

ACE_Time_Value *
Server_Events::wait_time (void)
{
  return this->how_long_;
}

Server_Events::Server_Events (u_short port, 
			      const char *mcast_addr,
			      long time_interval)
  : total_bytes_received_ (0),
    interval_ (time_interval),
    mcast_addr_ (port, mcast_addr)
{
  // use ACE_SOCK_Dgram_Mcast factory to subscribe to multicast group.

  if (this->mcast_dgram_.subscribe (this->mcast_addr_) == -1)
    perror("can't subscribe to multicast group"), exit(1);

  // Point to NULL so that we block in the beginning.
  this->how_long_ = 0;

  this->log_record_ = (Log_Wrapper::ACE_Log_Record *) &buf_;
  this->message_ = &buf_[sizeof (Log_Wrapper::ACE_Log_Record)];
}

// A destructor that emacs refuses to color blue ;-)

Server_Events::~Server_Events (void)
{
  this->mcast_dgram_.unsubscribe ();

  ACE_DEBUG ((LM_DEBUG, "total bytes received = %d after %d second\n",
	      this->total_bytes_received_, this->interval_));

  ACE_DEBUG ((LM_DEBUG, "Mbits/sec = %.2f\n",
	      (float) (total_bytes_received_ * 8 / (float) (1024*1024*interval_))));

  ACE_DEBUG ((LM_DEBUG, 
	      "last sequence number = %d\ntotal messages received = %d\ndiff = %d\n",
	      this->last_sequence_number_,
	      this->total_messages_received_,
	      this->last_sequence_number_ - total_messages_received_));
}

int
Server_Events::handle_input (ACE_HANDLE)
{
  // after the first message, point this to a timer
  // that way, the next time reactor::handle_events is called,
  // a nonzero time value will be passed in.
  if (this->how_long_ == 0)
    this->how_long_ = new ACE_Time_Value (this->interval_);

  // receive message from multicast group
  int retcode = this->mcast_dgram_.recv (this->buf_, 
					 sizeof this->buf_, 
					 this->remote_addr_);
  if (retcode != -1)
    {
      total_messages_received_++;
      total_bytes_received_ += retcode;
      last_sequence_number_ = log_record_->sequence_number;
      ACE_DEBUG ((LM_DEBUG, "sequence number = %d\n", 
		  log_record_->sequence_number));
      return 0;
    }
  else
    return -1;
}

static const char MCAST_ADDR[] = ACE_DEFAULT_MULTICAST_ADDR;
static const int UDP_PORT = ACE_DEFAULT_MULTICAST_PORT;

int 
main(int, char *[])
{
  int duration = 5;

  // Instantiate a server which will receive messages for 5 seconds.
  Server_Events server_events (UDP_PORT, MCAST_ADDR, duration);

  // Instance of the ACE_Reactor.
  ACE_Reactor reactor;

  if (reactor.register_handler (&server_events,
				ACE_Event_Handler::READ_MASK) == -1)
    ACE_ERROR ((LM_ERROR, "%p\n%a", "register_handler", 1));

  for (;;)
    reactor.handle_events (server_events.wait_time ());

  /* NOTREACHED */
  return 0;
}
#else
int 
main (int, char *argv[])
{
  ACE_ERROR_RETURN ((LM_ERROR, 
		     "error: %s must be run on a platform that support IP multicast\n",
		     argv[0]), -1);
}
#endif /* ACE_HAS_IP_MULTICAST */
