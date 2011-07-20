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
 * This file includes meta-mixins that are used to add an operator overload forwarding from the final type to the underlying type.
 *
 * There is a meta-mixin for each one of the C++ overloadable operators.
 * These meta-mixins have names that follows the naming used in <b>Boost.ConceptsTraits</b>, but prefixed by using_.
 *
 * See the section for a complete list of operators meta-mixins.
 */

/*
 * In this section the meta-mixin follows the schema
 * <b>Arithmetic Operators</b>
 *
 * The arithmetic meta-mixins ease the task of creating a custom numeric type based on the underlying type.
 * Given an underlying type, the templates add forward operators from the numeric class to the underlying type.
 * These operations are like the ones the standard arithmetic types have, and may include comparisons, adding,
 * incrementing, logical and bitwise manipulations, etc. Further, since most numeric types need more than one
 * of these operators, some templates are provided to combine several of the basic operator templates in one
 * declaration.
 *
 * The requirements for the types used to instantiate the simple operator templates are specified in terms of
 * expressions which must be valid and the expression's return type.
 *
 * These meta-mixins are "simple" since they provide an operator based on a single operation the underlying type
 * has to provide. They have an additional optional template parameter Base, which is not shown, for the base class
 * chaining technique.
 *
 * @code
 * struct meta-mixin {
 *   template <typename NT, typename Base>
 *   struct type: Base {
 *      // Supplied Operation
 *   };
 * };
 * @endcode
 *
 * - @c NT/NT2 is expected to satisfy the <em>FinalUnderlying</em> requirements.
 * - @c UT stands for @c NT::underlying_type.
 * - @c UT2 stands for @c NT2::underlying_type.
 * - @c this_ut is the instance @c UT reference obtained @c NT::underlying(this).
 * - @c lhs is a @c NT/NT2 const reference.
 * - @c rhs is a @c NT/NT2 const reference.
 * - @c lhs_ut is the instance @c UT reference obtained @c lhs.underlying().
 * - @c rhs_ut is the instance @c UT reference obtained @c rhs.underlying().
 *
 *
 */

#ifndef BOOST_OPAQUE_OPERATORS_HPP
#define BOOST_OPAQUE_OPERATORS_HPP
#if !defined(BOOST_OPAQUE_DOXYGEN_INVOKED)

#include <boost/config.hpp>
#include <boost/opaque/meta_mixin/placeholder.hpp>
#if !defined(BOOST_OPAQUE_NOT_DEPENDS_ON_CONVERSION)
#include <boost/conversion/explicit_convert_to.hpp>
#endif

#define BOOST_NO_EXPLICIT_CONVERSION_OPERATORS_BUG

namespace boost {
  namespace opaque {


#define BOOST_OPAQUE_INTERNAL_NAME(NAME) \
    BOOST_JOIN(BOOST_JOIN(boost_opaque_internal_,NAME),_op)

//////////////////////////////////////////////////////////////////////////////

    #define BOOST_OPAQUE_HIDING_COPY_CONSTRUCTOR(T) \
        private:  \
            T( const T& );

    //!
    struct hiding_copy_constructor {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_HIDING_COPY_CONSTRUCTOR(type)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_HIDING_ASSIGNEMENT(T) \
        private: \
            T& operator=(T const&);

    struct hiding_assignment {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_HIDING_ASSIGNEMENT(type)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_CONVERSION_TO_UNDERLYING_TYPE(Final,UT) \
    public: \
            operator UT() const{ \
                return Final::underlying(this); \
            }
    /**
     * Adds the implicit conversion operator to the underlying type.
     *
     */
    template <typename UT>
    struct using_conversion_to_underlying_type {
        template <typename Final, typename Base>
        struct type: Base {
          BOOST_OPAQUE_USING_CONVERSION_TO_UNDERLYING_TYPE(Final,UT)
        };
    };

//////////////////////////////////////////////////////////////////////////////


    template <typename T>
    struct using_conversion_to {
        template <typename Final, typename Base>
        struct type: Base {
            operator T() const {
                return T(Final::underlying(this));
            }
        };
    };

//////////////////////////////////////////////////////////////////////////////

    template <typename T>
    struct using_explicit_conversion_to {
        template <typename Final, typename Base>
        struct type: Base {
#if !defined(BOOST_OPAQUE_NOT_DEPENDS_ON_CONVERSION) || defined(BOOST_OPAQUE_DOXYGEN_INVOKED)
            friend T explicit_convert_to(Final const& rhs,
                boost::dummy::type_tag<T> const&)
            {
              return T(Final::underlying(rhs));
            }
#endif
    #if !defined(BOOST_NO_EXPLICIT_CONVERSION_OPERATORS) || defined(BOOST_OPAQUE_DOXYGEN_INVOKED)
            explicit operator T() const
            {
              return T(Final::underlying(this));
            }
    #endif
        };
    };

//////////////////////////////////////////////////////////////////////////////

