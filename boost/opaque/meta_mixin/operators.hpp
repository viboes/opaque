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
 * In this section the meta-mixin follows the schema
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

#include <boost/operators.hpp>

namespace boost {
  namespace opaque {

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

#define BOOST_OPAQUE_USING_CONVERSION(Final,UT) \
    public: \
            operator UT() const{ \
                return Final::underlying(this); \
            }
    /**
     * Adds the implicit conversion operator to the underlying type.
     *
     */
    template <typename UT>
    struct using_underlying_conversion {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_CONVERSION(Final,UT)
        };
    };

//////////////////////////////////////////////////////////////////////////////


    template <typename T>
    struct using_conversion_to {
        template <typename Final, typename Base>
        struct type: Base {
            operator T() const{
                return T(Final::underlying(this));
            }
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

#define BOOST_OPAQUE_USING_LESS_THAN(Final, Bool) \
    public :\
        Bool operator<(const Final& rhs) const  { \
            return Bool(Final::underlying(this) < rhs.underlying());\
        }

    /**
     * Adds the <c>Bool operator<(const Final& rhs) const</c>.
     *
     * @Requires <c>Bool(Final::underlying(this) < rhs.underlying())</c> is correct.
     */
    template <typename Bool=bool>
    struct using_less_than {
        template <typename Final, typename Base>
        struct type: Base {
           BOOST_OPAQUE_USING_LESS_THAN(Final,Bool)
        };
    };

#define BOOST_OPAQUE_HIDING_LESS_THAN(Final, Bool) \
    private :\
        Bool operator<(const Final& rhs) const;

    template <typename Bool=bool>
    struct hiding_less_than {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_HIDING_LESS_THAN(Final,Bool)
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_LESS_THAN_EQUAL(Final,Bool) \
    public :\
        Bool operator<=(const Final& rhs) const  { \
            return Bool(Final::underlying(this) <= rhs.underlying());\
        }

    template <typename Bool=bool>
    struct using_less_than_equal {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_LESS_THAN_EQUAL(Final,Bool)
        };
    };

    template <typename Bool=bool>
    struct hiding_less_than_equal {
        template <typename Final, typename Base>
        struct type: Base {
            Bool operator<=(const Final& rhs) const;
        };
    };
    
//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_GREATER_THAN(Final,Bool) \
    public :\
        Bool operator>(const Final& rhs) const  { \
            return Bool(Final::underlying(this) > rhs.underlying());\
        }

    template <typename Bool=bool>
    struct using_greater_than {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_GREATER_THAN(Final,Bool)
        };
    };
    template <typename Bool=bool>
    struct hiding_greater_than {
        template <typename Final, typename Base>
        struct type: Base {
            Bool operator>(const Final& rhs) const;
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_GREATER_THAN_EQUAL(Final,Bool) \
    public :\
        Bool operator>=(const Final& rhs) const  { \
            return Bool(Final::underlying(this) >= rhs.underlying());\
        }

    template <typename Bool=bool>
    struct using_greater_than_equal {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_GREATER_THAN_EQUAL(Final,Bool)
        };
    };
    template <typename Bool=bool>
    struct hiding_greater_than_equal {
        template <typename Final, typename Base>
        struct type: Base {
            Bool operator>=(const Final& rhs) const;
        };
    };


//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_EQUAL(Final,Bool) \
    public :\
        Bool operator==(const Final& rhs) const  { \
            return Bool(Final::underlying(this) == rhs.underlying());\
        }

    template <typename Bool=bool>
    struct using_equal {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_EQUAL(Final,Bool)
        };
    };
    template <typename Bool=bool>
    struct hiding_equal {
        template <typename Final, typename Base>
        struct type: Base {
            Bool operator==(const Final& rhs) const;
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_NOT_EQUAL(Final,Bool) \
    public :\
        Bool operator!=(const Final& rhs) const  { \
            return Bool(Final::underlying(this) != rhs.underlying());\
        }

    template <typename Bool=bool>
    struct using_not_equal {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_NOT_EQUAL(Final,Bool)
        };
    };
    template <typename Bool=bool>
    struct hiding_not_equal {
        template <typename Final, typename Base>
        struct type: Base {
            Bool operator!=(const Final& rhs) const;
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_PLUS_ASSIGN(Final) \
    public :\
        Final&  operator+=(const Final& rhs) { \
            Final::underlying(this) += rhs.underlying();\
            return Final::final(this); \
        }

    struct using_plus_assign {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_PLUS_ASSIGN(Final)
        };
    };

    struct hiding_plus_assign {
        template <typename Final, typename Base>
        struct type: Base {
            Final&  operator+=(const Final& rhs);
        };
    };
    
//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_MINUS_ASSIGN(Final) \
    public :\
        Final&  operator-=(const Final& rhs) { \
            Final::underlying(this) -= rhs.underlying();\
            return Final::final(this); \
        }

