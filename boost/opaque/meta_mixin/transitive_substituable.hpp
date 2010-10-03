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

#ifndef BOOST_OPAQUE_TRANSITIVE_SUBSTITUABLE_HPP
#define BOOST_OPAQUE_TRANSITIVE_SUBSTITUABLE_HPP

#include <boost/type_traits/is_class.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/mpl/and.hpp>

namespace boost {

    template <typename BaseClass, typename UT>
    struct transitive_substituable;

    namespace detail {

    template <
    	typename BaseClass,
    	typename Final,
    	typename UT,
    	typename Base,
    	bool IsConvertible
    >
    struct transitive_substituable_next_level;

    template <
    	typename BaseClass,
    	typename Final,
    	typename UT,
    	typename Base
    >
    struct transitive_substituable_next_level<BaseClass, Final, UT, Base, true>
        :  transitive_substituable<BaseClass, typename UT::underlying_type>
    		::template type<Final, Base>
    { };

    template <typename BaseClass, typename Final, typename UT, typename Base>
    struct transitive_substituable_next_level<BaseClass, Final, UT, Base, false>
    	:  Base
    { };

    }

    template <typename BaseClass, typename UT>
    struct transitive_substituable {
        template <typename Final, typename Base>
        struct type
            : detail::transitive_substituable_next_level<
            		BaseClass, Final, UT, Base,
                    mpl::and_<is_class<UT>, is_base_of<BaseClass, UT>
            	>::value>
        {
            operator UT() const {
                    return Final::final(this).underlying();
            }
        };
    };

}

#endif
