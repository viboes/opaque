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

#ifndef BOOST_OPAQUE_INHERITED_FROM_UNDERLYING_HPP
#define BOOST_OPAQUE_INHERITED_FROM_UNDERLYING_HPP

#include <boost/opaque/meta_mixin/combined_operators.hpp>

namespace boost {
namespace opaque {

    template <typename T, typename Bool=bool>
    struct inherited_from_underlying {
        template <typename Final, typename Base>
        struct type : Base
        {
            BOOST_OPAQUE_TOTALY_ORDERED1(Final,Bool)
            BOOST_OPAQUE_INTEGER_ARITHMETIC1(Final)
            BOOST_OPAQUE_BITWISE1(Final)
            BOOST_OPAQUE_UNIT_STEPABLE(Final)
            BOOST_OPAQUE_USING_UNARY_PLUS(Final)
            BOOST_OPAQUE_USING_UNARY_MINUS(Final)
        };
    };
}
}

#endif
