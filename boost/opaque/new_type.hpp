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

#ifndef BOOST_OPAQUE_NEW_TYPE_HPP
#define BOOST_OPAQUE_NEW_TYPE_HPP

#include <boost/opaque/new_class.hpp>
#include <boost/mpl/vector.hpp>

namespace boost {
namespace opaque {


    template <
        typename T,
        typename Tag,
        typename MetaMixinSeq=boost::mpl::vector0<>,
        typename Base=base_new_type
    >
    class new_type
        : public new_class<new_type<T, Tag, MetaMixinSeq, Base>,
                T, MetaMixinSeq, Base>
    {
        typedef new_class<new_type<T, Tag, MetaMixinSeq, Base>,
                    T, MetaMixinSeq, Base> base_type;
    public:
        template <typename W>
        explicit new_type(W v) : base_type(v) {}
        new_type(){}
        new_type(const new_type & rhs) : base_type(rhs.val_) {}
        explicit new_type(T v) : base_type(v) {}

    };

    template <
        typename T, 
        typename UT, 
        typename Tag, 
        typename MetaMixinSeq, 
        typename Base 
    >
    T opaque_static_cast(new_type<UT,Tag,MetaMixinSeq,Base> const& v)
    {
        return static_cast<T>(v.underlying());
    }
}
}


#endif
