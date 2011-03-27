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
 * Defines the @c public_opaque_type class.
 */

#ifndef BOOST_OPAQUE_PUBLIC_OPAQUE_TYPE_HPP
#define BOOST_OPAQUE_PUBLIC_OPAQUE_TYPE_HPP

//~ Can instances of UT be explicitly converted to instances of OT? Yes
//~ Can instances of UT be implicitly converted to instances of OT? No
//~ Can instances of OT be explicitly converted to instances of UT? Yes
//~ Can instances of OT be implicitly converted to instances of UT? Yes

#include <boost/opaque/public_opaque_class.hpp>

namespace boost {
  namespace opaque {

    //! @c public_opaque_type<> provides the equivalent of @c public_opaque_class<> but can be used as a @c typedef.
    //!
    //! @Requires
    //! @li @c UT must be <em>CopyConstructible</em>.
    //! @li @c MetaMixinSeq must be a model of <em>MetaMixinSeq</em>.
    //! @li @c Base must inherit directly or indirectly from  @c base_opaque_type or be @c base_opaque_type.
    //!
    //! @Note
    //! @li Can instances of UT be explicitly converted to instances of OT? Yes, there is an explicit constructor.
    //! @li Can instances of convertible to UT be explicitly converted to instances of OT? Yes, there is an explicit constructor.
    //! @li Can instances of UT be implicitly converted to instances of OT? No, this is one of the main differentiating features of @c new_class.
    //! @li Can instances of OT be explicitly converted to instances of UT? Yes, there is an explicit conversion operator (if supported by the compiler) or the @c underlying function.
    //! @li Can instances of OT be implicitly converted to instances of UT? Yes, this is one of the main differentiating features of @c public_opaque_type.
    template <
      typename T,
      typename Tag=void,
      typename Bool=bool,
      typename MetaMixinSeq=boost::mpl::vector0<>,
    typename Base=base_public_opaque_type
    >
    class public_opaque_type
    : public
      public_opaque_class< public_opaque_type<T,Tag,Bool,MetaMixinSeq,Base>,
          T, Bool, MetaMixinSeq, Base>
    {
      typedef
          public_opaque_class< public_opaque_type<T,Tag,Bool,MetaMixinSeq,Base>,
              T, Bool, MetaMixinSeq, Base> base_type;

    public:

      public_opaque_type() {}
      public_opaque_type(const public_opaque_type & rhs)
        : base_type(rhs.val_) {}
      //! explicit construction from the underlying type
      explicit public_opaque_type(T v)
        : base_type(v) {}
      //! explicit construction from convertible to the underlying type
      template <typename W>
      explicit public_opaque_type(W v)
      : base_type(v) {}

    };
  }
}


#endif
