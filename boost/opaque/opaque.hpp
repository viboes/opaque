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

#ifndef BOOST_OPAQUE__HPP
#define BOOST_OPAQUE__HPP

#include <boost/config.hpp>
#include <boost/operators.hpp>

namespace boost {
    template <typename Final, typename T, bool Convertible=true>
    class opaque_type;


    //~ *  totally_ordered<OT>
    //~ * integer_arithmetic<OT>
    //~ * bitwise<OT>
    //~ * unit_steppable<OT>

    //~ * totally_ordered<UT, OT>
    //~ * integer_arithmetic<UT, OT>
    //~ * bitwise<UT, OT>

    template <typename Final, typename T>
    class public_opaque_type
        : boost::totally_ordered< Final
        , boost::integer_arithmetic< Final
        , boost::bitwise< Final
        , boost::unit_steppable< Final
        , boost::totally_ordered< T, Final  // public specific conversions
        , boost::integer_arithmetic< T, Final // public specific conversions
        , boost::bitwise< T, Final // public specific conversions
        > > > > > > >
    {
    protected:
        T val_;
        typedef public_opaque_type opaque_type;
    public:
        typedef T underlying_type;
        //~ Can instances of UT be explicitly converted to instances of OT?
        //~ Proposed answer: yes.
        //~ Can instances of UT be implicitly converted to instances of OT?
        //~ Proposed answer: no.

        explicit public_opaque_type(const T v)
            : val_(v)
        {};
        public_opaque_type()
        {};
        public_opaque_type(const opaque_type & rhs)
            : val_(rhs.val_)
        {}
        public_opaque_type & operator=(const opaque_type & rhs) {
            val_ = rhs.val_; return *this;
        }
        public_opaque_type & operator=(const T rhs) {
            val_ = rhs; return *this;
        }

        T const& underlying() const {
            return val_;
        }
        T& underlying() {
            return val_;
        }

        // public specific conversions
        operator const T & () const {
            return val_;
        }
        operator T & () {
            return val_;
        }
#if 0
        bool operator==(const opaque_type & rhs) const {
            return val_ == rhs.val_;
        }
#endif
        bool operator<(const Final & rhs) const {
            return val_ < rhs.val_;
        }
        Final& operator+=(const Final & rhs) {
            val_ += rhs.val_;
            return static_cast<Final&>(*this);
        }
        Final& operator-=(const Final & rhs) {
            val_ -= rhs.val_;
            return static_cast<Final&>(*this);
        }
        Final& operator*=(const Final & rhs) {
            val_ *= rhs.val_;
            return static_cast<Final&>(*this);
        }
        Final& operator/=(const Final & rhs) {
            val_ /= rhs.val_;
            return static_cast<Final&>(*this);
        }
        Final& operator%=(const Final & rhs) {
            val_ %= rhs.val_;
            return static_cast<Final&>(*this);
        }
    };

    template <typename Final, typename T>
    class private_opaque_type
        : boost::totally_ordered< Final
        , boost::integer_arithmetic< Final
        , boost::bitwise< Final
        , boost::unit_steppable< Final
        > > > >
    {
        T val_;
        typedef private_opaque_type opaque_type;
    public:
        typedef T underlying_type;
        //~ Can instances of UT be explicitly converted to instances of OT?
        //~ Proposed answer: yes.
        //~ Can instances of UT be implicitly converted to instances of OT?
        //~ Proposed answer: no.

        explicit private_opaque_type(const T v)
            : val_(v)
        {};
        private_opaque_type()
        {};
        private_opaque_type(const opaque_type & rhs)
            : val_(rhs.val_)
        {}
        private_opaque_type & operator=(const opaque_type & rhs) {
            val_ = rhs.val_; return *this;
        }

        T underlying() const {
            return val_;
        }
        T& underlying() {
            return val_;
        }
        
        //~ // public specific conversions
        //~ operator const T & () const {
            //~ return val_;
        //~ }
        //~ operator T & () {
            //~ return val_;
        //~ }
        bool operator==(const Final & rhs) const {
            return val_ == rhs.val_;
        }
        bool operator<(const Final & rhs) const {
            return val_ < rhs.val_;
        }
        Final& operator+=(const Final & rhs) {
            val_ += rhs.val_;
            return static_cast<Final&>(*this);
        }
        Final& operator-=(const Final & rhs) {
            val_ -= rhs.val_;
            return static_cast<Final&>(*this);
        }
        Final& operator*=(const Final & rhs) {
            val_ *= rhs.val_;
            return static_cast<Final&>(*this);
        }
        Final& operator/=(const Final & rhs) {
            val_ /= rhs.val_;
            return static_cast<Final&>(*this);
        }
        Final& operator%=(const Final & rhs) {
            val_ %= rhs.val_;
            return static_cast<Final&>(*this);
        }
    };

