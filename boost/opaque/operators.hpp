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

//~ #include <boost/opaque/new_type.hpp>
#include <boost/operators.hpp>

namespace boost {

namespace opaque {
namespace ope {
    template <typename Base>
    struct copy_delete : Base {
    private:  // emphasize the following members are private
        copy_delete( const copy_delete & );
    };

    template <typename Base>
    struct assign_delete : Base {
    private:  // emphasize the following members are private
            assign_delete& operator=(assign_delete const&);
    };

    template <typename UT, typename Base>
    struct conversion : Base {
        operator UT() const{
                return this->underlying();
        }
    };

#define BOOST_OPAQUE_USING_LESS_THAN(Final) \
        public :\
        bool operator<(const Final& rhs) const  { \
            return Final::final(this).underlying() < rhs.underlying();\
        }

#define BOOST_OPAQUE_USING_LESS_THAN_EQUAL(Final) \
        public :\
        bool operator<=(const Final& rhs) const  { \
            return Final::final(this).underlying() <= rhs.underlying();\
        }

#define BOOST_OPAQUE_USING_GREATER_THAN(Final) \
        public :\
        bool operator>(const Final& rhs) const  { \
            return Final::final(this).underlying() > rhs.underlying();\
        }

#define BOOST_OPAQUE_USING_GREATER_THAN_EQUAL(Final) \
        public :\
        bool operator>=(const Final& rhs) const  { \
            return Final::final(this).underlying() >= rhs.underlying();\
        }

    template <typename Final, typename Base>
    struct less_than : Base {
        BOOST_OPAQUE_USING_LESS_THAN(Final)
    };

    template <typename Final, typename Base>
    struct equal : Base {
        friend bool operator==(const Final& x, const Final& y)  {
            return x.underlying() == y.underlying();
        }
    };

    template <typename Final, typename Base>
    struct not_equal : Base {
        friend bool operator!=(const Final& x, const Final& y)  {
            return x.underlying() != y.underlying();
        }
    };

    template <typename Final, typename Base>
    struct plus_assign : Base {
        friend Final& operator+=(Final& x, const Final& y)  {
            x.underlying() += y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base>
    struct minus_assign : Base {
        friend Final& operator-=(Final& x, const Final& y)  {
            x.underlying() -= y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base>
    struct multiply_assign : Base {
        friend Final& operator*=(Final& x, const Final& y)  {
            x.underlying() *= y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base>
    struct divide_assign : Base {
        friend Final& operator/=(Final& x, const Final& y)  {
            x.underlying() /= y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base>
    struct modulus_assign : Base {
        friend Final& operator%=(Final& x, const Final& y)  {
            x.underlying() %= y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base>
    struct bitwise_xor_assign : Base {
        friend Final& operator^=(Final& x, const Final& y)  {
            x.underlying() ^= y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base>
    struct bitwise_and_assign : Base {
        friend Final& operator&=(Final& x, const Final& y)  {
            x.underlying() &= y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base>
    struct bitwise_or_assign : Base {
        friend Final& operator|=(Final& x, const Final& y)  {
            x.underlying() |= y.underlying();
            return x;
        }
    };
    template <typename Final, typename Base>
    struct left_shift_assign : Base {
        friend Final& operator<<=(Final& x, const Final& y)  {
            x.underlying() <<= y.underlying();
            return x;
        }
    };
    template <typename Final, typename Base>
    struct right_shift_assign : Base {
        friend Final& operator>>=(Final& x, const Final& y)  {
            x.underlying() >>= y.underlying();
            return x;
        }
    };
    // Unary operators

    template <typename Final, typename Base>
    struct logical_not : Base {
        friend bool operator!(Final const& x)  {
            return !(x.underlying());
        }
    };

    template <typename Final, typename Base>
    struct unary_plus : Base {
        friend Final operator+(Final const& x)  {
            return x;
        }
    };
    template <typename Final, typename Base>
    struct unary_minus : Base {
        friend Final operator-(Final const& x)  {
            return Final(-(x.underlying()));
        }
    };

    template <typename Final, typename Base>
    struct bitwise_not : Base {
        friend Final operator~(Final const& x)  {
            return Final(~(x.underlying()));
        }
    };

    //~ template <typename Final, typename Base>
    //~ struct address_of : Base {
        //~ Final* operator&()  {
            //~ return this;
        //~ }
    //~ };

    //~ template <typename Final, typename Derreference=typename reference<Final::underlying_type>::type, typename Base>
    //~ struct derreference : Base {
        //~ Derreference operator*()  {
            //~ return *(x.underlying());
        //~ }
    //~ };

    //~ template <typename Final, typename Pointer=typename pointer<Final::underlying_type>::type, typename Base>
    //~ struct member_access : Base {
        //~ Pointer operator->()  {
            //~ return x.underlying().operator->();
        //~ }
    //~ };

    //~ template <typename Final, class I, class R, typename Base>
    //~ struct subscript : Base {
        //~ R operator[](I n)  {
            //~ return x.underlying()[i];
        //~ }
    //~ };

    // Increment and decrement
    template <typename Final, typename Base>
    struct pre_increment : Base {
        friend Final& operator++(Final& x)  {
            ++x.underlying();
            return x;
        }
    };

    template <typename Final, typename Base>
    struct pre_decrement : Base {
        friend Final& operator--(Final& x)  {
            --x.underlying();
            return x;
        }
    };

    template <typename Final, typename Base>
    struct post_increment : Base {
        friend Final operator++(Final& x, int)  {
            typename Final::underlying_type nrv(x);
            x.underlying()++;
            return nrv;
        }
    };

    template <typename Final, typename Base>
    struct post_decrement : Base {
        friend Final operator--(Final& x, int)  {
            typename Final::underlying_type nrv(x);
            x.underlying()--;
            return nrv;
        }
    };

}

}
}


#endif
