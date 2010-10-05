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

#define BOOST_OPAQUE_HIDING_COPY_CONSTRUCTOR(T) \
        private:  \
            T( const T& );

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

    struct using_right_shift_assign {
        template <typename Final, typename Base>
        struct type: Base {
            BOOST_OPAQUE_USING_RIGHT_SHIFT_ASSIGN(Final)
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
// It works for gcc-3.4    
// It doesn't work for gcc-4.3    

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
    struct hiding_plus {
        template <typename Final, typename Base>
        struct type: Base {
        private :
        	//friend Final operator+(const Final& lhs, const Final& rhs);
            Final operator+(const Final& rhs) const;
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
