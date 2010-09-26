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

#include <boost/opaque/combined_operators.hpp>
#include <boost/opaque/new_class.hpp>

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

    template <typename Final, typename UT, typename Base=base_new_type>
    struct transitive_substituable;

    namespace detail {

    template <typename Final, typename UT, typename Base, bool B>
    struct transitive_substituable_next_level;

    template <typename Final, typename UT, typename Base>
    struct transitive_substituable_next_level<Final, UT, Base, true>
        :  transitive_substituable<Final, typename UT::underlying_type, Base> { };

    template <typename Final, typename UT, typename Base>
    struct transitive_substituable_next_level<Final, UT, Base, false> :  Base { };

    }

    template <typename Final, typename UT, typename Base>
    struct transitive_substituable
        : detail::transitive_substituable_next_level<Final, UT, Base,
                mpl::and_<is_class<UT>, is_base_of<base_public_opaque_type, UT> >::value>
    {
        operator UT() const {
                return Final::final(this).underlying();
        }
    };

    template <typename T, typename Base=base_public_opaque_type, typename Tag=void>
    class public_opaque_type
        : public
            new_class< public_opaque_type<T,Base,Tag >, T, 
                transitive_substituable<public_opaque_type<T,Base,Tag >, T, 
                    //~ typename inherited_from_undelying<T, public_opaque_type<T,Base,Tag >, Base>::type 
                    typename inherited_from_undelying<T>::template type<public_opaque_type<T,Base,Tag>, T, Base>
                > 
            >

    {
        typedef
            new_class< public_opaque_type<T,Base,Tag >, T, 
                transitive_substituable<public_opaque_type<T,Base,Tag >, T, 
                    //~ typename inherited_from_undelying<T, public_opaque_type<T,Base,Tag >, Base>::type 
                    typename inherited_from_undelying<T>::template type<public_opaque_type<T,Base,Tag>, T, Base>
                > 
            >
        base_type;

    protected:
        typedef public_opaque_type opaque_type_t;
    public:
        typedef typename get_substituables<T,
                mpl::and_<is_class<T>, is_base_of<base_public_opaque_type,T> >::value
                 >::type substituables;

        //~ Can instances of UT be explicitly converted to instances of OT? Yes
        //~ Can instances of UT be implicitly converted to instances of OT? No
        //~ Can instances of OT be explicitly converted to instances of UT? Yes
        //~ Can instances of OT be implicitly converted to instances of UT? Yes

        public_opaque_type() {}
        public_opaque_type(const opaque_type_t & rhs) : base_type(rhs.val_){}
        explicit public_opaque_type(T v) : base_type(v) {}
        template <typename W>
        explicit public_opaque_type(W v) : base_type(v) {}

        //~ public_opaque_type & operator=(const opaque_type_t & rhs) {
            //~ this->val_ = rhs.val_; return *this;
        //~ }

    };

}


#endif
