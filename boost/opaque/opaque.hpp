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
#include <boost/mpl/if.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/single_view.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/empty_sequence.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_class.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/type_traits/is_fundamental.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/mpl/bool.hpp>
#define BOOST_OPAQUE_STATIC_ASSERT(CND, MSG, TYPES)                                 \
    BOOST_MPL_ASSERT_MSG(boost::mpl::bool_< (CND) >::type::value, MSG, TYPES)

namespace boost {

    class base_public_opaque_type {};
    class base_private_opaque_type {};

    template <typename UT, typename Base>
    struct basic_conv : Base {
        typedef Base base_type;
        basic_conv() {}
        basic_conv(UT val) : base_type(val) {}
        template <typename W>
        explicit basic_conv(W v)
            : base_type(v)
        {}

        // public specific conversions
        operator UT () const {
            return this->val_;
        }
    };


    template <typename T, typename UT, bool B, typename Base>
    struct conv_public_opaque_type2;

    template <typename T, typename UT, typename Base>
    struct conv_public_opaque_type2<T, UT,true,Base> :  public UT::template conv<T, Base>::type
    {
        typedef typename UT::template conv<T, Base>::type base_type;
        conv_public_opaque_type2() {}
        conv_public_opaque_type2(T val) : base_type(val) {}
        template <typename W>
        explicit conv_public_opaque_type2(W v)
            : base_type(v)
        {}

    };
    template <typename T, typename UT, typename Base>
    struct conv_public_opaque_type2<T, UT, false, Base> :  public basic_conv<T, Base>
    {
        typedef basic_conv<T, Base> base_type;
        conv_public_opaque_type2() {}
        conv_public_opaque_type2(T val) : base_type(val) {}
        template <typename W>
        explicit conv_public_opaque_type2(W v)
            : base_type(v)
        {}

    };

    template <typename T, typename UT, bool B, typename Base>
    struct conv_public_opaque_type;

    template <typename T, typename UT, typename Base>
    struct conv_public_opaque_type<T, UT,true,Base> :  public UT::template conv<T, Base>::type
    {
        typedef typename UT::template conv<T, Base>::type base_type;
        conv_public_opaque_type() {}
        conv_public_opaque_type(T val) : base_type(val) {}
        template <typename W>
        explicit conv_public_opaque_type(W v)
            : base_type(v)
        {}

        // public specific conversions
        operator UT () const {
            return this->val_.operator UT();
        }
    };
    template <typename T, typename UT, typename Base>
    struct conv_public_opaque_type<T, UT, false, Base> :  public basic_conv<T, Base>
    {
        typedef basic_conv<T, Base> base_type;
        conv_public_opaque_type() {}
        conv_public_opaque_type(T val) : base_type(val) {}
        template <typename W>
        explicit conv_public_opaque_type(W v)
            : base_type(v)
        {}

        // public specific conversions
        operator UT () const {
            return this->val_.operator UT();
        }
    };


    template <typename T, bool B>
    struct get_substituables;

    template <typename T>
    struct get_substituables<T,true> {
        typedef typename mpl::push_front<typename T::substituables, T>::type type;
    };

    template <typename T>
    struct get_substituables<T,false> {
        typedef mpl::vector<T> type;
    };

    template <typename Final, typename T, typename Base>
    class opaque_type
        : public boost::totally_ordered< Final
            , boost::integer_arithmetic< Final
              , boost::bitwise< Final
                , boost::unit_steppable< Final
                  , Base
                >
              >
            >
          >

