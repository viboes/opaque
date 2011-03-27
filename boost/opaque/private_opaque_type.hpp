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
 * Defines the @c private_opaque_type class.
 */

#ifndef BOOST_OPAQUE_PRIVATE_OPAQUE_TYPE_HPP
#define BOOST_OPAQUE_PRIVATE_OPAQUE_TYPE_HPP

#include <boost/opaque/private_opaque_class.hpp>

namespace boost {
  namespace opaque {


    //! @c private_opaque_type<> provides the equivalent of @c private_opaque_class<> but can be used as a @c typedef.
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
    //! @li Can instances of OT be implicitly converted to instances of UT? No, this is one of the main differentiating features of @c private_opaque_type.
    template <
      typename UT,
      typename Tag=void,
      typename Bool=bool,
      typename MetaMixinSeq=boost::mpl::vector0<>,
      typename Base=base_private_opaque_type
    >
    class private_opaque_type : public
      private_opaque_class< private_opaque_type<UT,Tag,Bool,MetaMixinSeq,Base>,
        UT, Bool, MetaMixinSeq, Base>
    {
      typedef
          private_opaque_class< private_opaque_type<UT,Tag,Bool,MetaMixinSeq,Base>,
            UT, Bool, MetaMixinSeq, Base>
      base_type;

    public:

      private_opaque_type() {};
      private_opaque_type(const private_opaque_type & rhs)
        : base_type(rhs.val_) {}
      //! explicit construction from the underlying type
      explicit private_opaque_type(UT v)
        : base_type(v) {};
      //! explicit construction from convertible to the underlying type
      template <typename W>
      explicit private_opaque_type(W v)
        : base_type(v)
      {}
    };
  }
}


#endif
