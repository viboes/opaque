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

#include <boost/opaque/opaque_type.hpp>

#include <boost/type_traits/is_class.hpp>
#include <boost/type_traits/is_base_of.hpp>

namespace boost {

    class base_private_opaque_type {};

    template <typename Final, typename T, typename Base=base_private_opaque_type>
    class private_opaque_type
        : public new_type< Final, T, typename inherited_from_undelying<T, Final, Base>::type >
    {
        typedef new_type< Final, T, typename inherited_from_undelying<T, Final, Base>::type > base_type;
    protected:
        typedef private_opaque_type opaque_type_t;
    public:
        //~ Can instances of UT be explicitly converted to instances of OT? Yes
        //~ Can instances of UT be implicitly converted to instances of OT? No
        //~ Can instances of OT be explicitly converted to instances of UT? Yes, throogh the underlying function
        //~ Can instances of OT be implicitly converted to instances of UT? Yes

        private_opaque_type() {};
        private_opaque_type(const opaque_type_t & rhs) : base_type(rhs.val_) {}
        private_opaque_type(const Final & rhs) : base_type(rhs.val_) {}
        explicit private_opaque_type(T v) : base_type(v) {};
        template <typename W>
        explicit private_opaque_type(W v)
            : base_type(v)
        {}
    };

}


#endif