    struct using_safe_bool_conversion {
        template <typename Final, typename Base>
        struct type: Base {
            typedef typename Final::underlying_type const& (Final::*unspecified_bool_type)() const;

            operator unspecified_bool_type() const
            {
                return Final::underlying(this) ? &Final::underlying : 0;
            }
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_DCL_META_MIXIN_REL2(OP, NAME) \
    template <typename Bool=bool, typename T=_self, typename U=_self> \
    struct BOOST_JOIN(using_,NAME); \
    template <typename Bool=bool, typename T=_self, typename U=_self> \
    struct BOOST_JOIN(hiding_,NAME); \
    template <typename Bool> \
    struct BOOST_JOIN(using_,NAME)<Bool, _self, _self> \
    { \
      template <typename Final, typename Base> \
      struct type: Base \
      { \
      protected:\
        static Bool BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const Final& rhs)  \
        { \
          return Bool(lhs.underlying() OP rhs.underlying()); \
        } \
      public: \
        friend bool operator OP (Final const& lhs, Final const& rhs)  \
        { \
          return Final::BOOST_OPAQUE_INTERNAL_NAME(NAME)(lhs, rhs);\
        } \
      }; \
    }; \
    template <typename Bool> \
    struct BOOST_JOIN(hiding_,NAME)<Bool, _self, _self> \
    { \
      template <typename Final, typename Base> \
      struct type: Base \
      { \
      private:\
        static Bool BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const Final& rhs); \
      }; \
    }; \
    template <typename Bool, typename T> \
    struct BOOST_JOIN(using_,NAME)<Bool, T, _self> \
    { \
      template <typename Final, typename Base> \
      struct type: Base \
      { \
      protected:\
        static Bool BOOST_OPAQUE_INTERNAL_NAME(NAME) (const T& lhs, const Final& rhs)  \
        { \
          return Bool(lhs OP rhs.underlying()); \
        } \
      public: \
        friend bool operator OP (T const& lhs, Final const& rhs)  \
        { \
          return Final::BOOST_OPAQUE_INTERNAL_NAME(NAME)(lhs, rhs);\
        } \
      }; \
    }; \
    template <typename Bool, typename T> \
    struct BOOST_JOIN(hiding_,NAME)<Bool, T, _self> \
    { \
      template <typename Final, typename Base> \
      struct type: Base \
      { \
      private:\
        static Bool BOOST_OPAQUE_INTERNAL_NAME(NAME) (const T& lhs, const Final& rhs); \
      }; \
    }; \
    template <typename Bool, typename T> \
    struct BOOST_JOIN(using_,NAME)<Bool, _self, T> \
    { \
      template <typename Final, typename Base> \
      struct type: Base \
      { \
      protected:\
        static Bool BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const T& rhs)  \
        { \
          return Bool(lhs.underlying() OP rhs); \
        } \
      public: \
        friend bool operator OP (Final const& lhs, T const& rhs) \
        { \
          return Final::BOOST_OPAQUE_INTERNAL_NAME(NAME)(lhs, rhs);\
        } \
      }; \
    }; \
    template <typename Bool, typename T> \
    struct BOOST_JOIN(hiding_,NAME)<Bool, _self, T > \
    { \
      template <typename Final, typename Base> \
      struct type: Base \
      { \
      private:\
        static Bool BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const T& rhs); \
      }; \
    }; \
    \


#define BOOST_OPAQUE_DCL_META_MIXIN_REL1(OP, NAME) \
    template <typename Bool=bool> \
    struct BOOST_JOIN(using_,NAME) \
    { \
      template <typename Final, typename Base> \
      struct type: Base \
      { \
        Bool operator OP (const Final& rhs) const \
        { \
          return Bool(Final::underlying(this) OP rhs.underlying()); \
        } \
      }; \
    }; \
    template <typename Bool=bool> \
    struct BOOST_JOIN(hiding_,NAME) \
    { \
      template <typename Final, typename Base> \
      struct type: Base \
      { \
      private :\
        Bool operator OP (const Final& rhs) const; \
      }; \
    }; \
    template <typename Bool=bool> \
    struct BOOST_JOIN(BOOST_JOIN(using_,NAME),2) \
    { \
      template <typename Final, typename Base> \
      struct type: Base \
      { \
      private:\
        template <typename U> \
        static Bool BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const U& rhs)  \
        { \
          return Bool(lhs.underlying() OP rhs);\
        } \
        template <typename U> \
        static Bool BOOST_OPAQUE_INTERNAL_NAME(NAME) (const U& lhs, const Final& rhs)   \
        { \
          return Bool(lhs OP rhs.underlying());\
        } \
      public:\
        template <typename U> \
        friend Bool operator OP (const Final& lhs, const U& rhs)  \
        { \
          return Final::BOOST_OPAQUE_INTERNAL_NAME(NAME)(lhs, rhs);\
        } \
        template <typename U> \
        friend Bool operator OP (const U& lhs, const Final& rhs)   \
        { \
          return Final::BOOST_OPAQUE_INTERNAL_NAME(NAME)(lhs, rhs);\
        } \
      }; \
    }; \
    template <typename Bool=bool> \
    struct BOOST_JOIN(BOOST_JOIN(hiding,NAME),2)  \
    { \
        template <typename Final, typename Base> \
        struct type: Base \
        { \
        private :\
          template <typename U> \
          static Bool BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const U& rhs);  \
          template <typename U> \
          static Bool BOOST_OPAQUE_INTERNAL_NAME(NAME) (const U& lhs, const Final& rhs);   \
        }; \
    }; \


