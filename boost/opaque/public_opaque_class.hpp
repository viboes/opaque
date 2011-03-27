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
 * Defines the @c base_public_opaque_type and @c public_opaque_class classes.
 */

#ifndef BOOST_OPAQUE_PUBLIC_OPAQUE_CLASS_HPP
#define BOOST_OPAQUE_PUBLIC_OPAQUE_CLASS_HPP

#include <boost/opaque/meta_mixin/inherited_from_underlying.hpp>
#include <boost/opaque/meta_mixin/using_implicit_conversion_to_ut_hierarchy.hpp>


namespace boost {
  namespace opaque {

    //! base types for all the private_opaque_class, used to identify them.
    struct base_public_opaque_type : base_opaque_type {};

    //! public_opaque_class<> wraps an underlying type providing the regular
    //!  constructors and copy construction from the underlying type and all the
    //!  conversions to the the UT inheriting from all the underlying operations.
    //!
    //! @Requires
    //! @li @c Final must publicly inherit from this class.
    //! @li @c UT must be <em>CopyConstructible</em>.
    //! @li @c Bool must be a model of <em>Boolean</em>.
    //! @li @c MetaMixinSeq must be a model of <em>MetaMixinSeq</em>.
    //! @li @c Base must inherit directly or indirectly from  @c base_opaque_type or be @c base_opaque_type.
    //!
    //! @Note
    //! @li Can instances of UT be explicitly converted to instances of OT? Yes, there is an explicit constructor.
    //! @li Can instances of convertible to UT be explicitly converted to instances of OT? Yes, there is an explicit constructor.
    //! @li Can instances of UT be implicitly converted to instances of OT? No, this is one of the main differentiating features of opaque types.
    //! @li Can instances of OT be explicitly converted to instances of UT? Yes, there is an explicit conversion operator (if supported by the compiler) or the @c underlying function.
    //! @li Can instances of OT be implicitly converted to instances of UT? Yes, this is one of the main differentiating features of @c public_opaque_class.
    //!
    //! @c public_opaque_class<> is a @c new_class with the @c using_implicit_conversion_to_underlying_type_hierarchy<base_public_opaque_type>
    //! and @c inherited_from_underlying<UT> added to the sequence of meta-mixins @c MetaMixinSeq,
    //! so a @c public_opaque_type inherits from all the operations of the underlying type @c UT and
    //! adds implicit conversions to all the types in the underlying type hierarchy.
    template <
      typename Final,
      typename T,
      typename Bool=bool,
      typename MetaMixinSeq=boost::mpl::vector0<>,
      typename Base=base_public_opaque_type
    >
    class public_opaque_class
    : public
      new_class< Final, T,
        typename mpl::push_front<
          typename mpl::push_front<
            MetaMixinSeq,
            using_implicit_conversion_to_underlying_type_hierarchy<base_public_opaque_type, T>
          >::type,
          opaque::inherited_from_underlying<T,Bool>
        >::type, Base
      >

    {
      typedef
          new_class< Final, T,
            typename mpl::push_front<
              typename mpl::push_front<
                MetaMixinSeq,
                using_implicit_conversion_to_underlying_type_hierarchy<base_public_opaque_type, T>
              >::type,
              opaque::inherited_from_underlying<T,Bool>
            >::type, Base
          >
      base_type;

    public:
      public_opaque_class() {}
      public_opaque_class(const public_opaque_class & rhs)
        : base_type(rhs.val_){}
      public_opaque_class(const Final & rhs)
        : base_type(rhs.val_){}
      //! explicit construction from the underlying type
      explicit public_opaque_class(T v)
        : base_type(v) {}
      //! explicit construction from convertible to the underlying type
      template <typename W>
      explicit public_opaque_class(W v)
      : base_type(v) {}

    };
  }
}


#endif
