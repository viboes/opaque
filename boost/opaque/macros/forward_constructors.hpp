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
 * Defines helper macro @c BOOST_OPAQUE_FORWARD_CONSTRUCTORS.
 */

#ifndef BOOST_OPAQUE_MACROS_FORWARD_CONSTRUCTORS_HPP
#define BOOST_OPAQUE_MACROS_FORWARD_CONSTRUCTORS_HPP

/** forward the constructors from the new class @c OT to the base class @ BASE

 @Note This macro can be used only inside the public part of a class.

 @Params
 @Param{OT, the class been defined}
 @Param{BASE, the base class}

 @Result
 @code
    OT(){}
    template <typename W>
    explicit OT(W w)
        : BASE(w)
    {}
    OT(OT const& r)
        : BASE(r.val_)
    {}
 @endcode
 */
#define BOOST_OPAQUE_FORWARD_CONSTRUCTORS(OT,BASE) \
    OT(){} \
    template <typename W> \
    explicit OT(W w) \
        : BASE(w) \
    {}\
    OT(OT const& r) \
        : BASE(r.val_) \
    {}

#endif

