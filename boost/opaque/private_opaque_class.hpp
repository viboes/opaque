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

#ifndef BOOST_OPAQUE_PRIVATE_OPAQUE_CLASS_HPP
#define BOOST_OPAQUE_PRIVATE_OPAQUE_CLASS_HPP

//~ Can instances of UT be explicitly converted to instances of OT? Yes
//~ Can instances of UT be implicitly converted to instances of OT? No
//~ Can instances of OT be explicitly converted to instances of UT? Yes.
//~     Waiting for explicit conversion operators, the explicit
//~     conversion must be done through the underlying function
//~ Can instances of OT be implicitly converted to instances of UT? No

#include <boost/opaque/meta_mixin/inherited_from_underlying.hpp>
#include <boost/opaque/meta_mixin/transitive_explicit_substituable.hpp>

#include <boost/type_traits/is_class.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/push_front.hpp>

namespace boost {
namespace opaque {
    class base_private_opaque_type {};

    template <
        typename Final,
        typename T,
        typename Bool=bool,
        typename MetaMixinSeq=boost::mpl::vector0<>,
        typename Base=base_private_opaque_type
    >
    class private_opaque_class
        : public
            new_class< Final, T,
                typename mpl::push_front<
                    typename mpl::push_front<
                        MetaMixinSeq,
                        opaque::transitive_explicit_substituable<base_private_opaque_type, T>
                    >::type,
                    opaque::inherited_from_underlying<T,Bool>
                >::type, Base
            >
    {
        typedef
            new_class< Final, T,
                typename mpl::push_front<
                    typename mpl::push_front<
                        MetaMixinSeq,
                        opaque::transitive_explicit_substituable<base_private_opaque_type, T>
                    >::type,
                    opaque::inherited_from_underlying<T,Bool>
                >::type, Base
            >
        base_type;

    public:

        private_opaque_class() {};
        private_opaque_class(const private_opaque_class & rhs)
            : base_type(rhs.val_) {}
        private_opaque_class(const Final & rhs)
            : base_type(rhs.val_) {}
        explicit private_opaque_class(T v)
            : base_type(v) {};
        template <typename W>
        explicit private_opaque_class(W v)
            : base_type(v)
        {}
    };
}
}


#endif
