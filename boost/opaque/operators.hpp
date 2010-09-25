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

#include <boost/opaque/new_type.hpp>
#include <boost/operators.hpp>

namespace boost {

namespace opaque {
namespace ope {
    template <typename Base=base_new_type>
    struct copy_delete : Base {
    private:  // emphasize the following members are private
        copy_delete( const copy_delete & );
    };

    template <typename Base=base_new_type>
    struct assign_delete : Base {
    private:  // emphasize the following members are private
            assign_delete& operator=(assign_delete const&);
    };

    template <typename UT, typename Base=base_new_type>
    struct conversion : Base {
        operator UT() const{
                return this->underlying();
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct less_than : Base {
        friend bool operator<(const Final& x, const Final& y)  {
            return x.underlying() < y.underlying();
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct equal : Base {
        friend bool operator==(const Final& x, const Final& y)  {
            return x.underlying() == y.underlying();
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct not_equal : Base {
        friend bool operator!=(const Final& x, const Final& y)  {
            return x.underlying() != y.underlying();
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct plus_assign : Base {
        friend Final& operator+=(Final& x, const Final& y)  {
            x.underlying() += y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct minus_assign : Base {
        friend Final& operator-=(Final& x, const Final& y)  {
            x.underlying() -= y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct multiply_assign : Base {
        friend Final& operator*=(Final& x, const Final& y)  {
            x.underlying() *= y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct divide_assign : Base {
        friend Final& operator/=(Final& x, const Final& y)  {
            x.underlying() /= y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct modulus_assign : Base {
        friend Final& operator%=(Final& x, const Final& y)  {
            x.underlying() %= y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct bitwise_xor_assign : Base {
        friend Final& operator^=(Final& x, const Final& y)  {
            x.underlying() ^= y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct bitwise_and_assign : Base {
        friend Final& operator&=(Final& x, const Final& y)  {
            x.underlying() &= y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct bitwise_or_assign : Base {
        friend Final& operator|=(Final& x, const Final& y)  {
            x.underlying() |= y.underlying();
            return x;
        }
    };
    template <typename Final, typename Base=base_new_type>
    struct left_shift_assign : Base {
        friend Final& operator<<=(Final& x, const Final& y)  {
            x.underlying() <<= y.underlying();
            return x;
        }
    };
    template <typename Final, typename Base=base_new_type>
    struct right_shift_assign : Base {
        friend Final& operator>>=(Final& x, const Final& y)  {
            x.underlying() >>= y.underlying();
            return x;
        }
    };
    // Unary operators

    template <typename Final, typename Base=base_new_type>
    struct logical_not : Base {
        friend bool operator!(Final const& x)  {
            return !(x.underlying());
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct unary_plus : Base {
        friend Final operator+(Final const& x)  {
            return x;
        }
    };
    template <typename Final, typename Base=base_new_type>
    struct unary_minus : Base {
        friend Final operator-(Final const& x)  {
            return Final(-(x.underlying()));
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct bitwise_not : Base {
        friend Final operator~(Final const& x)  {
            return Final(~(x.underlying()));
        }
    };

    //~ template <typename Final, typename Base=base_new_type>
    //~ struct address_of : Base {
        //~ Final* operator&()  {
            //~ return this;
        //~ }
    //~ };

    //~ template <typename Final, typename Derreference=typename reference<Final::underlying_type>::type, typename Base=base_new_type>
    //~ struct derreference : Base {
        //~ Derreference operator*()  {
            //~ return *(x.underlying());
        //~ }
    //~ };

    //~ template <typename Final, typename Pointer=typename pointer<Final::underlying_type>::type, typename Base=base_new_type>
    //~ struct member_access : Base {
        //~ Pointer operator->()  {
            //~ return x.underlying().operator->();
        //~ }
    //~ };

    //~ template <typename Final, class I, class R, typename Base=base_new_type>
    //~ struct subscript : Base {
        //~ R operator[](I n)  {
            //~ return x.underlying()[i];
        //~ }
    //~ };

    // Increment and decrement
    template <typename Final, typename Base=base_new_type>
    struct pre_increment : Base {
        friend Final& operator++(Final& x)  {
            ++x.underlying();
            return x;
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct pre_decrement : Base {
        friend Final& operator--(Final& x)  {
            --x.underlying();
            return x;
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct post_increment : Base {
        friend Final operator++(Final& x, int)  {
            typename Final::underlying_type nrv(x);
            x++;
            return nrv;
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct post_decrement : Base {
        friend Final operator--(Final& x, int)  {
            typename Final::underlying_type nrv(x);
            x--;
            return nrv;
        }
    };

}

}
}


#endif
