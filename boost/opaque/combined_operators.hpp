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
#include <boost/opaque/operators.hpp>

namespace boost {

namespace opaque {

#define BOOST_OPAQUE_EQUALITY_COMPARABLE1(Final,Bool) \
        BOOST_OPAQUE_USING_EQUAL(Final,Bool) \
        BOOST_OPAQUE_USING_NOT_EQUAL(Final,Bool)
    
    template <typename Bool=bool>
    struct using_equality_comparable1 {
        template <typename Final, typename UT, typename Base>
        struct type : Base {
            BOOST_OPAQUE_EQUALITY_COMPARABLE1(Final,Bool)
        };
    };

    template <typename Final, typename Base, typename Bool=bool>
    struct equality_comparable1 : Base {
        BOOST_OPAQUE_EQUALITY_COMPARABLE1(Final,Bool)
    };

#define BOOST_OPAQUE_LESS_THAN_COMPARABLE1(Final,Bool) \
        BOOST_OPAQUE_USING_LESS_THAN(Final,Bool) \
        BOOST_OPAQUE_USING_LESS_THAN_EQUAL(Final,Bool) \
        BOOST_OPAQUE_USING_GREATER_THAN(Final,Bool) \
        BOOST_OPAQUE_USING_GREATER_THAN_EQUAL(Final,Bool)

    template <typename Bool=bool>
    struct using_less_than_comparable1 {
        template <typename Final, typename UT, typename Base>
        struct type : Base {
            BOOST_OPAQUE_LESS_THAN_COMPARABLE1(Final,Bool)
        };
    };
    
    template <typename Final, typename Base, typename Bool=bool>
    struct less_than_comparable1 : Base {
        BOOST_OPAQUE_LESS_THAN_COMPARABLE1(Final,Bool)
    };


#define BOOST_OPAQUE_ADDABLE1(Final) \
        BOOST_OPAQUE_USING_PLUS_ASSIGN(Final) \
        BOOST_OPAQUE_USING_PLUS(Final)

    struct using_addable1 {
        template <typename Final, typename UT, typename Base>
        struct type : Base {
        BOOST_OPAQUE_ADDABLE1(Final)
        };
    };
        

    template <typename Final, typename Base>
    struct addable1 : Base  {
        BOOST_OPAQUE_ADDABLE1(Final)
    };

#define BOOST_OPAQUE_SUBTRACTABLE1(Final) \
        BOOST_OPAQUE_USING_MINUS_ASSIGN(Final) \
        BOOST_OPAQUE_USING_MINUS(Final)

    struct using_subtractable1 {
        template <typename Final, typename UT, typename Base>
        struct type : Base {
            BOOST_OPAQUE_SUBTRACTABLE1(Final)
        };
    };
        
    
    template <typename Final, typename Base>
    struct subtractable1 : Base 
    {
        BOOST_OPAQUE_SUBTRACTABLE1(Final)
    };

    
#define BOOST_OPAQUE_MULTIPLIABLE1(Final) \
        BOOST_OPAQUE_USING_MULTIPLY_ASSIGN(Final) \
        BOOST_OPAQUE_USING_MULTIPLY(Final)

    struct using_multipliable1 {
        template <typename Final, typename UT, typename Base>
        struct type : Base {
            BOOST_OPAQUE_MULTIPLIABLE1(Final)
        };
    };
        
    template <typename Final, typename Base>
    struct multipliable1 : Base {
            BOOST_OPAQUE_MULTIPLIABLE1(Final)
    };

#define BOOST_OPAQUE_DIVIDABLE1(Final) \
        BOOST_OPAQUE_USING_DIVIDE_ASSIGN(Final) \
        BOOST_OPAQUE_USING_DIVIDE(Final)

    struct using_dividable1 {
        template <typename Final, typename UT, typename Base>
        struct type : Base {
            BOOST_OPAQUE_DIVIDABLE1(Final)
        };
    };
        
    template <typename Final, typename Base>
    struct dividable1
    //~ : boost::dividable1<Final, ope::divide_assign<Final, Base> >
    : Base 
    {
            BOOST_OPAQUE_DIVIDABLE1(Final)
    };

#define BOOST_OPAQUE_MODABLE1(Final) \
        BOOST_OPAQUE_USING_MODULUS_ASSIGN(Final) \
        BOOST_OPAQUE_USING_MODULUS(Final)

