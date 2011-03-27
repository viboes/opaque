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

#ifndef BOOST_OPAQUE_NEW_TYPE_HPP
#define BOOST_OPAQUE_NEW_TYPE_HPP

#include <boost/opaque/new_class.hpp>
#include <boost/mpl/vector.hpp>

namespace boost {
  namespace opaque {
    
    //! @c new_type<> provides the equivalent of @c new_class<> but can be used as a @c typedef.
    //!
    //! @Requires
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
      typename UT,
      typename Tag,
      typename MetaMixinSeq=boost::mpl::vector0<>,
      typename Base=base_opaque_type
    >
    class new_type
      : public new_class<new_type<UT, Tag, MetaMixinSeq, Base>, UT, MetaMixinSeq, Base>
    {
      typedef new_class<new_type<UT, Tag, MetaMixinSeq, Base>, UT, MetaMixinSeq, Base> base_type;
    public:
      //! default constructor
      new_type() {}
      //! copy constructor
      new_type(const new_type & rhs) : base_type(rhs.val_) {}
      //! explicit construction from the underlying type
      explicit new_type(UT v) : base_type(v) {}
      //! explicit construction from convertible to the underlying type
      template <typename W>
      explicit new_type(W v) : base_type(v) {}
      
    };
  }

  //! Conversion from a @c new_type<> to a type convertible from @c UT.

  //! @Requires
  //! @li @c Final must publicly inherit from opaque::new_class<Final, UT, MetaMixinSeq, Base>.
  //! @li @c UT must be <em>CopyConstructible</em> and <em>Assignable</em>.
  //! @li @c MetaMixinSeq must be a model of <em>MetaMixinSeq</em>.
  //! @li @c UT must be convertible to @c T.
  //! @li @c Base must inherit directly or indirectly from  @c base_opaque_type or be @c base_opaque_type.

  template <
    typename T,
    typename UT,
    typename Tag,
    typename MetaMixinSeq,
    typename Base
  >
  T opaque_static_cast(opaque::new_type<UT,Tag,MetaMixinSeq,Base> const& v)
  {
    return static_cast<T>(v.underlying());
  }
  
}


#endif
