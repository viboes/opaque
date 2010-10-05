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

#ifndef BOOST_OPAQUE_PUBLIC_OPAQUE_CLASS_HPP
#define BOOST_OPAQUE_PUBLIC_OPAQUE_CLASS_HPP

#include <boost/opaque/meta_mixin/inherited_from_underlying.hpp>
#include <boost/opaque/meta_mixin/transitive_substituable.hpp>

#include <boost/type_traits/is_class.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/push_front.hpp>

namespace boost {

    class base_public_opaque_type {};

    template <typename T, bool B>
    struct get_substituables;

    template <typename T>
    struct get_substituables<T,true> {
        typedef typename mpl::push_front<typename T::substituables, T
            >::type type;
    };

    template <typename T>
    struct get_substituables<T,false> {
        typedef mpl::vector<T> type;
    };

    template <typename BaseClass, typename UT>
    struct transitive_substituable_help {
        template <typename Final, typename Base>
        struct type
            : transitive_substituable<BaseClass, UT>::template type<Final,
                typename opaque::inherited_from_underlying<UT>
                        ::template type<Final, Base>
              >
        {
            operator UT() const {
                    return Final::final(this).underlying();
            }
        };
    };

    template <
        typename Final,
        typename T,
        typename MetaMixinSeq=boost::mpl::vector0<>,
        typename Base=base_public_opaque_type
    >
    class public_opaque_class
        : public
#if 0
            new_class< Final, T, MetaMixinSeq,
#define COMPILER_WORKS
#if !defined(COMPILER_WORKS)
                typename transitive_substituable_help<base_public_opaque_type,T>
                    ::template type<Final, Base>
#else
                typename transitive_substituable<base_public_opaque_type, T>
                        ::template type<Final,
                    typename opaque::inherited_from_underlying<T>
                            ::template type<Final, Base>
                >
#endif
            >
#else
        new_class< Final, T,
            typename mpl::push_front<
                typename mpl::push_front<
                    MetaMixinSeq,
                    transitive_substituable<base_public_opaque_type, T>
        //opaque::inherited_from_underlying<T>
                >::type,
          //      transitive_substituable<base_public_opaque_type, T>
                opaque::inherited_from_underlying<T>
            >::type, Base
        >
#endif

    {
        typedef
#if 0
            new_class< Final, T, MetaMixinSeq,
#if !defined(COMPILER_WORKS)
                typename transitive_substituable_help<base_public_opaque_type,T>
                        ::template type<Final, Base>
#else
                typename transitive_substituable<base_public_opaque_type, T>
                        ::template type<Final,
                    typename opaque::inherited_from_underlying<T>
                            ::template type<Final, Base>
                >
#endif
            >
#else
        new_class< Final, T,
            typename mpl::push_front<
                typename mpl::push_front<
                    MetaMixinSeq,
                    transitive_substituable<base_public_opaque_type, T>
                >::type,
                opaque::inherited_from_underlying<T>
            >::type, Base
        >
#endif
        base_type;

    public:
        typedef typename get_substituables<T,
                    mpl::and_<    is_class<T>,
                            is_base_of<base_public_opaque_type,T>
                    >::value
                 >::type substituables;

        //~ Can instances of UT be explicitly converted to instances of OT? Yes
        //~ Can instances of UT be implicitly converted to instances of OT? No
        //~ Can instances of OT be explicitly converted to instances of UT? Yes
        //~ Can instances of OT be implicitly converted to instances of UT? Yes

        public_opaque_class() {}
        public_opaque_class(const public_opaque_class & rhs)
            : base_type(rhs.val_){}
        public_opaque_class(const Final & rhs)
            : base_type(rhs.val_){}
        explicit public_opaque_class(T v)
            : base_type(v) {}
        template <typename W>
        explicit public_opaque_class(W v)
            : base_type(v) {}

    };

}


#endif