    struct using_modable1 {
        template <typename Final, typename UT, typename Base>
        struct type : Base {
            BOOST_OPAQUE_MODABLE1(Final)
        };
    };
    template <typename Final, typename Base>
    struct modable1 : Base {
            BOOST_OPAQUE_MODABLE1(Final)
    };

    template <typename Final, typename Base>
    struct xorable1 : boost::xorable1<Final, ope::bitwise_xor_assign<Final, Base> > {};

    template <typename Final, typename Base>
    struct andable1 : boost::andable1<Final, ope::bitwise_and_assign<Final, Base> > {};

    template <typename Final, typename Base>
    struct orable1 : boost::orable1<Final, ope::bitwise_or_assign<Final, Base> > {};

    template <typename Final, typename Base>
    struct incrementable : boost::incrementable<Final, ope::pre_increment<Final, Base> > {};

    template <typename Final, typename Base>
    struct decrementable : boost::decrementable<Final, ope::pre_decrement<Final, Base> > {};

    template <typename Final, typename Base>
    struct left_shiftable1 : boost::left_shiftable1<Final, ope::left_shift_assign<Final, Base> > {};

    template <typename Final, typename Base>
    struct right_shiftable1 : boost::right_shiftable1<Final, ope::right_shift_assign<Final, Base> > {};

    template <typename Final, typename Base>
    struct partially_ordered1 : boost::partially_ordered1<Final, ope::less_than<Final, Base> > {};

#define BOOST_OPAQUE_TOTALY_ORDERED1(Final,Bool) \
        BOOST_OPAQUE_EQUALITY_COMPARABLE1(Final,Bool) \
        BOOST_OPAQUE_LESS_THAN_COMPARABLE1(Final,Bool)

    template <typename Bool=bool>
    struct using_totally_ordered1 {
        template <typename Final, typename UT, typename Base>
        struct type : Base {
            BOOST_OPAQUE_TOTALY_ORDERED1(Final,Bool)
        };
    };
        
    template <class Final, class UT, class Base, typename Bool=bool >
    struct totally_ordered1 : Base 
    {
        BOOST_OPAQUE_TOTALY_ORDERED1(Final,Bool)
    };

    //~ template <class T, class U, class Base = base_new_type >
    //~ struct additive2
        //~ : opaque::addable2<T, U
        //~ , opaque::subtractable2<T, U, Base
          //~ > > {};

    #define BOOST_OPAQUE_ADDITIVE1(Final) \
        BOOST_OPAQUE_ADDABLE1(Final) \
        BOOST_OPAQUE_SUBTRACTABLE1(Final)


    struct using_additive1 {
        template <typename Final, typename UT, typename Base>
        struct type : Base {
            BOOST_OPAQUE_ADDITIVE1(Final)
        };
    };

    template <class Final, class Base = base_new_type >
    struct additive1 : Base
    {
            BOOST_OPAQUE_ADDITIVE1(Final)
    };

    //~ template <class T, class U, class Base = base_new_type >
    //~ struct multiplicative2
        //~ : opaque::multipliable2<T, U
        //~ , opaque::dividable2<T, U, Base
          //~ > > {};

    #define BOOST_OPAQUE_MULTIPLICATIVE1(Final) \
        BOOST_OPAQUE_MULTIPLIABLE1(Final) \
        BOOST_OPAQUE_DIVIDABLE1(Final)


    struct using_multiplicative1 {
        template <typename Final, typename UT, typename Base>
        struct type : Base {
            BOOST_OPAQUE_MULTIPLICATIVE1(Final)
        };
    };
    
    template <class Final, class Base = base_new_type >
    struct multiplicative1 : Base
    {
            BOOST_OPAQUE_MULTIPLICATIVE1(Final)
    };

    //~ template <class T, class U, class Base = base_new_type >
    //~ struct integer_multiplicative2
        //~ : opaque::multiplicative2<T, U
        //~ , opaque::modable2<T, U, Base
          //~ > > {};