    template <typename T, typename U>
    T opaque_static_cast(U v)    {
        return static_castT<T>(v);
    }
    
    template <typename T, typename UT, typename OT>
    T opaque_static_cast<T, private_opaque_type<OT,UT> >(
        private_opaque_type<OT,UT> const&ot)    {
        return static_cast<T>(ot.underlying());
    }
    template <typename T, typename UT, typename OT>
    private_opaque_type<OT,UT> opaque_static_cast<private_opaque_type<OT,UT>,T>(
        T t)    {
        return private_opaque_type<OT,UT>(static_cast<UT>(t));
    }
    
    template <typename T, typename UT, typename OT>
    T opaque_static_cast<UT,public_opaque_type<OT,UT>>(private_opaque_type<OT,UT> const&ot)    {
        return static_cast<T>(ot.underlying());
    }
    
    template <typename UT, typename OT>
    UT opaque_static_cast<UT,private_opaque_type<OT,UT>>(private_opaque_type<OT,UT> const&ot)    {
        return ot.underlying();
    }
    
    template <typename X, typename Y>
    OT opaque_dynamic_cast(Y y)    {
        return dynamic_cast<X>(y);
    }
    template <typename X, typename UT, typename OT>
    UT opaque_dynamic_cast<X,private_opaque_type<OT,UT> >(private_opaque_type<OT,UT> *ot)    {
        return dynamic_cast<X>(&ot->underlying());
    }
    
}

#define BOOST_OPAQUE_PUBLIC_FORWARD_CONSTRUCTORS(OT, UT) \
    OT(){}\
    template <typename T> explicit OT(T v) : boost::public_opaque_type<OT, UT>(v) {}

#define BOOST_OPAQUE_PUBLIC_OPERATIONS(OT, UT) \
    BOOST_OPAQUE_FORWARD_CONSTRUCTORS(OT,OT);\
    bool operator<(const OT & rhs) const {\
        return val_ < rhs.val_;\
    }\

    //~ OT& operator+=(const OT & rhs) {
        //~ val_ += rhs.val_;
        //~ return *this;
    //~ }

#define BOOST_OPAQUE_PRIVATE_FORWARD_CONSTRUCTORS(OT, UT) \
    OT(){}\
    template <typename T> explicit OT(T v) : boost::private_opaque_type<OT, UT>(v) {}

#define BOOST_OPAQUE_PRIVATE_OPERATIONS(OT, UT) \
    BOOST_OPAQUE_PRIVATE_FORWARD_CONSTRUCTORS(OT, UT)

#define BOOST_OPAQUE_PUBLIC_TYPEDEF(UT, OT) \
struct OT: boost::public_opaque_type<OT, UT> \
{\
    BOOST_OPAQUE_PUBLIC_OPERATIONS(OT,UT);\
}


#define BOOST_OPAQUE_PRIVATE_TYPEDEF(UT, OT) \
struct OT: boost::private_opaque_type<OT, UT> \
{\
    BOOST_OPAQUE_PRIVATE_OPERATIONS(OT,UT);\
}

#endif
