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
#include <boost/opaque/public_opaque_class.hpp>

#include <boost/type_traits/is_class.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/vector.hpp>

namespace boost {


    template <typename T, typename Tag=void, typename MetaMixinSeq=boost::mpl::vector0<>, typename Base=base_public_opaque_type>
    class public_opaque_type
        : public public_opaque_class< public_opaque_type<T,Tag,MetaMixinSeq,Base>, T, MetaMixinSeq, Base>
    {
        typedef public_opaque_class< public_opaque_type<T,Tag,MetaMixinSeq,Base>, T, MetaMixinSeq, Base> base_type;
    protected:
        typedef public_opaque_type opaque_type_t;
    public:
        //~ Can instances of UT be explicitly converted to instances of OT? Yes
        //~ Can instances of UT be implicitly converted to instances of OT? No
        //~ Can instances of OT be explicitly converted to instances of UT? Yes
        //~ Can instances of OT be implicitly converted to instances of UT? Yes

        public_opaque_type() {}
        public_opaque_type(const opaque_type_t & rhs) : base_type(rhs.val_){}
        explicit public_opaque_type(T v) : base_type(v) {}
        template <typename W>
        explicit public_opaque_type(W v) : base_type(v) {}

    };

}


#endif
