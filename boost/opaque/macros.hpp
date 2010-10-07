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
        : boost::opaque::public_opaque_class<OT, UT>(w) \
    {}\
    OT(OT const& r) \
        : boost::opaque::public_opaque_class<OT, UT>(r) \
    {}

#define BOOST_OPAQUE_PUBLIC_OPERATIONS(UT, OT) \
    BOOST_OPAQUE_PUBLIC_FORWARD_CONSTRUCTORS(UT,OT)\


#if 0
#define BOOST_OPAQUE_PUBLIC_TYPEDEF(UT, OT) \
struct OT: boost::opaque::public_opaque_class<OT, UT> \
{\
    BOOST_OPAQUE_PUBLIC_OPERATIONS(UT,OT);\
}
#else
#define BOOST_OPAQUE_PUBLIC_TYPEDEF(UT, OT) \
struct BOOST_JOIN(OT, _tag) {};\
typedef boost::opaque::public_opaque_type<UT, BOOST_JOIN(OT, _tag)> OT
#endif

#define BOOST_OPAQUE_PUBLIC_CLASS(UT, NT1) \
struct NT1 : boost::opaque::public_opaque_class<NT1, UT> \
{ \
    typedef \
    boost::opaque::public_opaque_class<NT1, UT> \
    base_type; \
    \
    NT1(){} \
    explicit NT1(unsigned v) : base_type(v) {} \
    template <typename W>  \
    explicit NT1(W w)  \
        : base_type(w)  \
    {} \
    NT1(NT1 const& r) \
        : base_type(r.val_) \
    {} \
}

    //~ template <typename T> explicit OT(T v) : boost::private_opaque_type<OT, UT>(v) {}

#define BOOST_OPAQUE_PRIVATE_FORWARD_CONSTRUCTORS(UT, OT) \
    OT(){}\
    template <typename W> \
    explicit OT(W w) \
        : boost::opaque::private_opaque_class<OT, UT>(w) \
    {}\
    OT(OT const& r) \
        : boost::opaque::private_opaque_class<OT, UT>(r) \
    {}

#define BOOST_OPAQUE_PRIVATE_OPERATIONS(UT, OT) \
    BOOST_OPAQUE_PRIVATE_FORWARD_CONSTRUCTORS(UT, OT)




#if 0
#define BOOST_OPAQUE_PRIVATE_TYPEDEF(UT, OT) \
struct OT: boost::opaque::private_opaque_class<OT, UT> \
{\
    BOOST_OPAQUE_PRIVATE_OPERATIONS(UT,OT);\
}
#else
#define BOOST_OPAQUE_PRIVATE_TYPEDEF(UT, OT) \
struct BOOST_JOIN(OT, _tag) {};\
typedef boost::opaque::private_opaque_type<UT, BOOST_JOIN(OT, _tag)> OT
#endif


#endif
