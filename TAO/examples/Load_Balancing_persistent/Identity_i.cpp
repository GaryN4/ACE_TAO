/* -*- C++ -*- */
// $Id$
// ============================================================================
//
// = FILENAME
//   Identity_i.cpp
//
// = DESCRIPTION
//    Implements the interface in Identity.idl.
//
// = AUTHOR
//    Marina Spivak <marina@cs.wustl.edu>
//
// ============================================================================
#include "Identity_i.h"

Identity_i::Identity_i (const char *name,
                        PortableServer::POA_ptr poa)
  : name_ (name),
    poa_ (PortableServer::POA::_duplicate (poa))
{
}

Identity_i::~Identity_i (void)
{
}

void
Identity_i::get_name (CORBA::String_out name,
                      CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_UNUSED_ARG (ACE_TRY_ENV);
  name = this->name_.in ();
}

PortableServer::POA_ptr
Identity_i::_default_POA (CORBA::Environment &)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return PortableServer::POA::_duplicate (this->poa_);
}

