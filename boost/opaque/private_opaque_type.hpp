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

#ifndef BOOST_OPAQUE_PRIVATE_OPAQUE_TYPE_HPP
#define BOOST_OPAQUE_PRIVATE_OPAQUE_TYPE_HPP

#include <boost/opaque/private_opaque_class.hpp>

        //~ Can instances of UT be explicitly converted to instances of OT? Yes
        //~ Can instances of UT be implicitly converted to instances of OT? No
        //~ Can instances of OT be explicitly converted to instances of UT? Yes.
        //~     Waiting for explicit conversion operators,, the explicit
        //~     conversion must be done through the underlying function
        //~ Can instances of OT be implicitly converted to instances of UT? No

namespace boost {
namespace opaque {

    template <
        typename T,
        typename Tag=void,
        typename Bool=bool,
        typename MetaMixinSeq=boost::mpl::vector0<>,
        typename Base=base_private_opaque_type
    >
    class private_opaque_type : public
            private_opaque_class< private_opaque_type<T,Tag,Bool,MetaMixinSeq,Base>,
                T, Bool, MetaMixinSeq, Base>
    {
        typedef
            private_opaque_class< private_opaque_type<T,Tag,Bool,MetaMixinSeq,Base>,
                T, Bool, MetaMixinSeq, Base>
        base_type;

    public:

        private_opaque_type() {};
        private_opaque_type(const private_opaque_type & rhs)
            : base_type(rhs.val_) {}
        explicit private_opaque_type(T v)
            : base_type(v) {};
        template <typename W>
        explicit private_opaque_type(W v)
            : base_type(v)
        {}
    };
}
}


#endif
