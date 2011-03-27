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

#ifndef BOOST_OPAQUE_COMBINED_OPERATORS_HPP
#define BOOST_OPAQUE_COMBINED_OPERATORS_HPP

#include <boost/operators.hpp>
#include <boost/opaque/meta_mixin/operators.hpp>

namespace boost {
namespace opaque {

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_EQUALITY_COMPARABLE1(Final,Bool) \
        BOOST_OPAQUE_USING_EQUAL(Final,Bool) \
        BOOST_OPAQUE_USING_NOT_EQUAL(Final,Bool)

    template <typename Bool=bool>
    struct using_equality_comparable1 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_EQUALITY_COMPARABLE1(Final,Bool)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_LESS_THAN_COMPARABLE1(Final,Bool) \
        BOOST_OPAQUE_USING_LESS_THAN(Final,Bool) \
        BOOST_OPAQUE_USING_LESS_THAN_EQUAL(Final,Bool) \
        BOOST_OPAQUE_USING_GREATER_THAN(Final,Bool) \
        BOOST_OPAQUE_USING_GREATER_THAN_EQUAL(Final,Bool)

    template <typename Bool=bool>
    struct using_less_than_comparable1 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_LESS_THAN_COMPARABLE1(Final,Bool)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_ADDABLE1(Final) \
        BOOST_OPAQUE_USING_PLUS_ASSIGN(Final) \
        BOOST_OPAQUE_USING_PLUS(Final)

    struct using_addable1 {
        template <typename Final, typename Base>
        struct type : Base {
        BOOST_OPAQUE_ADDABLE1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_SUBTRACTABLE1(Final) \
        BOOST_OPAQUE_USING_MINUS_ASSIGN(Final) \
        BOOST_OPAQUE_USING_MINUS(Final)

    struct using_subtractable1 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_SUBTRACTABLE1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_MULTIPLIABLE1(Final) \
        BOOST_OPAQUE_USING_MULTIPLY_ASSIGN(Final) \
        BOOST_OPAQUE_USING_MULTIPLY(Final)

    struct using_multipliable1 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_MULTIPLIABLE1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_DIVIDABLE1(Final) \
        BOOST_OPAQUE_USING_DIVIDE_ASSIGN(Final) \
        BOOST_OPAQUE_USING_DIVIDE(Final)

    struct using_dividable1 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_DIVIDABLE1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_MODABLE1(Final) \
        BOOST_OPAQUE_USING_MODULUS_ASSIGN(Final) \
        BOOST_OPAQUE_USING_MODULUS(Final)

    struct using_modable1 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_MODABLE1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_BITWISE_XORABLE1(Final) \
        BOOST_OPAQUE_USING_BITWISE_XOR_ASSIGN(Final) \
        BOOST_OPAQUE_USING_BITWISE_XOR(Final)

    struct using_bitwise_xorable1 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_BITWISE_XORABLE1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_BITWISE_ANDABLE1(Final) \
        BOOST_OPAQUE_USING_BITWISE_AND_ASSIGN(Final) \
        BOOST_OPAQUE_USING_BITWISE_AND(Final)

    struct using_bitwise_andable1 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_BITWISE_ANDABLE1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_BITWISE_ORABLE1(Final) \
        BOOST_OPAQUE_USING_BITWISE_OR_ASSIGN(Final) \
        BOOST_OPAQUE_USING_BITWISE_OR(Final)

    struct using_bitwise_orable1 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_BITWISE_ORABLE1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_INCREMENTABLE(Final) \
        BOOST_OPAQUE_USING_PRE_INCREMENT(Final) \
        BOOST_OPAQUE_USING_POST_INCREMENT(Final)

