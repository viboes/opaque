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

#ifndef BOOST_OPAQUE_MACROS_HPP
#define BOOST_OPAQUE_MACROS_HPP

#include <boost/config.hpp>
#include <boost/opaque/private_opaque_type.hpp>
#include <boost/opaque/public_opaque_type.hpp>
#include <boost/opaque/private_opaque_class.hpp>
#include <boost/opaque/public_opaque_class.hpp>

#define BOOST_OPAQUE_PUBLIC_FORWARD_CONSTRUCTORS(UT, OT) \
    OT(){} \
    template <typename W> \
    explicit OT(W w) \
        : boost::public_opaque_class<OT, UT>(w) \
    {}\
    OT(OT const& r) \
        : boost::public_opaque_class<OT, UT>(r) \
    {}

#define BOOST_OPAQUE_PUBLIC_OPERATIONS(UT, OT) \
    BOOST_OPAQUE_PUBLIC_FORWARD_CONSTRUCTORS(UT,OT)\


#if 1
#define BOOST_OPAQUE_PUBLIC_TYPEDEF(UT, OT) \
struct OT: boost::public_opaque_class<OT, UT> \
{\
    BOOST_OPAQUE_PUBLIC_OPERATIONS(UT,OT);\
}
#else
#define BOOST_OPAQUE_PUBLIC_TYPEDEF(UT, OT) \
struct BOOST_JOIN(OT, _tag) {};\
typedef boost::public_opaque_type<UT, BOOST_JOIN(OT, _tag)> OT
#endif


    //~ template <typename T> explicit OT(T v) : boost::private_opaque_type<OT, UT>(v) {}

#define BOOST_OPAQUE_PRIVATE_FORWARD_CONSTRUCTORS(UT, OT) \
    OT(){}\
    template <typename W> \
    explicit OT(W w) \
        : boost::private_opaque_class<OT, UT>(w) \
    {}\
    OT(OT const& r) \
        : boost::private_opaque_class<OT, UT>(r) \
    {}

#define BOOST_OPAQUE_PRIVATE_OPERATIONS(UT, OT) \
    BOOST_OPAQUE_PRIVATE_FORWARD_CONSTRUCTORS(UT, OT)




#if 1
#define BOOST_OPAQUE_PRIVATE_TYPEDEF(UT, OT) \
struct OT: boost::private_opaque_class<OT, UT> \
{\
    BOOST_OPAQUE_PRIVATE_OPERATIONS(UT,OT);\
}
#else
#define BOOST_OPAQUE_PRIVATE_TYPEDEF(UT, OT) \
struct BOOST_JOIN(OT, _tag) {};\
typedef boost::private_opaque_type<UT, BOOST_JOIN(OT, _tag)> OT
#endif


#endif