    template <class T, class Base = base_new_type >
    struct integer_multiplicative1
        : opaque::multiplicative1<T
        , opaque::modable1<T, Base
          > > {};

    //~ template <class T, class U, class Base = base_new_type >
    //~ struct arithmetic2
        //~ : opaque::additive2<T, U
        //~ , opaque::multiplicative2<T, U, Base
          //~ > > {};

    template <class T, class Base = base_new_type >
    struct arithmetic1
        : opaque::additive1<T
        , opaque::multiplicative1<T, Base
          > > {};

    //~ template <class T, class U, class Base = base_new_type >
    //~ struct integer_arithmetic2
        //~ : additive2<T, U
        //~ , integer_multiplicative2<T, U, Base
          //~ > > {};

    template <class T, class Base = base_new_type >
    struct integer_arithmetic1
        : opaque::additive1<T
        , opaque::integer_multiplicative1<T, Base
          > > {};

    //~ template <class T, class U, class Base = base_new_type >
    //~ struct bitwise2
        //~ : opaque::xorable2<T, U
        //~ , opaque::andable2<T, U
        //~ , opaque::orable2<T, U, Base
          //~ > > > {};

    template <class T, class Base = base_new_type >
    struct bitwise1
        : opaque::xorable1<T
        , opaque::andable1<T
        , opaque::orable1<T, Base
          > > > {};

    template <class T, class Base = base_new_type >
    struct unit_steppable
        : opaque::incrementable<T
        , opaque::decrementable<T, Base
          > > {};

    //~ template <class T, class U, class Base = base_new_type >
    //~ struct shiftable2
        //~ : opaque::left_shiftable2<T, U
        //~ , opaque::right_shiftable2<T, U, Base
          //~ > > {};

    template <class T, class Base = base_new_type >
    struct shiftable1
        : opaque::left_shiftable1<T
        , opaque::right_shiftable1<T, Base
          > > {};

    //~ template <class T, class U, class Base = base_new_type >
    //~ struct ring_operators2
        //~ : opaque::additive2<T, U
        //~ , opaque::subtractable2_left<T, U
        //~ , opaque::multipliable2<T, U, Base
          //~ > > > {};

    template <class T, class Base = base_new_type >
    struct ring_operators1
        : opaque::additive1<T
        , opaque::multipliable1<T, Base
          > > {};

    //~ template <class T, class U, class Base = base_new_type >
    //~ struct ordered_ring_operators2
        //~ : opaque::ring_operators2<T, U
        //~ , opaque::totally_ordered2<T, U, Base
          //~ > > {};

    template <class T, class UT, class Base = base_new_type >
    struct ordered_ring_operators1
        : opaque::ring_operators1<T
        , opaque::totally_ordered1<T, UT, Base
          > > {};

    //~ template <class T, class U, class Base = base_new_type >
    //~ struct field_operators2
        //~ : opaque::ring_operators2<T, U
        //~ , opaque::dividable2<T, U
        //~ , opaque::dividable2_left<T, U, Base
          //~ > > > {};

    template <class T, class Base = base_new_type >
    struct field_operators1
        : opaque::ring_operators1<T
        , opaque::dividable1<T, Base
          > > {};

    //~ template <class T, class U, class Base = base_new_type >
    //~ struct ordered_field_operators2
        //~ : opaque::field_operators2<T, U
        //~ , opaque::totally_ordered2<T, U, Base
          //~ > > {};

    template <class T, class UT, class Base = base_new_type >
    struct ordered_field_operators1
        : opaque::field_operators1<T
        , opaque::totally_ordered1<T, UT, Base
          > > {};



}
    template <typename T>
    struct inherited_from_undelying {
            template <typename Final, typename UT, typename Base>
            struct type :
                opaque::totally_ordered1< Final, T
                ,   opaque::integer_arithmetic1< Final
                    ,   boost::bitwise1< Final
                        ,   opaque::unit_steppable< Final
                            ,   opaque::ope::unary_plus< Final
                                ,   opaque::ope::unary_minus< Final
                                    ,   Base
                                    >
                                >
                            >
                        >
                    >
                >
            {};
    };
}


#endif