    struct using_incrementable {
        template <typename Final, typename Base>
        struct type : Base
        {
            BOOST_OPAQUE_INCREMENTABLE(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_DECREMENTABLE(Final) \
        BOOST_OPAQUE_USING_PRE_DECREMENT(Final) \
        BOOST_OPAQUE_USING_POST_DECREMENT(Final)

    struct using_decrementable {
        template <typename Final, typename Base>
        struct type : Base
        {
            BOOST_OPAQUE_DECREMENTABLE(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_LEFT_SHIFTABLE1(Final) \
        BOOST_OPAQUE_USING_LEFT_SHIFT_ASSIGN(Final) \
        BOOST_OPAQUE_USING_LEFT_SHIFT1(Final)

    struct using_left_shiftable1 {
        template <typename Final, typename Base>
        struct type : Base
        {
            BOOST_OPAQUE_LEFT_SHIFTABLE1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_RIGHT_SHIFTABLE1(Final) \
        BOOST_OPAQUE_USING_RIGHT_SHIFT_ASSIGN(Final) \
        BOOST_OPAQUE_USING_RIGHT_SHIFT1(Final)

    struct using_right_shiftable1 {
        template <typename Final, typename Base>
        struct type : Base
        {
            BOOST_OPAQUE_RIGHT_SHIFTABLE1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_PARTIALLY_ORDERED1(Final,Bool) \
        BOOST_OPAQUE_USING_LESS_THAN(Final,Bool) \
        BOOST_OPAQUE_USING_LESS_THAN_EQUAL(Final,Bool) \
        BOOST_OPAQUE_USING_GREATER_THAN(Final,Bool) \
        BOOST_OPAQUE_USING_GREATER_THAN_EQUAL(Final,Bool)

    template <typename Bool=bool>
    struct using_partially_ordered1 {
        template <typename Final, typename Base>
        struct type : boost::partially_ordered1<Final, Base > {
            BOOST_OPAQUE_USING_LESS_THAN(Final,Bool)
        };
    };


//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_TOTALY_ORDERED1(Final,Bool) \
        BOOST_OPAQUE_EQUALITY_COMPARABLE1(Final,Bool) \
        BOOST_OPAQUE_LESS_THAN_COMPARABLE1(Final,Bool)

    template <typename Bool=bool>
    struct using_totally_ordered1 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_TOTALY_ORDERED1(Final,Bool)
        };
    };

//////////////////////////////////////////////////////////////////////////////

    //~ template <class T, class U, typename Base = base_opaque_type >
    //~ struct additive2
        //~ : opaque::addable2<T, U
        //~ , opaque::subtractable2<T, U, Base
          //~ > > {};

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_ADDITIVE1(Final) \
        BOOST_OPAQUE_ADDABLE1(Final) \
        BOOST_OPAQUE_SUBTRACTABLE1(Final)

    struct using_additive1 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_ADDITIVE1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

    //~ template <class T, class U, typename Base = base_opaque_type >
    //~ struct multiplicative2
        //~ : opaque::multipliable2<T, U
        //~ , opaque::dividable2<T, U, Base
          //~ > > {};

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_MULTIPLICATIVE1(Final) \
        BOOST_OPAQUE_MULTIPLIABLE1(Final) \
        BOOST_OPAQUE_DIVIDABLE1(Final)

    struct using_multiplicative1 {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_MULTIPLICATIVE1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

    //~ template <class T, class U, typename Base = base_opaque_type >
    //~ struct integer_multiplicative2
        //~ : opaque::multiplicative2<T, U
        //~ , opaque::modable2<T, U, Base
          //~ > > {};

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_INTEGER_MULTIPLICATIVE1(Final) \
        BOOST_OPAQUE_MULTIPLICATIVE1(Final) \
        BOOST_OPAQUE_MODABLE1(Final)

    struct integer_multiplicative1
    {
        template <typename Final, typename Base = base_opaque_type >
        struct type : Base
        {
            BOOST_OPAQUE_INTEGER_MULTIPLICATIVE1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

    //~ template <class T, class U, typename Base = base_opaque_type >
    //~ struct arithmetic2
        //~ : opaque::additive2<T, U
        //~ , opaque::multiplicative2<T, U, Base
          //~ > > {};

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_ARITHMETIC1(Final) \
        BOOST_OPAQUE_ADDITIVE1(Final) \
        BOOST_OPAQUE_MULTIPLICATIVE1(Final)

    struct using_arithmetic1
    {
        template <typename Final, typename Base = base_opaque_type >
        struct type : Base
        {
            BOOST_OPAQUE_ARITHMETIC1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

    //~ template <class T, class U, typename Base = base_opaque_type >
    //~ struct integer_arithmetic2
        //~ : additive2<T, U
        //~ , integer_multiplicative2<T, U, Base
          //~ > > {};

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_INTEGER_ARITHMETIC1(Final) \
        BOOST_OPAQUE_ADDITIVE1(Final) \
        BOOST_OPAQUE_INTEGER_MULTIPLICATIVE1(Final)

    struct using_integer_arithmetic1
    {
        template <typename Final, typename Base = base_opaque_type >
        struct type : Base
        {
            BOOST_OPAQUE_INTEGER_ARITHMETIC1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

    //~ template <class T, class U, typename Base = base_opaque_type >
    //~ struct bitwise2
        //~ : opaque::xorable2<T, U
        //~ , opaque::andable2<T, U
        //~ , opaque::orable2<T, U, Base
          //~ > > > {};

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_BITWISE1(Final) \
        BOOST_OPAQUE_BITWISE_XORABLE1(Final) \
        BOOST_OPAQUE_BITWISE_ANDABLE1(Final) \
        BOOST_OPAQUE_BITWISE_ORABLE1(Final)

    struct using_bitwise1
    {
        template <typename Final, typename Base = base_opaque_type >
        struct type : Base
        {
            BOOST_OPAQUE_BITWISE1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_UNIT_STEPABLE(Final) \
        BOOST_OPAQUE_INCREMENTABLE(Final) \
        BOOST_OPAQUE_DECREMENTABLE(Final)

    struct using_unit_steppable
    {
        template <typename Final, typename Base = base_opaque_type >
        struct type : Base
        {
            BOOST_OPAQUE_UNIT_STEPABLE(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

    //~ template <class T, class U, typename Base = base_opaque_type >
    //~ struct shiftable2
        //~ : opaque::left_shiftable2<T, U
        //~ , opaque::right_shiftable2<T, U, Base
          //~ > > {};

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_SHIFTABLE1(Final) \
        BOOST_OPAQUE_LEFT_SHIFTABLE1(Final) \
        BOOST_OPAQUE_RIGHT_SHIFTABLE1(Final)

    struct using_shiftable1
    {
        template <typename Final, typename Base = base_opaque_type >
        struct type : Base
        {
            BOOST_OPAQUE_SHIFTABLE1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

    //~ template <class T, class U, typename Base = base_opaque_type >
    //~ struct ring_operators2
        //~ : opaque::additive2<T, U
        //~ , opaque::subtractable2_left<T, U
        //~ , opaque::multipliable2<T, U, Base
          //~ > > > {};

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_RING1(Final) \
        BOOST_OPAQUE_ADDITIVE1(Final) \
        BOOST_OPAQUE_MULTIPLIABLE1(Final)

    struct using_ring_operators1
    {
        template <typename Final, typename Base = base_opaque_type >
        struct type: Base
        {
            BOOST_OPAQUE_RING1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

    //~ template <class T, class U, typename Base = base_opaque_type >
    //~ struct ordered_ring_operators2
        //~ : opaque::ring_operators2<T, U
        //~ , opaque::totally_ordered2<T, U, Base
          //~ > > {};

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_ORDERED_RING1(Final, Bool) \
        BOOST_OPAQUE_RING1(Final) \
        BOOST_OPAQUE_TOTALY_ORDERED1(Final,Bool)

    template <typename Bool=bool>
    struct using_ordered_ring_operators1
    {
        template <typename Final, typename Base = base_opaque_type>
        struct type : Base
        {
            BOOST_OPAQUE_ORDERED_RING1(Final,Bool)
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

    #define BOOST_OPAQUE_FIELD1(Final) \
        BOOST_OPAQUE_RING1(Final) \
        BOOST_OPAQUE_DIVIDABLE1(Final)

    struct using_field_operators1
    {
        template <typename Final, typename Base = base_opaque_type>
        struct type: Base
        {
            BOOST_OPAQUE_FIELD1(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////

    //~ template <class T, class U, typename Base = base_opaque_type >
    //~ struct ordered_field_operators2
        //~ : opaque::field_operators2<T, U
        //~ , opaque::totally_ordered2<T, U, Base
          //~ > > {};

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_ORDERED_FIELD1(Final, Bool) \
        BOOST_OPAQUE_FIELD1(Final) \
        BOOST_OPAQUE_TOTALY_ORDERED1(Final,Bool)

    template <typename Bool=bool>
    struct using_ordered_field_operators1
    {
        template <typename Final, typename Base = base_opaque_type>
        struct type : Base
        {
            BOOST_OPAQUE_ORDERED_FIELD1(Final,Bool)
        };
    };

}
}


#endif