#define BOOST_OPAQUE_DCL_META_MIXIN_REL(OP, NAME) \
    BOOST_OPAQUE_DCL_META_MIXIN_REL2(OP,NAME)

#define BOOST_OPAQUE_USING_REL_OP(Final, Bool, OP) \
        Bool operator OP(const Final& rhs) const  { \
            return Bool(Final::underlying(this) OP rhs.underlying());\
        }

#define BOOST_OPAQUE_HIDING_REL_OP(Final, Bool, OP) \
    private :\
        Bool operator OP(const Final& rhs) const;\
    public :

#define BOOST_OPAQUE_USING_REL_OP2(Final, Bool, OP) \
    template <typename U> \
    friend Bool operator OP (const Final& lhs, const U& rhs)  \
    { \
      return Bool(lhs.underlying() OP rhs);\
    } \
    template <typename U> \
    friend Bool operator OP (const U& lhs, const Final& rhs)   \
    { \
      return Bool(lhs OP rhs.underlying());\
    }

#define BOOST_OPAQUE_HIDING_REL_OP2(Final, Bool, OP) \
    private :\
      template <typename U> \
      friend Bool operator OP (const Final& lhs, const U& rhs);  \
      template <typename U> \
      friend Bool operator OP (const U& lhs, const Final& rhs);   \
    public :

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_DCL_META_MIXIN_BINARY1(OP, NAME) \
    struct BOOST_JOIN(using_,NAME) \
    { \
      template <typename Final, typename Base> \
      struct type: Base \
      { \
      private:\
        static Final BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const Final& rhs)  \
        { \
          return Final(lhs.underlying() OP rhs.underlying());\
        } \
      public:\
        friend Final operator OP (const Final& lhs, const Final& rhs)  \
        { \
          return Final::BOOST_OPAQUE_INTERNAL_NAME(NAME)(lhs, rhs);\
        } \
      }; \
    }; \
    struct BOOST_JOIN(hiding_,NAME) \
    { \
      template <typename Final, typename Base> \
      struct type: Base \
      { \
      private :\
        static Final BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const Final& rhs);  \
      }; \
    }; \
    template <typename U> \
    struct BOOST_JOIN(BOOST_JOIN(using_,NAME),2) \
    { \
      template <typename Final, typename Base> \
      struct type: Base \
      { \
      private:\
        static Final BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const U& rhs)  \
        { \
          return Final(lhs.underlying() OP rhs);\
        } \
        static Final BOOST_OPAQUE_INTERNAL_NAME(NAME) (const U& lhs, const Final& rhs)   \
        { \
          return Final(lhs OP rhs.underlying());\
        } \
      public:\
        friend Final operator OP (const Final& lhs, const U& rhs)  \
        { \
          return Final::BOOST_OPAQUE_INTERNAL_NAME(NAME)(lhs, rhs);\
        } \
        friend Final operator OP (const U& lhs, const Final& rhs)   \
        { \
          return Final::BOOST_OPAQUE_INTERNAL_NAME(NAME)(lhs, rhs);\
        } \
      }; \
    }; \
    template <typename U> \
    struct BOOST_JOIN(BOOST_JOIN(hiding,NAME),2)  \
    { \
        template <typename Final, typename Base> \
        struct type: Base \
        { \
        private :\
          static Final BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const U& rhs);  \
          static Final BOOST_OPAQUE_INTERNAL_NAME(NAME) (const U& lhs, const Final& rhs);   \
        }; \
    }; \