    struct using_minus_assign {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_MINUS_ASSIGN(Final)
        };
    };
    struct hiding_minus_assign {
        template <typename Final, typename Base>
        struct type: Base {
            Final&  operator-=(const Final& rhs);
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_MULTIPLY_ASSIGN(Final) \
    public :\
        Final&  operator*=(const Final& rhs) { \
            Final::underlying(this) *= rhs.underlying();\
            return Final::final(this); \
        }

    struct using_multiply_assign {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_MULTIPLY_ASSIGN(Final)
        };
    };
    struct hiding_multiply_assign {
        template <typename Final, typename Base>
        struct type: Base {
            Final&  operator*=(const Final& rhs);
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_DIVIDE_ASSIGN(Final) \
    public :\
        Final&  operator/=(const Final& rhs) { \
            Final::underlying(this) /= rhs.underlying();\
            return Final::final(this); \
        }

    struct using_divide_assign {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_DIVIDE_ASSIGN(Final)
        };
    };
    struct hiding_divide_assign {
        template <typename Final, typename Base>
        struct type: Base {
            Final&  operator/=(const Final& rhs);
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_MODULUS_ASSIGN(Final) \
    public :\
        Final&  operator%=(const Final& rhs) { \
            Final::underlying(this) %= rhs.underlying();\
            return Final::final(this); \
        }

    struct using_modulus_assign {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_MODULUS_ASSIGN(Final)
        };
    };
    struct hiding_modulus_assign {
        template <typename Final, typename Base>
        struct type: Base {
            Final&  operator%=(const Final& rhs);
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_BITWISE_XOR_ASSIGN(Final) \
    public :\
        Final&  operator^=(const Final& rhs) { \
            Final::underlying(this) ^= rhs.underlying();\
            return Final::final(this); \
        }

    struct using_bitwise_xor_assign {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_BITWISE_XOR_ASSIGN(Final)
        };
    };
    struct hiding_bitwise_xor_assign {
        template <typename Final, typename Base>
        struct type: Base {
            Final&  operator^=(const Final& rhs);
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_BITWISE_AND_ASSIGN(Final) \
    public :\
        Final&  operator&=(const Final& rhs) { \
            Final::underlying(this) &= rhs.underlying();\
            return Final::final(this); \
        }

    struct using_bitwise_and_assign {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_BITWISE_AND_ASSIGN(Final)
        };
    };
    struct hiding_bitwise_and_assign {
        template <typename Final, typename Base>
        struct type: Base {
            Final&  operator&=(const Final& rhs);
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_BITWISE_OR_ASSIGN(Final) \
    public :\
        Final&  operator|=(const Final& rhs) { \
            Final::underlying(this) |= rhs.underlying();\
            return Final::final(this); \
        }

    struct using_bitwise_or_assign {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_BITWISE_OR_ASSIGN(Final)
        };
    };
    struct hiding_bitwise_or_assign {
        template <typename Final, typename Base>
        struct type: Base {
            Final&  operator|=(const Final& rhs);
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_LEFT_SHIFT_ASSIGN(Final) \
    public :\
        Final&  operator<<=(const Final& rhs) { \
            Final::underlying(this) <<= rhs.underlying();\
            return Final::final(this); \
        }

    struct using_left_shift_assign {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_LEFT_SHIFT_ASSIGN(Final)
        };
    };
    struct hiding_left_shift_assign {
        template <typename Final, typename Base>
        struct type: Base {
            Final&  operator<<=(const Final& rhs);\
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_RIGHT_SHIFT_ASSIGN(Final) \
    public :\
        Final&  operator>>=(const Final& rhs) { \
            Final::underlying(this) >>= rhs.underlying();\
            return Final::final(this); \
        }

    struct using_right_shift_assign {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_RIGHT_SHIFT_ASSIGN(Final)
        };
    };
    struct hiding_right_shift_assign {
        template <typename Final, typename Base>
        struct type: Base {
            Final&  operator>>=(const Final& rhs);
        };
    };

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
            Final operator--(int);
        };
    };

//////////////////////////////////////////////////////////////////////////////
    
#define BOOST_OPAQUE_USING_PLUS(Final) \
    private : \
        Final using_plus_op(const Final& rhs) const { \
            return Final(Final::underlying(this) + rhs.underlying()); \
        } \
        friend Final operator+(const Final& lhs, const Final& rhs) { \
            return lhs.using_plus_op(rhs); \
        }
    
    struct using_plus {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_PLUS(Final)
        };
    };

