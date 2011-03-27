//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Vicente J. Botet Escriba 2010-2011.
// Distributed under the Boost
// Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or
// copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/opaque for documentation.
//
//////////////////////////////////////////////////////////////////////////////

/**
 * @file
 * Defines helper macro @c BOOST_OPAQUE_INHERIT_FROM_UNDERLYING.
 */

#ifndef BOOST_OPAQUE_MACROS_INHERIT_FROM_UNDERLYING_SPEC_HPP
#define BOOST_OPAQUE_MACROS_INHERIT_FROM_UNDERLYING_SPEC_HPP

#include <boost/opaque/meta_mixin/inherited_from_underlying.hpp>

/**
 Specialize inherited_from_underlying for the type @ OT just inheriting the ones from its underlying type.

 @Note This macro can be used only outside a namespace.

 @Params
 @Param{OT, the opaque type}

 @Result
 @code
 namespace boost {
   namespace opaque {
    template <typename Bool>
    struct inherited_from_underlying<OT,Bool>
      : inherited_from_underlying<typename OT::underlying_type,Bool> { };
   }
 }
 @endcode
 */
#define BOOST_OPAQUE_INHERIT_FROM_UNDERLYING(OT) \
namespace boost {\
namespace opaque {\
  template <typename Bool>\
  struct inherited_from_underlying<OT,Bool>\
    : inherited_from_underlying<typename OT::underlying_type,Bool> { };\
} \
}

#endif