#define BOOST_OPAQUE_DCL_META_MIXIN_BINARY(OP, NAME) \
  BOOST_OPAQUE_DCL_META_MIXIN_BINARY1(OP, NAME)

#define BOOST_OPAQUE_USING_BINARY_OP(Final, OP, NAME) \
    private:\
      static Final BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const Final& rhs)  \
      { \
        return Final(lhs.underlying() OP rhs.underlying());\
      } \
    public:\
      friend Final operator OP (const Final& lhs, const Final& rhs)  \
      { \
        return Final::BOOST_OPAQUE_INTERNAL_NAME(NAME)(lhs, rhs);\
      } \

#define BOOST_OPAQUE_HIDING_BINARY_OP(Final, OP, NAME) \
    private :\
      static Final BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const Final& rhs);  \
    public :

#define BOOST_OPAQUE_USING_BINARY_OP2(Final, OP, NAME) \
    private:\
      template <typename U> \
      static Final BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const U& rhs)  \
      { \
        return Final(lhs.underlying() OP rhs);\
      } \
      template <typename U> \
      static Final BOOST_OPAQUE_INTERNAL_NAME(NAME) (const U& lhs, const Final& rhs)   \
      { \
        return Final(lhs OP rhs.underlying());\
      } \
    public:\
      template <typename U> \
      friend Final operator OP (const Final& lhs, const U& rhs)  \
      { \
        return Final::BOOST_OPAQUE_INTERNAL_NAME(NAME)(lhs, rhs);\
      } \
      template <typename U> \
      friend Final operator OP (const U& lhs, const Final& rhs)   \
      { \
        return Final::BOOST_OPAQUE_INTERNAL_NAME(NAME)(lhs, rhs);\
      } \

#define BOOST_OPAQUE_HIDING_BINARY_OP2(Final, OP, NAME) \
    private :\
      template <typename U> \
      static Final BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const U& rhs);  \
      template <typename U> \
      static Final BOOST_OPAQUE_INTERNAL_NAME(NAME) (const U& lhs, const Final& rhs);   \
    public :

//////////////////////////////////////////////////////////////////////////////


    #define BOOST_OPAQUE_DCL_META_MIXIN_BINARY_EX(OP, NAME) \
        struct BOOST_JOIN(using_,NAME) \
        { \
          template <typename Final, typename Base> \
          struct type: Base \
          { \
          private:\
          template <typename U> \
            static Final BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const U& rhs)  \
            { \
              return Final(lhs.underlying() OP rhs);\
            } \
          public:\
          template <typename U> \
            friend Final operator OP (const Final& lhs, const U& rhs)  \
            { \
              return Final::BOOST_OPAQUE_INTERNAL_NAME(NAME)(lhs, rhs);\
            } \
          }; \
        }; \
        struct BOOST_JOIN(BOOST_JOIN(hiding,NAME),2)  \
        { \
            template <typename Final, typename Base> \
            struct type: Base \
            { \
            private :\
            template <typename U> \
              static Final BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const U& rhs);  \
            }; \
        }; \


    #define BOOST_OPAQUE_USING_BINARY_OP_EX(Final, OP, NAME) \
        private:\
        template <typename U> \
          static Final BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const U& rhs)  \
          { \
            return Final(lhs.underlying() OP rhs);\
          } \
        public:\
        template <typename U> \
          friend Final operator OP (const Final& lhs, const U& rhs)  \
          { \
            return Final::BOOST_OPAQUE_INTERNAL_NAME(NAME)(lhs, rhs);\
          } \

    #define BOOST_OPAQUE_HIDING_BINARY_OP_EX(Final, OP, NAME) \
        private :\
        template <typename U> \
          static Final BOOST_OPAQUE_INTERNAL_NAME(NAME) (const Final& lhs, const U& rhs);  \
        public :

/////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_LESS_THAN(Final, Bool) \
    BOOST_OPAQUE_USING_REL_OP(Final, Bool, <)

#define BOOST_OPAQUE_HIDING_LESS_THAN(Final, Bool) \
    BOOST_OPAQUE_HIDING_REL_OP(Final, Bool, <)

#define BOOST_OPAQUE_USING_LESS_THAN2(Final, Bool) \
    BOOST_OPAQUE_USING_REL_OP2(Final, Bool, <)

#define BOOST_OPAQUE_HIDING_LESS_THAN2(Final, Bool) \
    BOOST_OPAQUE_HIDING_REL_OP2(Final, Bool, <)

BOOST_OPAQUE_DCL_META_MIXIN_REL(<, less_than)