    {
    public:
        typedef T underlying_type;
        typedef typename get_substituables<T,
                mpl::and_<is_class<T>, is_base_of<base_public_opaque_type,T> >::value
                 >::type substituables;

        template <typename W>
        //~ explicit opaque_type(W v, enable_if<mpl::contains<substituables,W> >*dummy =0)
        explicit opaque_type(W v)
            : val_(v)
        {
        }

        opaque_type()
        {}

        opaque_type(const opaque_type & rhs)
            : val_(rhs.val_)
        {}
        explicit opaque_type(T v)
            : val_(v)
        {}
    protected:
        T val_;
        opaque_type & operator=(const opaque_type & rhs) {
            val_ = rhs.val_; return *this;
        }

    public:
        T const& underlying() const {
            return val_;
        }
        T& underlying() {
            return val_;
        }

        bool operator==(const opaque_type & rhs) const {
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




    template <typename Final, typename T>
    class public_opaque_type
        : public
            conv_public_opaque_type2<T, T, mpl::and_<is_class<T>, is_base_of<base_public_opaque_type,T> >::value,
                opaque_type< Final, T, base_public_opaque_type>
            >
    {
        typedef
            conv_public_opaque_type2<T, T, mpl::and_<is_class<T>, is_base_of<base_public_opaque_type,T> >::value,
                opaque_type< Final, T, base_public_opaque_type>
            > base_type;

    protected:
        typedef public_opaque_type opaque_type_t;
    public:
        typedef T underlying_type;
        typedef typename opaque_type< Final, T, base_public_opaque_type>::substituables substituables;
        template <typename U, typename B>
        struct conv {
            typedef
                conv_public_opaque_type<U, T,
                    mpl::and_<is_class<T>, is_base_of<base_public_opaque_type,T> >::value,
                    B> type;
        };
        //~ Can instances of UT be explicitly converted to instances of OT?
        //~ Proposed answer: yes.
        //~ Can instances of UT be implicitly converted to instances of OT?
        //~ Proposed answer: no.

        public_opaque_type() {}

        public_opaque_type(const opaque_type_t & rhs)
            : base_type(rhs.val_)
        {}
        public_opaque_type(const Final & rhs)
            : base_type(rhs.val_)
        {}

        explicit public_opaque_type(T v)
            : base_type(v)
        {}
        //~ template <typename W>
        //~ explicit public_opaque_type(const W v, enable_if<mpl::contains<substituables,W> >*dummy =0)
            //~ : base_type(v)
        //~ {}

        template <typename W>
        explicit public_opaque_type(W v)
            : base_type(v)
        {}

        public_opaque_type & operator=(const opaque_type_t & rhs) {
            this->val_ = rhs.val_; return *this;
        }

        // public specific conversions
        operator T() const {
            return this->val_;
        }
        operator T() {
            return this->val_;
        }

        //~ template <typename W>
        //~ operator const W & () const {
            //~ return W(this->val_);
        //~ }
        //~ template <typename W>
        //~ operator W & () {
            //~ return W(this->val_);
        //~ }

    };

    template <typename Final, typename T>
    class private_opaque_type
        : public opaque_type< Final, T, base_private_opaque_type >
    {
        typedef opaque_type< Final, T, base_private_opaque_type > base_type;
    protected:
        typedef private_opaque_type opaque_type_t;
    public:
        typedef T underlying_type;
        //~ Can instances of UT be explicitly converted to instances of OT?
        //~ Proposed answer: yes.
        //~ Can instances of UT be implicitly converted to instances of OT?
        //~ Proposed answer: no.

        private_opaque_type()
        {};
        private_opaque_type(const opaque_type_t & rhs)
            : base_type(rhs.val_)
        {}
        private_opaque_type(const Final & rhs)
            : base_type(rhs.val_)
        {}
        explicit private_opaque_type(T v)
            : base_type(v)
        {};
        template <typename W>
        explicit private_opaque_type(W v)
            : base_type(v)
        {}
        //~ private_opaque_type & operator=(const opaque_type_t & rhs) {
            //~ val_ = rhs.val_; return *this;
        //~ }


        //~ // public specific conversions
        //~ operator const T & () const {
            //~ return val_;
        //~ }
        //~ operator T & () {
            //~ return val_;
        //~ }
    };

    template <typename T, typename U>
    T opaque_static_cast(U v)
    {
        return static_cast<T>(v);
    }

    #if 0
    template <typename T, typename UT, typename OT>
    T opaque_static_cast<T, private_opaque_type<OT,UT> >(private_opaque_type<OT,UT> const&ot)
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

    //~ explicit OT(UT w) 
        //~ : boost::public_opaque_type<OT, UT>(w) 
    //~ {} 

#define BOOST_OPAQUE_PUBLIC_FORWARD_CONSTRUCTORS(UT, OT) \
    OT(){} \
    template <typename W> \
    explicit OT(W w) \
        : boost::public_opaque_type<OT, UT>(w) \
    {}\
    OT(OT const& r) \
        : boost::public_opaque_type<OT, UT>(r) \
    {}

#define BOOST_OPAQUE_PUBLIC_OPERATIONS(UT, OT) \
    BOOST_OPAQUE_PUBLIC_FORWARD_CONSTRUCTORS(UT,OT)\

#define BOOST_OPAQUE_PUBLIC_TYPEDEF(UT, OT) \
struct OT: boost::public_opaque_type<OT, UT> \
{\
    BOOST_OPAQUE_PUBLIC_OPERATIONS(UT,OT);\
}


    //~ template <typename T> explicit OT(T v) : boost::private_opaque_type<OT, UT>(v) {} 

#define BOOST_OPAQUE_PRIVATE_FORWARD_CONSTRUCTORS(UT, OT) \
    OT(){}\
    template <typename W> \
    explicit OT(W w) \
        : boost::private_opaque_type<OT, UT>(w) \
    {}\
    OT(OT const& r) \
        : boost::private_opaque_type<OT, UT>(r) \
    {}

#define BOOST_OPAQUE_PRIVATE_OPERATIONS(UT, OT) \
    BOOST_OPAQUE_PRIVATE_FORWARD_CONSTRUCTORS(UT, OT)



#define BOOST_OPAQUE_PRIVATE_TYPEDEF(UT, OT) \
struct OT: boost::private_opaque_type<OT, UT> \
{\
    BOOST_OPAQUE_PRIVATE_OPERATIONS(UT,OT);\
}

#endif
