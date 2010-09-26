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

#include <boost/opaque/new_type.hpp>
#include <boost/operators.hpp>
#include <boost/opaque/operators.hpp>

namespace boost {

namespace opaque {

    template <typename Final, typename Base=base_new_type>
    struct equality_comparable1 : boost::equality_comparable1<Final, ope::equal<Final, Base> > {};

    template <typename Final, typename Base=base_new_type>
    struct less_than_comparable1 : boost::less_than_comparable1<Final, ope::less_than<Final, Base> > {};

    template <typename Final, typename Base=base_new_type>
    struct addable1 : boost::addable1<Final, ope::plus_assign<Final, Base> > {};

    template <typename Final, typename Base=base_new_type>
    struct subtractable1 : boost::subtractable1<Final, ope::minus_assign<Final, Base> > {};

    template <typename Final, typename Base=base_new_type>
    struct multipliable1 : boost::multipliable1<Final, ope::multiply_assign<Final, Base> > {};

    template <typename Final, typename Base=base_new_type>
    struct dividable1 : boost::dividable1<Final, ope::divide_assign<Final, Base> > {};

    template <typename Final, typename Base=base_new_type>
    struct modable1 : boost::modable1<Final, ope::modulus_assign<Final, Base> > {};

    template <typename Final, typename Base=base_new_type>
    struct xorable1 : boost::xorable1<Final, ope::bitwise_xor_assign<Final, Base> > {};

    template <typename Final, typename Base=base_new_type>
    struct andable1 : boost::andable1<Final, ope::bitwise_and_assign<Final, Base> > {};

    template <typename Final, typename Base=base_new_type>
    struct orable1 : boost::orable1<Final, ope::bitwise_or_assign<Final, Base> > {};

    template <typename Final, typename Base=base_new_type>
    struct incrementable : boost::incrementable<Final, ope::pre_increment<Final, Base> > {};

    template <typename Final, typename Base=base_new_type>
    struct decrementable : boost::decrementable<Final, ope::pre_decrement<Final, Base> > {};

    template <typename Final, typename Base=base_new_type>
    struct left_shiftable1 : boost::left_shiftable1<Final, ope::left_shift_assign<Final, Base> > {};

    template <typename Final, typename Base=base_new_type>
    struct right_shiftable1 : boost::right_shiftable1<Final, ope::right_shift_assign<Final, Base> > {};

    template <typename Final, typename Base=base_new_type>
    struct partially_ordered1 : boost::less_than_comparable1<Final, ope::less_than<Final, Base> > {};


    template <class T, class B = base_new_type >
    struct totally_ordered1
        : opaque::less_than_comparable1<T
        , opaque::equality_comparable1<T, B
          > > {};

    //~ template <class T, class U, class B = base_new_type >
    //~ struct additive2
        //~ : opaque::addable2<T, U
        //~ , opaque::subtractable2<T, U, B
          //~ > > {};

    template <class T, class B = base_new_type >
    struct additive1
        : opaque::addable1<T
        , opaque::subtractable1<T, B
          > > {};

    //~ template <class T, class U, class B = base_new_type >
    //~ struct multiplicative2
        //~ : opaque::multipliable2<T, U
        //~ , opaque::dividable2<T, U, B
          //~ > > {};

    template <class T, class B = base_new_type >
    struct multiplicative1
        : opaque::multipliable1<T
        , opaque::dividable1<T, B
          > > {};

    //~ template <class T, class U, class B = base_new_type >
    //~ struct integer_multiplicative2
        //~ : opaque::multiplicative2<T, U
        //~ , opaque::modable2<T, U, B
          //~ > > {};

    template <class T, class B = base_new_type >
    struct integer_multiplicative1
        : opaque::multiplicative1<T
        , opaque::modable1<T, B
          > > {};

    //~ template <class T, class U, class B = base_new_type >
    //~ struct arithmetic2
        //~ : opaque::additive2<T, U
        //~ , opaque::multiplicative2<T, U, B
          //~ > > {};

    template <class T, class B = base_new_type >
    struct arithmetic1
        : opaque::additive1<T
        , opaque::multiplicative1<T, B
          > > {};

    //~ template <class T, class U, class B = base_new_type >
    //~ struct integer_arithmetic2
        //~ : additive2<T, U
        //~ , integer_multiplicative2<T, U, B
          //~ > > {};

    template <class T, class B = base_new_type >
    struct integer_arithmetic1
        : opaque::additive1<T
        , opaque::integer_multiplicative1<T, B
          > > {};

    //~ template <class T, class U, class B = base_new_type >
    //~ struct bitwise2
        //~ : opaque::xorable2<T, U
        //~ , opaque::andable2<T, U
        //~ , opaque::orable2<T, U, B
          //~ > > > {};

    template <class T, class B = base_new_type >
    struct bitwise1
        : opaque::xorable1<T
        , opaque::andable1<T
        , opaque::orable1<T, B
          > > > {};

    template <class T, class B = base_new_type >
    struct unit_steppable
        : opaque::incrementable<T
        , opaque::decrementable<T, B
          > > {};

    //~ template <class T, class U, class B = base_new_type >
    //~ struct shiftable2
        //~ : opaque::left_shiftable2<T, U
        //~ , opaque::right_shiftable2<T, U, B
          //~ > > {};

    template <class T, class B = base_new_type >
    struct shiftable1
        : opaque::left_shiftable1<T
        , opaque::right_shiftable1<T, B
          > > {};

    //~ template <class T, class U, class B = base_new_type >
    //~ struct ring_operators2
        //~ : opaque::additive2<T, U
        //~ , opaque::subtractable2_left<T, U
        //~ , opaque::multipliable2<T, U, B
          //~ > > > {};

    template <class T, class B = base_new_type >
    struct ring_operators1
        : opaque::additive1<T
        , opaque::multipliable1<T, B
          > > {};

    //~ template <class T, class U, class B = base_new_type >
    //~ struct ordered_ring_operators2
        //~ : opaque::ring_operators2<T, U
        //~ , opaque::totally_ordered2<T, U, B
          //~ > > {};

    template <class T, class B = base_new_type >
    struct ordered_ring_operators1
        : opaque::ring_operators1<T
        , opaque::totally_ordered1<T, B
          > > {};

    //~ template <class T, class U, class B = base_new_type >
    //~ struct field_operators2
        //~ : opaque::ring_operators2<T, U
        //~ , opaque::dividable2<T, U
        //~ , opaque::dividable2_left<T, U, B
          //~ > > > {};

    template <class T, class B = base_new_type >
    struct field_operators1
        : opaque::ring_operators1<T
        , opaque::dividable1<T, B
          > > {};

    //~ template <class T, class U, class B = base_new_type >
    //~ struct ordered_field_operators2
        //~ : opaque::field_operators2<T, U
        //~ , opaque::totally_ordered2<T, U, B
          //~ > > {};

    template <class T, class B = base_new_type >
    struct ordered_field_operators1
        : opaque::field_operators1<T
        , opaque::totally_ordered1<T, B
          > > {};


}
}


#endif