//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_LESS_THAN_EQUAL(Final, Bool) \
    BOOST_OPAQUE_USING_REL_OP(Final, Bool, <=)

#define BOOST_OPAQUE_HIDING_LESS_THAN_EQUAL(Final, Bool) \
    BOOST_OPAQUE_HIDING_REL_OP(Final, Bool, <=)

#define BOOST_OPAQUE_USING_LESS_THAN_EQUAL2(Final, Bool) \
    BOOST_OPAQUE_USING_REL_OP2(Final, Bool, <=)

#define BOOST_OPAQUE_HIDING_LESS_THAN_EQUAL2(Final, Bool) \
    BOOST_OPAQUE_HIDING_REL_OP2(Final, Bool, <=)

BOOST_OPAQUE_DCL_META_MIXIN_REL(<=, less_than_equal)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_GREATER_THAN(Final, Bool) \
    BOOST_OPAQUE_USING_REL_OP(Final, Bool, >)

#define BOOST_OPAQUE_HIDING_GREATER_THAN(Final, Bool) \
    BOOST_OPAQUE_HIDING_REL_OP(Final, Bool, >)

#define BOOST_OPAQUE_USING_GREATER_THAN2(Final, Bool) \
    BOOST_OPAQUE_USING_REL_OP2(Final, Bool, >)

#define BOOST_OPAQUE_HIDING_GREATER_THAN2(Final, Bool) \
    BOOST_OPAQUE_HIDING_REL_OP2(Final, Bool, >)

BOOST_OPAQUE_DCL_META_MIXIN_REL(>, greater_than)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_GREATER_THAN_EQUAL(Final, Bool) \
    BOOST_OPAQUE_USING_REL_OP(Final, Bool, >=)

#define BOOST_OPAQUE_HIDING_GREATER_THAN_EQUAL(Final, Bool) \
    BOOST_OPAQUE_HIDING_REL_OP(Final, Bool, >=)

#define BOOST_OPAQUE_USING_GREATER_THAN_EQUAL2(Final, Bool) \
    BOOST_OPAQUE_USING_REL_OP2(Final, Bool, >=)

#define BOOST_OPAQUE_HIDING_GREATER_THAN_EQUAL2(Final, Bool) \
    BOOST_OPAQUE_HIDING_REL_OP2(Final, Bool, >=)

BOOST_OPAQUE_DCL_META_MIXIN_REL(>=, greater_than_equal)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_EQUAL(Final, Bool) \
    BOOST_OPAQUE_USING_REL_OP(Final, Bool, ==)

#define BOOST_OPAQUE_HIDING_EQUAL(Final, Bool) \
    BOOST_OPAQUE_HIDING_REL_OP(Final, Bool, ==)

#define BOOST_OPAQUE_USING_EQUAL2(Final, Bool) \
    BOOST_OPAQUE_USING_REL_OP2(Final, Bool, ==)

#define BOOST_OPAQUE_HIDING_EQUAL2(Final, Bool) \
    BOOST_OPAQUE_HIDING_REL_OP2(Final, Bool, ==)

BOOST_OPAQUE_DCL_META_MIXIN_REL(==, equal)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_NOT_EQUAL(Final, Bool) \
    BOOST_OPAQUE_USING_REL_OP(Final, Bool, !=)

#define BOOST_OPAQUE_HIDING_NOT_EQUAL(Final, Bool) \
    BOOST_OPAQUE_HIDING_REL_OP(Final, Bool, !=)

#define BOOST_OPAQUE_USING_NOT_EQUAL2(Final, Bool) \
    BOOST_OPAQUE_USING_REL_OP2(Final, Bool, !=)

#define BOOST_OPAQUE_HIDING_NOT_EQUAL2(Final, Bool) \
    BOOST_OPAQUE_HIDING_REL_OP2(Final, Bool, !=)

BOOST_OPAQUE_DCL_META_MIXIN_REL(!=, not_equal)

//////////////////////////////////////////////////////////////////////////////


#define BOOST_OPAQUE_DCL_META_MIXIN_ASSIGN(OP, NAME) \
    struct BOOST_JOIN(using_,NAME) { \
        template <typename Final, typename Base> \
        struct type: Base { \
          Final&  operator OP (const Final& rhs) { \
               Final::underlying(this) OP rhs.underlying();\
               return Final::final(this); \
          } \
        }; \
    }; \
    struct BOOST_JOIN(hiding_,NAME) \
    { \
        template <typename Final, typename Base> \
        struct type: Base { \
        private :\
            Final&  operator OP(const Final& rhs); \
        }; \
    };