    struct hiding_plus {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Final using_plus_op(const Final& rhs) const;
        };
    };
   
//////////////////////////////////////////////////////////////////////////////
    
#define BOOST_OPAQUE_USING_MINUS(Final) \
    private : \
        Final using_minus_op(const Final& rhs) const { \
            return Final(Final::underlying(this) - rhs.underlying()); \
        } \
        friend Final  operator-(const Final& lhs, const Final& rhs) { \
            return lhs.using_minus_op(rhs); \
        }

    
    struct using_minus {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_MINUS(Final)
        };
    };

    struct hiding_minus {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Final using_minus_op(const Final& rhs) const;
        };
    };
       
//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_MULTIPLY(Final) \
    private : \
        Final using_multiply_op(const Final& rhs) const { \
            return Final(Final::underlying(this) * rhs.underlying()); \
        } \
        friend Final  operator*(const Final& lhs, const Final& rhs) { \
            return lhs.using_multiply_op(rhs); \
        }

    struct using_multiply {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_MULTIPLY(Final)
        };
    };

    struct hiding_multiply {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Final using_multiply_op(const Final& rhs) const;
        };
    };
    
//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_DIVIDE(Final) \
    private : \
        Final using_divide_op(const Final& rhs) const { \
            return Final(Final::underlying(this) / rhs.underlying()); \
        } \
        friend Final  operator/(const Final& lhs, const Final& rhs) { \
            return lhs.using_divide_op(rhs); \
        }

    struct using_divide {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_DIVIDE(Final)
        };
    };

    struct hiding_divide {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Final using_divide_op(const Final& rhs) const;
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_MODULUS(Final) \
    private : \
        Final using_modulus_op(const Final& rhs) const { \
            return Final(Final::underlying(this) % rhs.underlying()); \
        } \
        friend Final  operator%(const Final& lhs, const Final& rhs) { \
            return lhs.using_modulus_op(rhs); \
        }

    struct using_modulus {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_MODULUS(Final)
        };
    };

    struct hiding_modulus {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Final using_modulus_op(const Final& rhs) const;
        };
    };
    
//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_BITWISE_XOR(Final) \
    private : \
        Final using_bitwise_xor_op(const Final& rhs) const { \
            return Final(Final::underlying(this) ^ rhs.underlying()); \
        } \
        friend Final  operator^(const Final& lhs, const Final& rhs) { \
            return lhs.using_bitwise_xor_op(rhs); \
        }

    struct using_bitwise_xor {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_BITWISE_XOR(Final)
        };
    };

    struct hiding_bitwise_xor {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Final using_bitwise_xor_op(const Final& rhs) const;
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_BITWISE_OR(Final) \
    private : \
        Final using_bitwise_or_op(const Final& rhs) const { \
            return Final(Final::underlying(this) | rhs.underlying()); \
        } \
        friend Final  operator|(const Final& lhs, const Final& rhs) { \
            return lhs.using_bitwise_or_op(rhs); \
        }

    struct using_bitwise_or {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_BITWISE_OR(Final)
        };
    };

    struct hiding_bitwise_or {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Final using_bitwise_or_op(const Final& rhs) const;
        };
    };

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_BITWISE_AND(Final) \
    private : \
        Final using_bitwise_and_op(const Final& rhs) const { \
            return Final(Final::underlying(this) & rhs.underlying()); \
        } \
        friend Final  operator&(const Final& lhs, const Final& rhs) { \
            return lhs.using_bitwise_and_op(rhs); \
        }

    struct using_bitwise_and {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_BITWISE_AND(Final)
        };
    };

    struct hiding_bitwise_and {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Final using_bitwise_and_op(const Final& rhs) const;
        };
    };
    
//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_LEFT_SHIFT1(Final) \
    private : \
        Final using_left_shift_op(const Final& rhs) const { \
            return Final(Final::underlying(this) << rhs.underlying()); \
        } \
        friend Final  operator<<(const Final& lhs, const Final& rhs) { \
            return lhs.using_left_shift_op(rhs); \
        }

    struct using_left_shift1 {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_LEFT_SHIFT1(Final)
        };
    };

    struct hiding_left_shift {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Final using_left_shift_op(const Final& rhs) const;
        };
    };
    
//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_USING_RIGHT_SHIFT1(Final) \
    private : \
        Final using_right_shift_op(const Final& rhs) const { \
            return Final(Final::underlying(this) >> rhs.underlying()); \
        } \
        friend Final  operator>>(const Final& lhs, const Final& rhs) { \
            return lhs.using_right_shift_op(rhs); \
        }

    struct using_right_shift1 {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_RIGHT_SHIFT1(Final)
        };
    };

    struct hiding_right_shift {
        template <typename Final, typename Base>
        struct type: Base {
        private :
            Final using_right_shift_op(const Final& rhs) const;
        };
    };
    
}
}

#endif
