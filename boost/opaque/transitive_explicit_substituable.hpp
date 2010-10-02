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

#ifndef BOOST_OPAQUE_TRANSITIVE_EXPLICIT_SUBSTITUABLE_HPP
#define BOOST_OPAQUE_TRANSITIVE_EXPLICIT_SUBSTITUABLE_HPP

#include <boost/opaque/combined_operators.hpp>

#include <boost/type_traits/is_class.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/mpl/and.hpp>

namespace boost {


    template <typename BaseClass>
    struct transitive_explicit_substituable;
        
    namespace detail {

    template <typename BaseClass, typename Final, typename UT, typename Base, bool B>
    struct transitive_explicit_substituable_next_level;

    template <typename BaseClass, typename Final, typename UT, typename Base>
    struct transitive_explicit_substituable_next_level<BaseClass, Final, UT, Base, true>
        :  transitive_explicit_substituable<BaseClass>::template 
            type<Final, typename UT::underlying_type, Base> 
    {};
    template <typename BaseClass, typename Final, typename UT, typename Base>
    struct transitive_explicit_substituable_next_level<BaseClass, Final, UT, Base, false> 
        :  Base 
    {};

    }

    template <typename BaseClass>
    struct transitive_explicit_substituable {
        template <typename Final, typename UT, typename Base>
        struct type
    #if defined(BOOST_NO_EXPLICIT_CONVERSION_OPERATORS)
            : Base {};
    #else
            : detail::transitive_explicit_substituable_next_level<BaseClass, Final, UT, Base,
                    mpl::and_<is_class<UT>, is_base_of<BaseClass, UT> >::value>
        {
            explicit operator UT() const {
                    return Final::final(this).underlying();
            }
        };
    #endif
    };
    

}


#endif
