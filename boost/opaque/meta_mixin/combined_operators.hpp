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

/**
 * @file
 * This file includes meta-mixins combining several operators.
 *
 * These meta-mixins have names that follows the naming used in <b>Boost.Operators</b>, but prefixed by @c using_.
 *
 * The composite operator templates only list what other templates they use.
 * The supplied operations and requirements of the composite operator templates can be inferred from the
 * operations and requirements of the listed components.
 *
 * See the section for a complete list of combined meta-mixins.
 */

#ifndef BOOST_OPAQUE_COMBINED_OPERATORS_HPP
#define BOOST_OPAQUE_COMBINED_OPERATORS_HPP
#if !defined(BOOST_OPAQUE_DOXYGEN_INVOKED)

#include <boost/operators.hpp>
#include <boost/opaque/meta_mixin/operators.hpp>

namespace boost {
namespace opaque {

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_EQUALITY_COMPARABLE(Final,Bool) \
        BOOST_OPAQUE_USING_EQUAL(Final,Bool) \
        BOOST_OPAQUE_USING_NOT_EQUAL(Final,Bool)

    template <typename Bool=bool>
    struct using_equality_comparable {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_EQUALITY_COMPARABLE(Final,Bool)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_LESS_THAN_COMPARABLE(Final,Bool) \
        BOOST_OPAQUE_USING_LESS_THAN(Final,Bool) \
        BOOST_OPAQUE_USING_LESS_THAN_EQUAL(Final,Bool) \
        BOOST_OPAQUE_USING_GREATER_THAN(Final,Bool) \
        BOOST_OPAQUE_USING_GREATER_THAN_EQUAL(Final,Bool)

    template <typename Bool=bool>
    struct using_less_than_comparable {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_LESS_THAN_COMPARABLE(Final,Bool)
        };
    };

#define BOOST_OPAQUE_USING_LESS_THAN_COMPARABLE2(Final, Bool) \
        BOOST_OPAQUE_USING_LESS_THAN2(Final,Bool) \
        BOOST_OPAQUE_USING_LESS_THAN_EQUAL2(Final,Bool) \
        BOOST_OPAQUE_USING_GREATER_THAN2(Final,Bool) \
        BOOST_OPAQUE_USING_GREATER_THAN_EQUAL2(Final,Bool)

    template <typename Bool=bool>
    struct using_less_than_comparable2 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_LESS_THAN_COMPARABLE2(Final, Bool)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_ADDABLE(Final) \
        BOOST_OPAQUE_USING_PLUS_ASSIGN(Final) \
        BOOST_OPAQUE_USING_PLUS(Final)

    struct using_addable {
        template <typename Final, typename Base>
        struct type : Base {
        BOOST_OPAQUE_USING_ADDABLE(Final)
        };
    };

#define BOOST_OPAQUE_USING_ADDABLE2(Final) \
        BOOST_OPAQUE_USING_PLUS_ASSIGN(Final) \
        BOOST_OPAQUE_USING_PLUS2(Final)

    struct using_addable2 {
        template <typename Final, typename Base>
        struct type : Base {
        BOOST_OPAQUE_USING_ADDABLE2(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_SUBTRACTABLE(Final) \
        BOOST_OPAQUE_USING_MINUS_ASSIGN(Final) \
        BOOST_OPAQUE_USING_MINUS(Final)

    struct using_subtractable {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_SUBTRACTABLE(Final)
        };
    };

#define BOOST_OPAQUE_USING_SUBTRACTABLE2(Final) \
        BOOST_OPAQUE_USING_MINUS_ASSIGN(Final) \
        BOOST_OPAQUE_USING_MINUS2(Final)

    struct using_subtractable2 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_SUBTRACTABLE2(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_MULTIPLIABLE(Final) \
        BOOST_OPAQUE_USING_MULTIPLY_ASSIGN(Final) \
        BOOST_OPAQUE_USING_MULTIPLY(Final)

    struct using_multipliable {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_MULTIPLIABLE(Final)
        };
    };

#define BOOST_OPAQUE_USING_MULTIPLIABLE2(Final) \
        BOOST_OPAQUE_USING_MULTIPLY_ASSIGN(Final) \
        BOOST_OPAQUE_USING_MULTIPLY2(Final)

