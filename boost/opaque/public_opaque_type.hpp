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

#ifndef BOOST_OPAQUE_PUBLIC_OPAQUE_TYPE_HPP
#define BOOST_OPAQUE_PUBLIC_OPAQUE_TYPE_HPP

#include <boost/opaque/opaque_type.hpp>

#include <boost/type_traits/is_class.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/vector.hpp>

namespace boost {

    class base_public_opaque_type {};

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
        //~ typedef T underlying_type;
        //~ typedef typename opaque_type< Final, T, Base>::substituables substituables;
        template <typename U, typename B>
        struct conv {
            typedef
                conv_public_opaque_type<U, T,
                    mpl::and_<is_class<T>, is_base_of<base_public_opaque_type,T> >::value,
                    B> type;
        };
        typedef typename get_substituables<T,
                mpl::and_<is_class<T>, is_base_of<base_public_opaque_type,T> >::value
                 >::type substituables;

        //~ Can instances of UT be explicitly converted to instances of OT?
        //~ Proposed answer: yes.
        //~ Can instances of UT be implicitly converted to instances of OT?
        //~ Proposed answer: no.

        public_opaque_type() {}
        public_opaque_type(const opaque_type_t & rhs) : base_type(rhs.val_){}
        public_opaque_type(const Final & rhs) : base_type(rhs.val_){}
        explicit public_opaque_type(T v) : base_type(v) {}

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

}


#endif
