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

    //! meta-mixin stating which operations are inherited from UT.
    //! The user must specialize this meta-mixin to state which operations are inherited from UT.
    //! This class must be specialized for specific types in order to make easier the construction of opaque types having UT as underlying type.
    template <typename UT, typename Bool=bool>
    struct inherited_from_underlying
    {
      template <typename Final, typename Base>
      struct type : Base  {

      };
    };

    //! Helper class to inherit from all the arithmetic operations.
    template <typename Bool=bool>
    struct inherited_from_arithmetic
    {
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

    //! inherited_from_underlying specializations for each one of the built-in types.
    template <typename Bool>
    struct inherited_from_underlying<char,Bool>
    : inherited_from_arithmetic<Bool> { };
    template <typename Bool>
    struct inherited_from_underlying<short,Bool>
    : inherited_from_arithmetic<Bool> { };
    template <typename Bool>
    struct inherited_from_underlying<int,Bool>
    : inherited_from_arithmetic<Bool> { };
    template <typename Bool>
    struct inherited_from_underlying<long,Bool>
    : inherited_from_arithmetic<Bool> { };
    template <typename Bool>
    struct inherited_from_underlying<long long,Bool>
    : inherited_from_arithmetic<Bool> { };
    template <typename Bool>
    struct inherited_from_underlying<unsigned char,Bool>
    : inherited_from_arithmetic<Bool> { };
    template <typename Bool>
    struct inherited_from_underlying<unsigned short,Bool>
    : inherited_from_arithmetic<Bool> { };
    template <typename Bool>
    struct inherited_from_underlying<unsigned int,Bool>
    : inherited_from_arithmetic<Bool> { };
    template <typename Bool>
    struct inherited_from_underlying<unsigned long,Bool>
    : inherited_from_arithmetic<Bool> { };
    template <typename Bool>
    struct inherited_from_underlying<unsigned long long,Bool>
    : inherited_from_arithmetic<Bool> { };
    template <typename Bool>
    struct inherited_from_underlying<float,Bool>
    : inherited_from_arithmetic<Bool> { };
    template <typename Bool>
    struct inherited_from_underlying<double,Bool>
    : inherited_from_arithmetic<Bool> { };


  }
}

#endif
