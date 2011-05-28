// Boost.TypeErasure library
//
// Copyright 2011 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id$

#ifndef BOOST_OPAQUE_PLACEHOLDER_HPP
#define BOOST_OPAQUE_PLACEHOLDER_HPP

// Base of the file type_erasure/placeholder.hpp even if the purpose is not the same.
namespace boost {
namespace opaque {

/** INTERNAL ONLY */
struct placeholder_base {};

/**
 * Placeholders are used heavily throughout the library.
 * Every placeholder must derive from @ref placeholder
 * using CRTP.  The library provides a number of placeholders,
 * out of the box, but you are welcome to define your own,
 * if you want more descriptive names.  The placeholder
 * @ref _self is special in that it is used as the default
 * wherever possible, and that it is used to place the Final template parameter.
 * There is also the _ut placeholder, which is used to mean the underlying type.
 *
 * What exactly is a placeholder?  Placeholders act as
 * a substitute for template parameters in meta-mixins.
 *
 * For example, in the following,
 *
 * @code
    template <typename T=_self, typename U=_self>
    struct lt;
    template <>
    struct lt<_self,_self>
    {
      template <typename Final, typename Base>
      struct type: Base
      {
        friend bool operator OP (Final const& lhs, Final const& rhs)
        {
          return lhs.underlying() OP rhs.underlying();
        }
      };
    };
    template <typename T>
    struct lt<T,_self>
    {
      template <typename Final, typename Base>
      struct type: Base
      {
        friend bool operator OP (T const& lhs, Final const& rhs)
        {
          return lhs OP rhs.underlying();
        }
      };
    };
    template <typename T>
    struct lt<_self,T>
    {
      template <typename Final, typename Base>
      struct type: Base
      {
        friend bool operator OP (Final const& lhs, T const& rhs)
        {
          return lhs.underlying() OP rhs;
        }
      };
    };
 * @endcode
 *
 */
template<class Derived>
struct placeholder : placeholder_base {};

struct _a : placeholder<_a> {};
struct _b : placeholder<_b> {};
struct _c : placeholder<_c> {};
struct _d : placeholder<_d> {};
struct _e : placeholder<_e> {};
struct _f : placeholder<_f> {};
struct _g : placeholder<_g> {};

/**
 * \brief The default placeholder
 *
 * @ref _self is the default @ref placeholder used
 * by meta-mixins.  It should be used as a default
 * by most meta-mixins, so using meta-mixins with no
 * explicit arguments will "just work" as much as
 * possible.
 */
struct _self : placeholder<_self> {};

}
}

#endif
