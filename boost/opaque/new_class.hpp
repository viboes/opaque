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
 * @File Defines the new_class<> class.
 */


#ifndef BOOST_OPAQUE_NEW_CLASS_HPP
#define BOOST_OPAQUE_NEW_CLASS_HPP

#include <boost/opaque/meta_mixin/linear_hierarchy.hpp>
#include <boost/type_traits/is_class.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/push_front.hpp>

namespace boost {
  namespace opaque {

    namespace opaque_detail {

      template <typename T, bool B>
      struct build_undelying_type_hierarchy;

      template <typename T>
      struct build_undelying_type_hierarchy<T,true> {
        typedef typename mpl::push_front<typename T::undelying_type_hierarchy, T
            >::type type;
      };

      template <typename T>
      struct build_undelying_type_hierarchy<T,false> {
        typedef mpl::vector<T> type;
      };
    }
    //! base types for all the new opaque types, used to identify them
    struct base_opaque_type {};

    //! new_class<> wraps an underlying type providing the regular constructors and copy construction from the underlying type and all the convertibles to the the UT.
    //!
    //! @Requires
    //! @li @c Final must publicly inherit from this class to make it a model of <em>FinalUnderlying</em>
    //! @li @c UT must be <em>CopyConstructible</em> and <em>Assignable</em>.
    //! @li @c MetaMixinSeq must be a model of <em>MetaMixinSeq</em>.
    //! @li @c Base must inherit directly or indirectly from  @c base_opaque_type or be @c base_opaque_type.
    //!
    //! @Note
    //! @li Can instances of UT be explicitly converted to instances of OT? Yes, there is an explicit constructor.
    //! @li Can instances of convertible to UT be explicitly converted to instances of OT? Yes, there is an explicit constructor.
    //! @li Can instances of UT be implicitly converted to instances of OT? No, this is one of the main differentiating features of @c new_class.
    //! @li Can instances of OT be explicitly converted to instances of UT? Yes, there is an explicit conversion operator (if supported by the compiler) or the @c underlying function.
    //! @li Can instances of OT be implicitly converted to instances of UT? No, this is one of the main differentiating features of @c new_class.

    template <
      typename Final,
      typename UT,
      typename MetaMixinSeq=boost::mpl::vector0<>,
      typename Base=base_opaque_type
    >
    class new_class : public linear_hierarchy<MetaMixinSeq, Final, Base>::type
    {
    public:

      //! the underlying type
      //!
      typedef UT underlying_type;

      //! MPL sequence of type to which this type is convertible.
      typedef typename opaque_detail::build_undelying_type_hierarchy<UT,
        mpl::and_<
          is_class<UT>,
          is_base_of<base_opaque_type,UT>
        >::value
      >::type undelying_type_hierarchy;


      //! default constructor
      new_class() : val_() {}
      //! copy constructor
      new_class(const new_class & rhs) : val_(rhs.val_) {}
      //! explicit construction from the underlying type
      explicit new_class(UT v) : val_(v) {}
      //! explicit construction from convertible to the underlying type
      template <typename W>
      explicit new_class(W v) : val_(v) {}
    protected:
      //! the storage
      //!
      UT val_;

    public:
      //! explicit conversion to the underlying type.
      underlying_type const& underlying() const {
        return val_;
      }
      //! explicit conversion to the underlying type.
      underlying_type& underlying() {
        return val_;
      }
#if !defined(BOOST_NO_EXPLICIT_CONVERSION_OPERATORS)
      //! explicit conversion operator to the underlying type.
      //!
      //! @Remark Only provided when supported by the compiler.
      //! @Note the @explicit keyword doesn't appears in the documentation as doxygen doesn't generates it :(.
      explicit operator underlying_type const&() const {
        return val_;
      }
      //! explicit conversion operator to the underlying type.
      //!
      //! @Remark Only provided when supported by the compiler.
      //! @Note the @explicit keyword doesn't appears in the documentation as doxygen doesn't generates it :(.
      explicit operator underlying_type&() {
        return val_;
      }

#endif

      //! explicit conversion from a @c Final class to the underlying type.
      template<typename F>
      static underlying_type& underlying(F* f){
        return final(f).underlying();
      }

      //! explicit conversion from a <c>Final const</c> class to the underlying type.
      template<typename F>
      static underlying_type const& underlying(F const* f){
        return final(f).underlying();
      }

      //! explicit conversion from a base const class to the @c Final class.
      template<typename F>
      static Final const& final(F const* f)  {
        return static_cast<Final const&>(*f);
      }
      //! explicit conversion from a base class to the @c Final class.
      template<typename F>
      static Final& final(F* f) {
        return static_cast<Final&>(*f);
      }

    };
  }

  //! Conversion from a @c new_class<> to a type convertible from @c UT.

  //! @Requires
  //! @li @c Final must publicly inherit from opaque::new_class<Final, UT, MetaMixinSeq, Base>.
  //! @li @c UT must be <em>CopyConstructible</em> and <em>Assignable</em>.
  //! @li @c MetaMixinSeq must be a model of <em>MetaMixinSeq</em>.
  //! @li @c UT must be convertible to @c T.
  //! @li @c Base must inherit directly or indirectly from  @c base_opaque_type or be @c base_opaque_type.

  template <
    typename T,
    typename Final,
    typename UT,
    typename MetaMixinSeq,
    typename Base
  >
  T opaque_static_cast(opaque::new_class<Final, UT, MetaMixinSeq, Base> const& v)
  {
    return static_cast<T>(v.underlying());
  }

}


#endif
