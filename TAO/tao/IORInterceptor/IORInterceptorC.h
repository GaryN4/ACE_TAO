// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:151

#ifndef _TAO_IDL_ORIG_IORINTERCEPTORC_H_
#define _TAO_IDL_ORIG_IORINTERCEPTORC_H_

#include "ace/pre.h"
#include "tao/PortableInterceptorC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/ObjectReferenceTemplateC.h"
#include "iorinterceptor_export.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_IORInterceptor_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_IORInterceptor_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:48

TAO_NAMESPACE  PortableInterceptor
{
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:52

#if !defined (_PORTABLEINTERCEPTOR_IORINFO___PTR_CH_)
#define _PORTABLEINTERCEPTOR_IORINFO___PTR_CH_
  
  class IORInfo;
  typedef IORInfo *IORInfo_ptr;

#endif /* end #if !defined */

#if !defined (_PORTABLEINTERCEPTOR_IORINFO___VAR_CH_)
#define _PORTABLEINTERCEPTOR_IORINFO___VAR_CH_
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:566
  
  class TAO_IORInterceptor_Export IORInfo_var : private TAO_Base_var
  {
  public:
    IORInfo_var (void); // default constructor
    IORInfo_var (IORInfo_ptr p) : ptr_ (p) {} 
    IORInfo_var (const IORInfo_var &); // copy constructor
    ~IORInfo_var (void); // destructor
    
    IORInfo_var &operator= (IORInfo_ptr);
    IORInfo_var &operator= (const IORInfo_var &);
    IORInfo_ptr operator-> (void) const;
    
    operator const IORInfo_ptr &() const;
    operator IORInfo_ptr &();
    // in, inout, out, _retn 
    IORInfo_ptr in (void) const;
    IORInfo_ptr &inout (void);
    IORInfo_ptr &out (void);
    IORInfo_ptr _retn (void);
    IORInfo_ptr ptr (void) const;
    
    // Hooks used by template sequence and object manager classes
    // for non-defined forward declared interfaces.
    static IORInfo_ptr tao_duplicate (IORInfo_ptr);
    static void tao_release (IORInfo_ptr);
    static IORInfo_ptr tao_nil (void);
    static IORInfo_ptr tao_narrow (
        CORBA::Object *
        ACE_ENV_ARG_DECL
      );
    static CORBA::Object * tao_upcast (void *);
  
  private:
    IORInfo_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    IORInfo_var (const TAO_Base_var & rhs);
    IORInfo_var & operator= (const TAO_Base_var & rhs);
  };

#endif /* end #if !defined */

#if !defined (_PORTABLEINTERCEPTOR_IORINFO___OUT_CH_)
#define _PORTABLEINTERCEPTOR_IORINFO___OUT_CH_
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:947

  class TAO_IORInterceptor_Export IORInfo_out
  {
  public:
    IORInfo_out (IORInfo_ptr &);
    IORInfo_out (IORInfo_var &);
    IORInfo_out (const IORInfo_out &);
    IORInfo_out &operator= (const IORInfo_out &);
    IORInfo_out &operator= (const IORInfo_var &);
    IORInfo_out &operator= (IORInfo_ptr);
    operator IORInfo_ptr &();
    IORInfo_ptr &ptr (void);
    IORInfo_ptr operator-> (void);
  
  private:
    IORInfo_ptr &ptr_;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:110

#if !defined (_PORTABLEINTERCEPTOR_IORINFO_CH_)
#define _PORTABLEINTERCEPTOR_IORINFO_CH_
  
  class TAO_IORInterceptor_Export IORInfo
    : public virtual CORBA::Object
  {
  public:
    typedef IORInfo_ptr _ptr_type;
    typedef IORInfo_var _var_type;
    static int _tao_class_id;
    
    // The static operations.
    static IORInfo_ptr _duplicate (IORInfo_ptr obj);
    
    static IORInfo_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static IORInfo_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static IORInfo_ptr _nil (void)
      {
        return (IORInfo_ptr)0;
      }
    
    
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Policy_ptr get_effective_policy (
        CORBA::PolicyType type
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void add_ior_component (
        const IOP::TaggedComponent & a_component
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void add_ior_component_to_profile (
        const IOP::TaggedComponent & a_component,
        IOP::ProfileId profile_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual PortableInterceptor::AdapterManagerId manager_id (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual PortableInterceptor::AdapterState state (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::PortableInterceptor::ObjectReferenceTemplate * adapter_template (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::PortableInterceptor::ObjectReferenceFactory * current_factory (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void current_factory (
        PortableInterceptor::ObjectReferenceFactory * current_factory
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:267
    
    virtual void *_tao_QueryInterface (ptr_arith_t type);
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    IORInfo (void);
    virtual ~IORInfo (void);
  
  private:
    IORInfo (const IORInfo &);
    void operator= (const IORInfo &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:52

#if !defined (_PORTABLEINTERCEPTOR_IORINTERCEPTOR___PTR_CH_)
#define _PORTABLEINTERCEPTOR_IORINTERCEPTOR___PTR_CH_
  
  class IORInterceptor;
  typedef IORInterceptor *IORInterceptor_ptr;

#endif /* end #if !defined */

#if !defined (_PORTABLEINTERCEPTOR_IORINTERCEPTOR___VAR_CH_)
#define _PORTABLEINTERCEPTOR_IORINTERCEPTOR___VAR_CH_
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:566
  
  class TAO_IORInterceptor_Export IORInterceptor_var : private TAO_Base_var
  {
  public:
    IORInterceptor_var (void); // default constructor
    IORInterceptor_var (IORInterceptor_ptr p) : ptr_ (p) {} 
    IORInterceptor_var (const IORInterceptor_var &); // copy constructor
    ~IORInterceptor_var (void); // destructor
    
    IORInterceptor_var &operator= (IORInterceptor_ptr);
    IORInterceptor_var &operator= (const IORInterceptor_var &);
    IORInterceptor_ptr operator-> (void) const;
    
    operator const IORInterceptor_ptr &() const;
    operator IORInterceptor_ptr &();
    // in, inout, out, _retn 
    IORInterceptor_ptr in (void) const;
    IORInterceptor_ptr &inout (void);
    IORInterceptor_ptr &out (void);
    IORInterceptor_ptr _retn (void);
    IORInterceptor_ptr ptr (void) const;
    
    // Hooks used by template sequence and object manager classes
    // for non-defined forward declared interfaces.
    static IORInterceptor_ptr tao_duplicate (IORInterceptor_ptr);
    static void tao_release (IORInterceptor_ptr);
    static IORInterceptor_ptr tao_nil (void);
    static IORInterceptor_ptr tao_narrow (
        CORBA::Object *
        ACE_ENV_ARG_DECL
      );
    static CORBA::Object * tao_upcast (void *);
  
  private:
    IORInterceptor_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    IORInterceptor_var (const TAO_Base_var & rhs);
    IORInterceptor_var & operator= (const TAO_Base_var & rhs);
  };

#endif /* end #if !defined */

#if !defined (_PORTABLEINTERCEPTOR_IORINTERCEPTOR___OUT_CH_)
#define _PORTABLEINTERCEPTOR_IORINTERCEPTOR___OUT_CH_
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:947
  
  class TAO_IORInterceptor_Export IORInterceptor_out
  {
  public:
    IORInterceptor_out (IORInterceptor_ptr &);
    IORInterceptor_out (IORInterceptor_var &);
    IORInterceptor_out (const IORInterceptor_out &);
    IORInterceptor_out &operator= (const IORInterceptor_out &);
    IORInterceptor_out &operator= (const IORInterceptor_var &);
    IORInterceptor_out &operator= (IORInterceptor_ptr);
    operator IORInterceptor_ptr &();
    IORInterceptor_ptr &ptr (void);
    IORInterceptor_ptr operator-> (void);
  
  private:
    IORInterceptor_ptr &ptr_;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:110

#if !defined (_PORTABLEINTERCEPTOR_IORINTERCEPTOR_CH_)
#define _PORTABLEINTERCEPTOR_IORINTERCEPTOR_CH_
  
  class TAO_IORInterceptor_Export IORInterceptor
    : public virtual PortableInterceptor::Interceptor
  {
  public:
    typedef IORInterceptor_ptr _ptr_type;
    typedef IORInterceptor_var _var_type;
    static int _tao_class_id;
    
    // The static operations.
    static IORInterceptor_ptr _duplicate (IORInterceptor_ptr obj);
    
    static IORInterceptor_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static IORInterceptor_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static IORInterceptor_ptr _nil (void)
      {
        return (IORInterceptor_ptr)0;
      }
    
    
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void establish_components (
        PortableInterceptor::IORInfo_ptr info
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void components_established (
        PortableInterceptor::IORInfo_ptr info
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void adapter_manager_state_changed (
        PortableInterceptor::AdapterManagerId id,
        PortableInterceptor::AdapterState state
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void adapter_state_changed (
        const PortableInterceptor::ObjectReferenceTemplateSeq & templates,
        PortableInterceptor::AdapterState state
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:267
    
    virtual void *_tao_QueryInterface (ptr_arith_t type);
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    IORInterceptor (void);
    virtual ~IORInterceptor (void);
  
  private:
    IORInterceptor (const IORInterceptor &);
    void operator= (const IORInterceptor &);
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:67

}
TAO_NAMESPACE_CLOSE // module PortableInterceptor

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:1018

#if defined (__ACE_INLINE__)
#include "IORInterceptorC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include "ace/post.h"
#endif /* ifndef */