#define BOOST_OPAQUE_USING_OP_ASSIGN(Final,OP) \
    public :\
        Final&  operator OP(const Final& rhs) { \
            Final::underlying(this) OP rhs.underlying();\
            return Final::final(this); \
        }

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_PLUS_ASSIGN(Final) \
    BOOST_OPAQUE_USING_OP_ASSIGN(Final,+=)

BOOST_OPAQUE_DCL_META_MIXIN_ASSIGN(+=, plus_assign)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_MINUS_ASSIGN(Final) \
    BOOST_OPAQUE_USING_OP_ASSIGN(Final, -=)

BOOST_OPAQUE_DCL_META_MIXIN_ASSIGN(-=, minus_assign)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_MULTIPLY_ASSIGN(Final) \
    BOOST_OPAQUE_USING_OP_ASSIGN(Final, *=)

BOOST_OPAQUE_DCL_META_MIXIN_ASSIGN(*=, multiply_assign)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_DIVIDE_ASSIGN(Final) \
    BOOST_OPAQUE_USING_OP_ASSIGN(Final, /=)

BOOST_OPAQUE_DCL_META_MIXIN_ASSIGN(/=, divide_assign)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_MODULUS_ASSIGN(Final) \
    BOOST_OPAQUE_USING_OP_ASSIGN(Final, %=)

BOOST_OPAQUE_DCL_META_MIXIN_ASSIGN(%=, modulus_assign)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_BITWISE_XOR_ASSIGN(Final) \
    BOOST_OPAQUE_USING_OP_ASSIGN(Final, ^=)

BOOST_OPAQUE_DCL_META_MIXIN_ASSIGN(^=, bitwise_xor_assign)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_BITWISE_AND_ASSIGN(Final) \
    BOOST_OPAQUE_USING_OP_ASSIGN(Final, &=)

BOOST_OPAQUE_DCL_META_MIXIN_ASSIGN(&=, bitwise_and_assign)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_BITWISE_OR_ASSIGN(Final) \
    BOOST_OPAQUE_USING_OP_ASSIGN(Final, |=)

BOOST_OPAQUE_DCL_META_MIXIN_ASSIGN(|=, bitwise_or_assign)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_LEFT_SHIFT_ASSIGN(Final) \
    BOOST_OPAQUE_USING_OP_ASSIGN(Final, <<=)

BOOST_OPAQUE_DCL_META_MIXIN_ASSIGN(<<=, left_shift_assign)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_RIGHT_SHIFT_ASSIGN(Final) \
    BOOST_OPAQUE_USING_OP_ASSIGN(Final, >>=)

BOOST_OPAQUE_DCL_META_MIXIN_ASSIGN(>>=, right_shift_assign)

// Unary operators

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_LOGICAL_NOT(Final,Bool) \
    public :\
        Bool operator!() const  { \
            return Bool(!Final::underlying(this));\
        }

    template <typename Bool=bool>
    struct using_logical_not {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_LOGICAL_NOT(Final,Bool)
        };
    };
    template <typename Bool=bool>
    struct hiding_logical_not {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Bool operator!() const;
        };
    };

//////////////////////////////////////////////////////////////////////////////
#define BOOST_OPAQUE_USING_LOGICAL_AND(Final,Bool) \
    public :\
        Bool operator&&(const Final& rhs) const  { \
            return Bool(Final::underlying(this) && rhs.underlying());\
        }

    template <typename Bool=bool>
    struct using_logical_and {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_LOGICAL_AND(Final,Bool)
        };
    };
    template <typename Bool=bool>
    struct hiding_logical_and {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Bool operator&&(const Final& rhs) const;
        };
    };

//////////////////////////////////////////////////////////////////////////////
#define BOOST_OPAQUE_USING_LOGICAL_OR(Final,Bool) \
    public :\
        Bool operator||(const Final& rhs) const  { \
            return Bool(Final::underlying(this) || rhs.underlying());\
        }

    template <typename Bool=bool>
    struct using_logical_or {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_LOGICAL_OR(Final,Bool)
        };
    };
    template <typename Bool=bool>
    struct hiding_logical_or {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Bool operator||(const Final& rhs) const;
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_UNARY_PLUS(Final) \
    public :\
        Final operator+() const  { \
            return Final(+(Final::underlying(this)));\
        }

    struct using_unary_plus {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_UNARY_PLUS(Final)
        };
    };
    struct hiding_unary_plus {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Final operator+() const;
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_UNARY_MINUS(Final) \
    public :\
        Final operator-() const { \
            return Final(-(Final::underlying(this))); \
        }

    struct using_unary_minus {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_UNARY_MINUS(Final)
        };
    };
    struct hiding_unary_minus {
        template <typename Final, typename Base>
        struct type: Base {
        private :\
            Final operator-() const;
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_BITWISE_NOT(Final) \
    public :\
        Final operator~() const { \
            return Final(~(Final::underlying(this))); \
        }

    struct using_bitwise_not {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_BITWISE_NOT(Final)
        };
    };
    struct hiding_bitwise_not {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Final operator~() const;
        };
    };

