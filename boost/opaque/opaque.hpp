//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Vicente J. Botet Escriba 2010.
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
 * Includes all the opaque public headers.
 */

#ifndef BOOST_OPAQUE_OPAQUE_HPP
#define BOOST_OPAQUE_OPAQUE_HPP

#include <boost/opaque/new_type.hpp>
#include <boost/opaque/new_class.hpp>
#include <boost/opaque/private_opaque_type.hpp>
#include <boost/opaque/private_opaque_class.hpp>
#include <boost/opaque/public_opaque_type.hpp>
#include <boost/opaque/public_opaque_class.hpp>
#include <boost/opaque/boolean.hpp>
#include <boost/opaque/meta_mixin/operators.hpp>
#include <boost/opaque/meta_mixin/combined_operators.hpp>
#include <boost/opaque/macros.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/assert.hpp>

#if !defined(BOOST_OPAQUE_DOXYGEN_INVOKED)

#define BOOST_OPAQUE_STATIC_ASSERT(CND, MSG, TYPES)                                 \
    BOOST_MPL_ASSERT_MSG(boost::mpl::bool_< (CND) >::type::value, MSG, TYPES)

#endif

namespace boost {

    #if 0
    template <typename T, typename UT, typename OT>
    T opaque_static_cast(private_opaque_type<OT,UT> const&ot)
    {
        return static_cast<T>(ot.underlying());
    }
    template <typename T, typename UT, typename OT>
    private_opaque_type<OT,UT>
    opaque_static_cast<private_opaque_type<OT,UT>,T>(T t)
    {
        return private_opaque_type<OT,UT>(static_cast<UT>(t));
    }

    template <typename T, typename UT, typename OT>
    T opaque_static_cast<UT,public_opaque_type<OT,UT> >(private_opaque_type<OT,UT> const&ot)
    {
        return static_cast<T>(ot.underlying());
    }

    template <typename UT, typename OT>
    UT opaque_static_cast<UT,private_opaque_type<OT,UT> >(private_opaque_type<OT,UT> const&ot)
    {
        return ot.underlying();
    }

    template <typename X, typename Y>
    OT opaque_dynamic_cast(Y y)
    {
        return dynamic_cast<X>(y);
    }
    template <typename X, typename UT, typename OT>
    UT opaque_dynamic_cast<X,private_opaque_type<OT,UT> >(private_opaque_type<OT,UT> *ot)
    {
        return dynamic_cast<X>(&ot->underlying());
    }
    #endif
}


#endif