    struct using_multipliable2 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_MULTIPLIABLE2(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_DIVIDABLE(Final) \
        BOOST_OPAQUE_USING_DIVIDE_ASSIGN(Final) \
        BOOST_OPAQUE_USING_DIVIDE(Final)

    struct using_dividable {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_DIVIDABLE(Final)
        };
    };

#define BOOST_OPAQUE_USING_DIVIDABLE2(Final) \
        BOOST_OPAQUE_USING_DIVIDE_ASSIGN(Final) \
        BOOST_OPAQUE_USING_DIVIDE2(Final)

    struct using_dividable2 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_DIVIDABLE2(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_MODABLE(Final) \
        BOOST_OPAQUE_USING_MODULUS_ASSIGN(Final) \
        BOOST_OPAQUE_USING_MODULUS(Final)

    struct using_modable {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_MODABLE(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_BITWISE_XORABLE(Final) \
        BOOST_OPAQUE_USING_BITWISE_XOR_ASSIGN(Final) \
        BOOST_OPAQUE_USING_BITWISE_XOR(Final)

    struct using_bitwise_xorable {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_BITWISE_XORABLE(Final)
        };
    };

#define BOOST_OPAQUE_USING_BITWISE_XORABLE2(Final) \
        BOOST_OPAQUE_USING_BITWISE_XOR_ASSIGN(Final) \
        BOOST_OPAQUE_USING_BITWISE_XOR2(Final)

    struct using_bitwise_xorable2 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_BITWISE_XORABLE2(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_BITWISE_ANDABLE(Final) \
        BOOST_OPAQUE_USING_BITWISE_AND_ASSIGN(Final) \
        BOOST_OPAQUE_USING_BITWISE_AND(Final)

    struct using_bitwise_andable {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_BITWISE_ANDABLE(Final)
        };
    };

#define BOOST_OPAQUE_USING_BITWISE_ANDABLE2(Final) \
        BOOST_OPAQUE_USING_BITWISE_AND_ASSIGN(Final) \
        BOOST_OPAQUE_USING_BITWISE_AND2(Final)

    struct using_bitwise_andable2 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_BITWISE_ANDABLE2(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_BITWISE_ORABLE(Final) \
        BOOST_OPAQUE_USING_BITWISE_OR_ASSIGN(Final) \
        BOOST_OPAQUE_USING_BITWISE_OR(Final)

    struct using_bitwise_orable {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_BITWISE_ORABLE(Final)
        };
    };

#define BOOST_OPAQUE_USING_BITWISE_ORABLE2(Final) \
        BOOST_OPAQUE_USING_BITWISE_OR_ASSIGN(Final) \
        BOOST_OPAQUE_USING_BITWISE_OR2(Final)

    struct using_bitwise_orable2 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_BITWISE_ORABLE2(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_INCREMENTABLE(Final) \
        BOOST_OPAQUE_USING_PRE_INCREMENT(Final) \
        BOOST_OPAQUE_USING_POST_INCREMENT(Final)

    struct using_incrementable {
        template <typename Final, typename Base>
        struct type : Base
        {
            BOOST_OPAQUE_USING_INCREMENTABLE(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_DECREMENTABLE(Final) \
        BOOST_OPAQUE_USING_PRE_DECREMENT(Final) \
        BOOST_OPAQUE_USING_POST_DECREMENT(Final)

    struct using_decrementable {
        template <typename Final, typename Base>
        struct type : Base
        {
            BOOST_OPAQUE_USING_DECREMENTABLE(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_LEFT_SHIFTABLE(Final) \
        BOOST_OPAQUE_USING_LEFT_SHIFT_ASSIGN(Final) \
        BOOST_OPAQUE_USING_LEFT_SHIFT(Final)

    struct using_left_shiftable {
        template <typename Final, typename Base>
        struct type : Base
        {
            BOOST_OPAQUE_USING_LEFT_SHIFTABLE(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_RIGHT_SHIFTABLE(Final) \
        BOOST_OPAQUE_USING_RIGHT_SHIFT_ASSIGN(Final) \
        BOOST_OPAQUE_USING_RIGHT_SHIFT(Final)

    struct using_right_shiftable {
        template <typename Final, typename Base>
        struct type : Base
        {
            BOOST_OPAQUE_USING_RIGHT_SHIFTABLE(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_PARTIALLY_ORDERED(Final,Bool) \
        BOOST_OPAQUE_USING_LESS_THAN(Final,Bool) \
        BOOST_OPAQUE_USING_LESS_THAN_EQUAL(Final,Bool) \
        BOOST_OPAQUE_USING_GREATER_THAN(Final,Bool) \
        BOOST_OPAQUE_USING_GREATER_THAN_EQUAL(Final,Bool)

    template <typename Bool=bool>
    struct using_partially_ordered {
        template <typename Final, typename Base>
        struct type : Base {
          BOOST_OPAQUE_USING_PARTIALLY_ORDERED(Final,Bool)
        };
    };


//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_TOTALY_ORDERED(Final,Bool) \
        BOOST_OPAQUE_USING_EQUALITY_COMPARABLE(Final,Bool) \
        BOOST_OPAQUE_USING_LESS_THAN_COMPARABLE(Final,Bool)

    template <typename Bool=bool>
    struct using_totally_ordered {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_TOTALY_ORDERED(Final,Bool)
        };
    };

#define BOOST_OPAQUE_USING_TOTALY_ORDERED2(Final, Bool) \
        BOOST_OPAQUE_USING_EQUALITY_COMPARABLE(Final, Bool) \
        BOOST_OPAQUE_USING_LESS_THAN_COMPARABLE2(Final, Bool)

    template <typename Bool=bool>
    struct using_totally_ordered2 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_TOTALY_ORDERED2(Final, Bool)
        };
    };

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_USING_ADDITIVE(Final) \
        BOOST_OPAQUE_USING_ADDABLE(Final) \
        BOOST_OPAQUE_USING_SUBTRACTABLE(Final)

    struct using_additive {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_ADDITIVE(Final)
        };
    };

    #define BOOST_OPAQUE_USING_ADDITIVE2(Final) \
      BOOST_OPAQUE_USING_ADDABLE2(Final) \
      BOOST_OPAQUE_USING_SUBTRACTABLE2(Final)

    struct using_additive2 {
      template <typename Final, typename Base>
      struct type : Base {
        BOOST_OPAQUE_USING_ADDITIVE2(Final)
      };
    };



//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_USING_MULTIPLICATIVE(Final) \
        BOOST_OPAQUE_USING_MULTIPLIABLE(Final) \
        BOOST_OPAQUE_USING_DIVIDABLE(Final)

    struct using_multiplicative {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_USING_MULTIPLICATIVE(Final)
        };
    };

    #define BOOST_OPAQUE_USING_MULTIPLICATIVE2(Final) \
      BOOST_OPAQUE_USING_MULTIPLIABLE2(Final) \
      BOOST_OPAQUE_USING_DIVIDABLE2(Final)

    struct using_multiplicative2 {
      template <typename Final, typename Base>
      struct type : Base {
        BOOST_OPAQUE_USING_MULTIPLICATIVE2(Final)
      };
    };

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_USING_INTEGER_MULTIPLICATIVE(Final) \
        BOOST_OPAQUE_USING_MULTIPLICATIVE(Final) \
        BOOST_OPAQUE_USING_MODABLE(Final)

    struct integer_multiplicative
    {
        template <typename Final, typename Base = base_opaque_type >
        struct type : Base
        {
            BOOST_OPAQUE_USING_INTEGER_MULTIPLICATIVE(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_USING_ARITHMETIC(Final) \
        BOOST_OPAQUE_USING_ADDITIVE(Final) \
        BOOST_OPAQUE_USING_MULTIPLICATIVE(Final)

    struct using_arithmetic
    {
        template <typename Final, typename Base = base_opaque_type >
        struct type : Base
        {
            BOOST_OPAQUE_USING_ARITHMETIC(Final)
        };
    };

#define BOOST_OPAQUE_USING_ARITHMETIC2(Final) \
    BOOST_OPAQUE_USING_ADDITIVE2(Final) \
    BOOST_OPAQUE_USING_MULTIPLICATIVE2(Final)

struct using_arithmetic2
{
    template <typename Final, typename Base = base_opaque_type >
    struct type : Base
    {
        BOOST_OPAQUE_USING_ARITHMETIC2(Final)
    };
};

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_USING_INTEGER_ARITHMETIC(Final) \
        BOOST_OPAQUE_USING_ADDITIVE(Final) \
        BOOST_OPAQUE_USING_INTEGER_MULTIPLICATIVE(Final)

    struct using_integer_arithmetic1
    {
        template <typename Final, typename Base = base_opaque_type >
        struct type : Base
        {
            BOOST_OPAQUE_USING_INTEGER_ARITHMETIC(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

    //~ template <class T, class U, typename Base = base_opaque_type >
    //~ struct bitwise2
        //~ : opaque::xorable2<T
        //~ , opaque::andable2<T
        //~ , opaque::orable2<T, U, Base
          //~ > > > {};

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_USING_BITWISE(Final) \
        BOOST_OPAQUE_USING_BITWISE_XORABLE(Final) \
        BOOST_OPAQUE_USING_BITWISE_ANDABLE(Final) \
        BOOST_OPAQUE_USING_BITWISE_ORABLE(Final)

    struct using_bitwise
    {
        template <typename Final, typename Base = base_opaque_type >
        struct type : Base
        {
            BOOST_OPAQUE_USING_BITWISE(Final)
        };
    };

#define BOOST_OPAQUE_USING_BITWISE2(Final) \
    BOOST_OPAQUE_USING_BITWISE_XORABLE2(Final) \
    BOOST_OPAQUE_USING_BITWISE_ANDABLE2(Final) \
    BOOST_OPAQUE_USING_BITWISE_ORABLE2(Final)

struct using_bitwise2
{
    template <typename Final, typename Base = base_opaque_type >
    struct type : Base
    {
        BOOST_OPAQUE_USING_BITWISE2(Final)
    };
};

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_USING_UNIT_STEPABLE(Final) \
        BOOST_OPAQUE_USING_INCREMENTABLE(Final) \
        BOOST_OPAQUE_USING_DECREMENTABLE(Final)

    struct using_unit_steppable
    {
        template <typename Final, typename Base = base_opaque_type >
        struct type : Base
        {
            BOOST_OPAQUE_USING_UNIT_STEPABLE(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

    //~ template <class T, class U, typename Base = base_opaque_type >
    //~ struct shiftable2
        //~ : opaque::left_shiftable2<T, U
        //~ , opaque::right_shiftable2<T, U, Base
          //~ > > {};

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_USING_SHIFTABLE(Final) \
        BOOST_OPAQUE_USING_LEFT_SHIFTABLE(Final) \
        BOOST_OPAQUE_USING_RIGHT_SHIFTABLE(Final)

    struct using_shiftable1
    {
        template <typename Final, typename Base = base_opaque_type >
        struct type : Base
        {
            BOOST_OPAQUE_USING_SHIFTABLE(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_USING_RING_OPERATORS(Final) \
        BOOST_OPAQUE_USING_ADDITIVE(Final) \
        BOOST_OPAQUE_USING_MULTIPLIABLE(Final)

    struct using_ring_operators
    {
        template <typename Final, typename Base = base_opaque_type >
        struct type: Base
        {
            BOOST_OPAQUE_USING_RING_OPERATORS(Final)
        };
    };

#define BOOST_OPAQUE_USING_RING_OPERATORS2(Final) \
    BOOST_OPAQUE_USING_ADDITIVE2(Final) \
    BOOST_OPAQUE_USING_MULTIPLIABLE2(Final)

struct using_ring_operators2
{
    template <typename Final, typename Base = base_opaque_type >
    struct type: Base
    {
      BOOST_OPAQUE_USING_RING_OPERATORS2(Final)
    };
};


//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_USING_ORDERED_RING_OPERATORS(Final, Bool) \
        BOOST_OPAQUE_USING_RING_OPERATORS(Final) \
        BOOST_OPAQUE_USING_TOTALY_ORDERED(Final,Bool)

    template <typename Bool=bool>
    struct using_ordered_ring_operators
    {
        template <typename Final, typename Base = base_opaque_type>
        struct type : Base
        {
            BOOST_OPAQUE_USING_ORDERED_RING_OPERATORS(Final,Bool)
        };
    };

#define BOOST_OPAQUE_USING_ORDERED_RING_OPERATORS2(Final, Bool) \
    BOOST_OPAQUE_USING_RING_OPERATORS2(Final) \
    BOOST_OPAQUE_USING_TOTALY_ORDERED2(Final,Bool)

template <typename Bool=bool>
struct using_ordered_ring_operators2
{
    template <typename Final, typename Base = base_opaque_type>
    struct type : Base
    {
        BOOST_OPAQUE_USING_ORDERED_RING_OPERATORS2(Final,Bool)
    };
};

//////////////////////////////////////////////////////////////////////////////

    //~ template <class T, class U, typename Base = base_opaque_type >
    //~ struct field_operators2
        //~ : opaque::ring_operators2<T, U
        //~ , opaque::dividable2<T, U
        //~ , opaque::dividable2_left<T, U, Base
          //~ > > > {};

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_USING_FIELD_OPERATORS(Final) \
        BOOST_OPAQUE_USING_RING_OPERATORS(Final) \
        BOOST_OPAQUE_USING_DIVIDABLE(Final)

    struct using_field_operators
    {
        template <typename Final, typename Base = base_opaque_type>
        struct type: Base
        {
            BOOST_OPAQUE_USING_FIELD_OPERATORS(Final)
        };
    };

#define BOOST_OPAQUE_USING_FIELD_OPERATORS2(Final) \
     BOOST_OPAQUE_USING_RING_OPERATORS2(Final) \
     BOOST_OPAQUE_USING_DIVIDABLE2(Final)

 struct using_field_operators2
 {
     template <typename Final, typename Base = base_opaque_type>
     struct type: Base
     {
         BOOST_OPAQUE_USING_FIELD_OPERATORS2(Final)
     };
 };
//////////////////////////////////////////////////////////////////////////////

    //~ template <class T, class U, typename Base = base_opaque_type >
    //~ struct ordered_field_operators2
        //~ : opaque::field_operators2<T, U
        //~ , opaque::totally_ordered2<T, U, Base
          //~ > > {};

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_USING_ORDERED_FIELD_OPERATORS(Final, Bool) \
        BOOST_OPAQUE_USING_FIELD_OPERATORS(Final) \
        BOOST_OPAQUE_USING_TOTALY_ORDERED(Final,Bool)

    template <typename Bool=bool>
    struct using_ordered_field_operators
    {
        template <typename Final, typename Base = base_opaque_type>
        struct type : Base
        {
            BOOST_OPAQUE_USING_ORDERED_FIELD_OPERATORS(Final,Bool)
        };
    };

#define BOOST_OPAQUE_USING_ORDERED_FIELD_OPERATORS2(Final, Bool) \
    BOOST_OPAQUE_USING_FIELD_OPERATORS2(Final) \
    BOOST_OPAQUE_USING_TOTALY_ORDERED2(Final, Bool)

template <typename Bool=bool>
struct using_ordered_field_operators2
{
    template <typename Final, typename Base = base_opaque_type>
    struct type : Base
    {
        BOOST_OPAQUE_USING_ORDERED_FIELD_OPERATORS2(Final, Bool)
    };
};

}
}


#endif
#endif