//////////////////////////////////////////////////////////////////////////////

template <typename Final, typename Address, typename Base>
struct using_address_of : Base {
    Address operator&()  {
        return Address(&(Final::underlying(this)));
    }
};

//////////////////////////////////////////////////////////////////////////////

template <typename Final, typename Reference, typename Base>
struct using_derreference : Base {
    Reference operator*()  {
        return Reference(*(Final::underlying(this)));
    }
};

//////////////////////////////////////////////////////////////////////////////

template <typename Final, typename Pointer, typename Base>
struct using_member_access : Base {
    Pointer operator->()  {
        return Final::underlying(this).operator->();
    }
};

//////////////////////////////////////////////////////////////////////////////

template <typename Final, class I, class R, typename Base>
struct using_subscript : Base {
    R operator[](I n)  {
        return Final::underlying(this)[n];
    }
};

//////////////////////////////////////////////////////////////////////////////

template <typename Final, class RHS, class R, typename Base>
struct using_comma : Base {
    R operator,(RHS rhs)  {
        return (Final::underlying(this),rhs);
    }
};

//////////////////////////////////////////////////////////////////////////////

template <typename Final, class Sig, typename Base>
struct using_function_call;

template <typename Final, class R, typename Base>
struct using_function_call<Final, R(), Base> : Base {
    R operator()()  {
        return Final::underlying(this)();
    }
};

template <typename Final, class R, class P1, typename Base>
struct using_function_call<Final, R(P1), Base> : Base {
    R operator()(P1 p1)  {
        return Final::underlying(this)(p1);
    }
};

//////////////////////////////////////////////////////////////////////////////

// As the NT is not related to the UT by derivation, we can not overload the
// operator ->* with a pointer to a member of the UT.
// The user will need to define a specific member function

//template <typename Final, class PTM, class R, typename Base>
//struct using_pointer_to_member : Base {
//    R operator->*(PTM m)  {
//        return Final::underlying(this)->*m;
//    }
//};



// Increment and decrement
//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_PRE_INCREMENT(Final) \
    public :\
        Final& operator++()  { \
            ++Final::underlying(this); \
            return Final::final(this); \
        }

    struct using_pre_increment {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_PRE_INCREMENT(Final)
        };
    };
    struct hiding_pre_increment {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Final& operator++();
        };
    };


