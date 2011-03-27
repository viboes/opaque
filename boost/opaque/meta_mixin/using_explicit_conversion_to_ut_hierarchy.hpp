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

#include <boost/opaque/meta_mixin/combined_operators.hpp>

#include <boost/type_traits/is_class.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/mpl/and.hpp>
#include <boost/conversion/convert_to.hpp>

namespace boost {
  namespace opaque {

#if !defined(BOOST_OPAQUE_DOXYGEN_INVOKED)
    template <typename BaseClass, typename UT>
    struct using_explicit_conversion_to_underlying_type_hierarchy;

    namespace opaque_detail {

      template <
        typename BaseClass,
        typename Final,
        typename UT,
        typename Base,
        bool B>
      struct transitive_explicit_substituable_next_level;

      template <
        typename BaseClass,
        typename Final,
        typename UT,
        typename Base>
      struct transitive_explicit_substituable_next_level<BaseClass, Final, UT, Base, true>
      :  using_explicit_conversion_to_underlying_type_hierarchy<BaseClass, typename UT::underlying_type>
      ::template type<Final, Base>
      {};
      template <
        typename BaseClass,
        typename Final,
        typename UT,
        typename Base
      >
      struct transitive_explicit_substituable_next_level<BaseClass, Final, UT, Base, false>
      :  Base
         {};

    }
#endif

    //! mixin generating the explicit conversion to all the underlying types hierarchy.
    //! This meta-mixin provides the Final class explicit conversions for all the underlying types hierarchy
    //! (when the compiler supports explicit conversion operators).
    //! For portability purposed the library provide as workaround a @c convert_to non member function which follows the Boost.conversion protocol.
    template <typename BaseClass, typename UT>
    struct using_explicit_conversion_to_underlying_type_hierarchy {
      template <typename Final, typename Base>
      struct type
      : opaque_detail::transitive_explicit_substituable_next_level<BaseClass, Final, UT, Base,
        mpl::and_<is_class<UT>, is_base_of<BaseClass, UT> >::value>
      {
        friend UT convert_to(Final const& rhs,
            boost::dummy::type_tag<UT> const&)
        {
          return Final::final(&rhs).underlying();
        }
#if !defined(BOOST_NO_EXPLICIT_CONVERSION_OPERATORS)
        explicit operator UT() const
        {
          return Final::final(this).underlying();
        }
#endif
      };
    };

  }
}


#endif
