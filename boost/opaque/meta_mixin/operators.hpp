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

#ifndef BOOST_OPAQUE_OPERATORS_HPP
#define BOOST_OPAQUE_OPERATORS_HPP

#include <boost/operators.hpp>

namespace boost {
namespace opaque {

//////////////////////////////////////////////////////////////////////////////

#define BOOST_OPAQUE_HIDING_COPY(T) \
        private:  \
            T( const T& );

    struct hiding_copy {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_HIDING_COPY(type)
        };
    };

//////////////////////////////////////////////////////////////////////////////
    
#define BOOST_OPAQUE_HIDING_ASSIGN(T) \
        private: \
            T& operator=(T const&);

    struct hiding_assign {
        template <typename Final, typename Base>
        struct type : Base {
            BOOST_OPAQUE_HIDING_ASSIGN(type)
        };
    };

//////////////////////////////////////////////////////////////////////////////
        
#define BOOST_OPAQUE_USING_CONVERSION(Final,UT) \
    public: \
            operator UT() const{ \
                return Final::underlying(this); \
            }

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

    template <typename Bool=bool>
    struct using_less_than {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_LESS_THAN(Final,Bool)
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

//////////////////////////////////////////////////////////////////////////////
        
#define BOOST_OPAQUE_USING_RIGHT_SHIFT_ASSIGN(Final) \
    public :\
        Final&  operator>>=(const Final& rhs) { \
            Final::underlying(this) >>= rhs.underlying();\
            return Final::final(this); \
        }

    struct using_left_right_assign {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_RIGHT_SHIFT_ASSIGN(Final)
        };
    };

// Unary operators

//////////////////////////////////////////////////////////////////////////////
        
#define BOOST_OPAQUE_USING_LOGICAL_NOT(Final) \
    public :\
        bool operator!() const  { \
            return !Final::underlying(this);\
        }

    struct using_logical_not {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_LOGICAL_NOT(Final)
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

//////////////////////////////////////////////////////////////////////////////
        
//~ template <typename Final, typename Base>
//~ struct address_of : Base {
//~ 	Final* operator&()  {
//~ 		return this;
//~ 	}
//~ };

//////////////////////////////////////////////////////////////////////////////
        
//~ template <typename Final, typename Derreference=typename reference<Final::underlying_type>::type, typename Base>
//~ struct derreference : Base {
//~ 	Derreference operator*()  {
//~ 		return *(x.underlying());
//~ 	}
//~ };

//////////////////////////////////////////////////////////////////////////////
        
//~ template <typename Final, typename Pointer=typename pointer<Final::underlying_type>::type, typename Base>
//~ struct member_access : Base {
//~ 	Pointer operator->()  {
//~ 		return x.underlying().operator->();
//~ 	}
//~ };

//////////////////////////////////////////////////////////////////////////////
        
//~ template <typename Final, class I, class R, typename Base>
//~ struct subscript : Base {
//~ 	R operator[](I n)  {
//~ 		return x.underlying()[i];
//~ 	}
//~ };

// Increment and decrement
//////////////////////////////////////////////////////////////////////////////
        
#define BOOST_OPAQUE_USING_PRE_INCREMENT(Final) \
    public :\
        Final operator++()  { \
            ++Final::underlying(this); \
            return Final::final(this); \
        }

    struct using_pre_increment {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_PRE_INCREMENT(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////
        
#define BOOST_OPAQUE_USING_PRE_DECREMENT(Final) \
    public :\
        Final operator--()  { \
            --Final::underlying(this); \
            return Final::final(this); \
        }

    struct using_pre_decrement {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_PRE_DECREMENT(Final)
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

#if 0
// I don't know why this doesn't works :(

//////////////////////////////////////////////////////////////////////////////
        
#define BOOST_OPAQUE_USING_PLUS(Final) \
    public :\
        Final operator+(const Final& rhs) const { \
            return Final(Final::underlying(this) + rhs.underlying()); \
        }

#define BOOST_OPAQUE_USING_MINUS(Final) \
    public :\
        Final operator-(const Final& rhs) const { \
            return Final(Final::underlying(this) - rhs.underlying()); \
        }
#else
#define BOOST_OPAQUE_USING_PLUS(Final) \
    public :\
        friend Final operator+(const Final& lhs, const Final& rhs) { \
            return Final(lhs.underlying() + rhs.underlying()); \
        }
#define BOOST_OPAQUE_USING_MINUS(Final) \
    public :\
        friend Final  operator-(const Final& lhs, const Final& rhs) { \
            return Final(lhs.underlying() - rhs.underlying()); \
        }
#endif

//////////////////////////////////////////////////////////////////////////////
        
    struct using_plus {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_PLUS(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////
        
    struct using_minus {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_MINUS(Final)
        };
    };

//////////////////////////////////////////////////////////////////////////////
        
#define BOOST_OPAQUE_USING_MULTIPLY(Final) \
    public :\
        Final  operator*(const Final& rhs) const { \
            return Final(Final::underlying(this) * rhs.underlying()); \
        }

    struct using_multiply {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_MULTIPLY(Final)
        };
    };
    
//////////////////////////////////////////////////////////////////////////////
        
#define BOOST_OPAQUE_USING_DIVIDE(Final) \
    public :\
        Final  operator/(const Final& rhs) const { \
            return Final(Final::underlying(this) / rhs.underlying()); \
        }

    struct using_divide {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_DIVIDE(Final)
        };
    };
    
    
//////////////////////////////////////////////////////////////////////////////
        
#define BOOST_OPAQUE_USING_MODULUS(Final) \
    public :\
        Final  operator%(const Final& rhs) const { \
            return Final(Final::underlying(this) % rhs.underlying()); \
        }

    struct using_modulus {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_MODULUS(Final)
        };
    };
    
//////////////////////////////////////////////////////////////////////////////
        
#define BOOST_OPAQUE_USING_BITWISE_XOR(Final) \
    public :\
        Final operator^(const Final& rhs) const { \
            return Final(Final::underlying(this) ^ rhs.underlying()); \
        }

    struct using_bitwise_xor {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_BITWISE_XOR(Final)
        };
    };
    
    
//////////////////////////////////////////////////////////////////////////////
        
#define BOOST_OPAQUE_USING_BITWISE_OR(Final) \
    public :\
        Final operator|(const Final& rhs) const { \
            return Final(Final::underlying(this) | rhs.underlying()); \
        }

    struct using_bitwise_or {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_BITWISE_OR(Final)
        };
    };
    
//////////////////////////////////////////////////////////////////////////////
        
#define BOOST_OPAQUE_USING_BITWISE_AND(Final) \
    public :\
        Final operator&(const Final& rhs) const { \
            return Final(Final::underlying(this) & rhs.underlying()); \
        }

    struct using_bitwise_and {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_BITWISE_AND(Final)
        };
    };
    
//////////////////////////////////////////////////////////////////////////////
        
#define BOOST_OPAQUE_USING_LEFT_SHIFT1(Final) \
    public :\
        Final operator<<(const Final& rhs) const { \
            return Final(Final::underlying(this) << rhs.underlying()); \
        }

    struct using_left_shift1 {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_LEFT_SHIFT1(Final)
        };
    };
    
//////////////////////////////////////////////////////////////////////////////
        
#define BOOST_OPAQUE_USING_RIGHT_SHIFT1(Final) \
    public :\
        Final operator>>(const Final& rhs) const { \
            return Final(Final::underlying(this) >> rhs.underlying()); \
        }

    struct using_right_shift1 {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_RIGHT_SHIFT1(Final)
        };
    };
    
}
}

#endif