//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_PRE_DECREMENT(Final) \
    public :\
        Final& operator--()  { \
            --Final::underlying(this); \
            return Final::final(this); \
        }

    struct using_pre_decrement {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_PRE_DECREMENT(Final)
        };
    };
    struct hiding_pre_decrement {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Final& operator--();
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_POST_INCREMENT(Final) \
    public :\
        Final operator++(int)  { \
            Final nrv(Final::final(this)); \
            Final::underlying(this)++; \
            return nrv; \
        }

    struct using_post_increment {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_POST_INCREMENT(Final)
        };
    };
    struct hiding_post_increment {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Final operator++(int);
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_POST_DECREMENT(Final) \
    public :\
        Final operator--(int)  { \
            Final nrv(Final::final(this)); \
            Final::underlying(this)--; \
            return nrv; \
        }

    struct using_post_decrement {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_POST_DECREMENT(Final)
        };
    };
    struct hiding_post_decrement {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Final operator--(int);
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_PLUS(Final) \
    BOOST_OPAQUE_USING_BINARY_OP(Final, +, plus)

#define BOOST_OPAQUE_HIDING_PLUS(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP(Final, +, plus)

#define BOOST_OPAQUE_USING_PLUS2(Final) \
    BOOST_OPAQUE_USING_BINARY_OP2(Final, +, plus)

#define BOOST_OPAQUE_HIDING_PLUS2(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP2(Final, +, plus)

BOOST_OPAQUE_DCL_META_MIXIN_BINARY(+, plus)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_MINUS(Final) \
    BOOST_OPAQUE_USING_BINARY_OP(Final, -, minus)

#define BOOST_OPAQUE_HIDING_MINUS(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP(Final, -, minus)

#define BOOST_OPAQUE_USING_MINUS2(Final) \
    BOOST_OPAQUE_USING_BINARY_OP2(Final, -, minus)

#define BOOST_OPAQUE_HIDING_MINUS2(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP2(Final, -, minus)

BOOST_OPAQUE_DCL_META_MIXIN_BINARY(-, minus)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_MULTIPLY(Final) \
    BOOST_OPAQUE_USING_BINARY_OP(Final, *, multiply)

#define BOOST_OPAQUE_HIDING_MULTIPLY(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP(Final, *, multiply)

#define BOOST_OPAQUE_USING_MULTIPLY2(Final) \
    BOOST_OPAQUE_USING_BINARY_OP2(Final, *, multiply)

#define BOOST_OPAQUE_HIDING_MULTIPLY2(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP2(Final, *, multiply)

BOOST_OPAQUE_DCL_META_MIXIN_BINARY(*, multiply)


//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_DIVIDE(Final) \
    BOOST_OPAQUE_USING_BINARY_OP(Final, /, divide)

#define BOOST_OPAQUE_HIDING_DIVIDE(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP(Final, /, divide)

#define BOOST_OPAQUE_USING_DIVIDE2(Final) \
    BOOST_OPAQUE_USING_BINARY_OP2(Final, /, divide)

#define BOOST_OPAQUE_HIDING_DIVIDE2(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP2(Final, /, divide)

BOOST_OPAQUE_DCL_META_MIXIN_BINARY(/, divide)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_MODULUS(Final) \
    BOOST_OPAQUE_USING_BINARY_OP(Final, %, modulus)

#define BOOST_OPAQUE_HIDING_MODULUS(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP(Final, %, modulus)

#define BOOST_OPAQUE_USING_MODULUS2(Final) \
    BOOST_OPAQUE_USING_BINARY_OP2(Final, %, modulus)

#define BOOST_OPAQUE_HIDING_MODULUS2(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP2(Final, %, modulus)

BOOST_OPAQUE_DCL_META_MIXIN_BINARY(%, modulus)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_BITWISE_XOR(Final) \
    BOOST_OPAQUE_USING_BINARY_OP(Final, ^, bitwise_xor)

#define BOOST_OPAQUE_HIDING_BITWISE_XOR(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP(Final, ^, bitwise_xor)

#define BOOST_OPAQUE_USING_BITWISE_XOR2(Final) \
    BOOST_OPAQUE_USING_BINARY_OP2(Final, ^, bitwise_xor)

#define BOOST_OPAQUE_HIDING_BITWISE_XOR2(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP2(Final, ^, bitwise_xor)

BOOST_OPAQUE_DCL_META_MIXIN_BINARY(^, bitwise_xor)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_BITWISE_OR(Final) \
    BOOST_OPAQUE_USING_BINARY_OP(Final, |, bitwise_or)

#define BOOST_OPAQUE_HIDING_BITWISE_OR(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP(Final, |, bitwise_or)

#define BOOST_OPAQUE_USING_BITWISE_OR2(Final) \
    BOOST_OPAQUE_USING_BINARY_OP2(Final, |, bitwise_or)

#define BOOST_OPAQUE_HIDING_BITWISE_OR2(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP2(Final, |, bitwise_or)

BOOST_OPAQUE_DCL_META_MIXIN_BINARY(|, bitwise_or)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_BITWISE_AND(Final) \
    BOOST_OPAQUE_USING_BINARY_OP(Final, &, bitwise_and)

#define BOOST_OPAQUE_HIDING_BITWISE_AND(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP(Final, &, bitwise_and)

#define BOOST_OPAQUE_USING_BITWISE_AND2(Final) \
    BOOST_OPAQUE_USING_BINARY_OP2(Final, &, bitwise_and)

#define BOOST_OPAQUE_HIDING_BITWISE_AND2(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP2(Final, &, bitwise_and)

BOOST_OPAQUE_DCL_META_MIXIN_BINARY(&, bitwise_and)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_LEFT_SHIFT(Final) \
    BOOST_OPAQUE_USING_BINARY_OP_EX(Final, <<, left_shift)

#define BOOST_OPAQUE_HIDING_LEFT_SHIFT(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP_EX(Final, <<, left_shift)

BOOST_OPAQUE_DCL_META_MIXIN_BINARY_EX(<<, left_shift)

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_RIGHT_SHIFT(Final) \
    BOOST_OPAQUE_USING_BINARY_OP_EX(Final, >>, right_shift)

#define BOOST_OPAQUE_HIDING_RIGHT_SHIFT(Final) \
    BOOST_OPAQUE_HIDING_BINARY_OP_EX(Final, >>, right_shift)

BOOST_OPAQUE_DCL_META_MIXIN_BINARY_EX(>>, right_shift)

}
}

#endif
#endif
