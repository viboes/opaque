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

    class base_new_type {};
    class base_public_opaque_type {};
    class base_private_opaque_type {};

    template <typename Final, typename UT, typename Base>
    struct underlying_access : Base {
        typedef Base base_type;
        underlying_access() {}
        underlying_access(UT val) : base_type(val) {}
        template <typename W>
        explicit underlying_access(W v)
            : base_type(v)
        {}

        Final const& final() const {
            return static_cast<Final const&>(*this);
        }
        Final& final() {
            return static_cast<Final&>(*this);
        }
        UT const& underlying() const {
            return final().underlying();
        }
        UT& underlying() {
            return final().underlying();
        }
    };
        
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

namespace opaque {
    template <typename Final, typename UT, typename Base>
    struct less_than_comparable : Base {
        friend bool operator<(const Final& x, const Final& y)  { 
            return x.underlying() < y.underlying(); 
        }
    };    

    template <typename Final, typename UT, typename Base>
    struct equality_comparable : Base {
        friend bool operator==(const Final& x, const Final& y)  { 
            return x.underlying() == y.underlying(); 
        }
    };    

    template <typename Final, typename UT, typename Base>
    struct addable : Base {
        friend Final& operator+=(Final& x, const Final& y)  { 
            x.underlying() += y.underlying(); 
            return x;
        }
    };    
    
    template <typename Final, typename UT, typename Base>
    struct subtractable : Base {
        friend Final& operator-=(Final& x, const Final& y)  { 
            x.underlying() -= y.underlying(); 
            return x;
        }
    };    
    
    template <typename Final, typename UT, typename Base>
    struct multipliable : Base {
        friend Final& operator*=(Final& x, const Final& y)  { 
            x.underlying() *= y.underlying(); 
            return x;
        }
    };    
    
    template <typename Final, typename UT, typename Base>
    struct dividable : Base {
        friend Final& operator/=(Final& x, const Final& y)  { 
            x.underlying() /= y.underlying(); 
            return x;
        }
    };    
    
    template <typename Final, typename UT, typename Base>
    struct modable : Base {
        friend Final& operator%=(Final& x, const Final& y)  { 
            x.underlying() %= y.underlying(); 
            return x;
        }
    };    
    
}


    template <typename Final, typename T, typename Base=base_new_type>
    class new_type : public Base
    {
    public:
        typedef T underlying_type;

        template <typename W>
        explicit new_type(W v) : val_(v) {}
        new_type(){}
        new_type(const new_type & rhs) : val_(rhs.val_) {}
        explicit new_type(T v) : val_(v) {}
    protected:
        T val_;
        new_type & operator=(const new_type & rhs) {
            val_ = rhs.val_; return *this;
        }

    public:
        T const& underlying() const {
            return val_;
        }
        T& underlying() {
            return val_;
        }

    };


    template <typename T, typename Final, typename Base>
    struct inherited_from_undelying {
        //~ template <>
        struct type : 
            boost::totally_ordered< Final
            , boost::integer_arithmetic< Final
              , boost::bitwise< Final
                , boost::unit_steppable< Final
                  , opaque::less_than_comparable<Final, T 
                    , opaque::equality_comparable<Final, T 
                      , opaque::addable<Final, T 
                        , opaque::subtractable<Final, T 
                          , opaque::multipliable<Final, T 
                            , opaque::dividable<Final, T 
                              , opaque::modable<Final, T 
                                , underlying_access< Final, T, Base >
                              >
                            >
                          >
                        >
                      >
                    >
                  >
                >
              >
            >
          >
        {};  

    };
    
    template <typename Final, typename T, typename Base>
    class opaque_type : public new_type<Final, T, typename inherited_from_undelying<T, Final, Base>::type >
    {
    public:
        typedef
            new_type<Final, T, typename inherited_from_undelying<T, Final, Base>::type > base_type;
        //~ typedef T underlying_type;
        typedef typename get_substituables<T,
                mpl::and_<is_class<T>, is_base_of<base_public_opaque_type,T> >::value
                 >::type substituables;

        template <typename W>
        explicit opaque_type(W v)
            : base_type(v)
        {
        }

        opaque_type() {}
        opaque_type(const opaque_type & rhs) : base_type(rhs.val_) {}
        explicit opaque_type(T v) : base_type(v) {}
            
    };




    template <typename Final, typename T, typename Base=base_public_opaque_type>
    class public_opaque_type
        : public
            conv_public_opaque_type2<T, T, mpl::and_<is_class<T>, is_base_of<base_public_opaque_type,T> >::value,
                opaque_type< Final, T, Base>
            >
    {
        typedef
            conv_public_opaque_type2<T, T, mpl::and_<is_class<T>, is_base_of<base_public_opaque_type,T> >::value,
                opaque_type< Final, T, Base>
            > base_type;

    protected:
        typedef public_opaque_type opaque_type_t;
    public:
        typedef T underlying_type;
        typedef typename opaque_type< Final, T, Base>::substituables substituables;
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

    };

    template <typename Final, typename T, typename Base=base_private_opaque_type>
    class private_opaque_type
        : public opaque_type< Final, T, Base >
    {
        typedef opaque_type< Final, T, Base > base_type;
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
