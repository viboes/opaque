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

namespace boost {

namespace opaque {
    template <typename Final, typename UT, typename Base>
    struct less_than_comparable : Base {
        friend bool operator<(const Final& x, const Final& y)  {
            return x.underlying() < y.underlying();
        }
    };

    template <typename Final, typename UT, typename Base>
    struct equality_comparable : Base {
        friend bool operator==(const Final& x, const Final& y)  {
            return x.underlying() == y.underlying();
        }
    };

    template <typename Final, typename UT, typename Base>
    struct addable : Base {
        friend Final& operator+=(Final& x, const Final& y)  {
            x.underlying() += y.underlying();
            return x;
        }
    };

    template <typename Final, typename UT, typename Base>
    struct subtractable : Base {
        friend Final& operator-=(Final& x, const Final& y)  {
            x.underlying() -= y.underlying();
            return x;
        }
    };

    template <typename Final, typename UT, typename Base>
    struct multipliable : Base {
        friend Final& operator*=(Final& x, const Final& y)  {
            x.underlying() *= y.underlying();
            return x;
        }
    };

    template <typename Final, typename UT, typename Base>
    struct dividable : Base {
        friend Final& operator/=(Final& x, const Final& y)  {
            x.underlying() /= y.underlying();
            return x;
        }
    };

    template <typename Final, typename UT, typename Base>
    struct modable : Base {
        friend Final& operator%=(Final& x, const Final& y)  {
            x.underlying() %= y.underlying();
            return x;
        }
    };

}
}


#endif
