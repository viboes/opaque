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

#ifndef BOOST_OPAQUE_OPAQUE_TYPE_HPP
#define BOOST_OPAQUE_OPAQUE_TYPE_HPP

#include <boost/opaque/new_type.hpp>
#include <boost/opaque/combined_operators.hpp>

namespace boost {

    template <typename T, typename Final, typename Base>
    struct inherited_from_undelying {
        struct type :
            opaque::totally_ordered1< Final
            ,   opaque::integer_arithmetic1< Final
                ,   boost::bitwise1< Final
                    ,   opaque::unit_steppable< Final
                        ,   underlying_access< Final, T, Base >
                        >
                    >
                >
            >
        {};
    };

}


#endif
