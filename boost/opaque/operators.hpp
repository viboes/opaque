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
    template <typename Base=base_new_type>
    struct non_copyable : Base {
    private:  // emphasize the following members are private
        non_copyable( const non_copyable& );
    };

    template <typename Base=base_new_type>
    struct non_assignable : Base {
    private:  // emphasize the following members are private
            non_assignable& operator=(non_assignable const&);
    };

    template <typename UT, typename Base=base_new_type>
    struct convertible : Base {
        operator UT() const{
                return this->underlying();
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct less_than_comparable : Base {
        friend bool operator<(const Final& x, const Final& y)  {
            return x.underlying() < y.underlying();
        }
    };

    namespace ope { 
    template <typename Final, typename Base=base_new_type>
    struct eq : Base {
        friend bool operator==(const Final& x, const Final& y)  {
            return x.underlying() == y.underlying();
        }
    };
    }
    template <typename Final, typename Base=base_new_type>
    struct equality_comparable1 : boost::equality_comparable1<Final, ope::eq<Final, Base> > {};

    template <typename Final, typename Base=base_new_type>
    struct addable : Base {
        friend Final& operator+=(Final& x, const Final& y)  {
            x.underlying() += y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct subtractable : Base {
        friend Final& operator-=(Final& x, const Final& y)  {
            x.underlying() -= y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct multipliable : Base {
        friend Final& operator*=(Final& x, const Final& y)  {
            x.underlying() *= y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct dividable : Base {
        friend Final& operator/=(Final& x, const Final& y)  {
            x.underlying() /= y.underlying();
            return x;
        }
    };

    template <typename Final, typename Base=base_new_type>
    struct modable : Base {
        friend Final& operator%=(Final& x, const Final& y)  {
            x.underlying() %= y.underlying();
            return x;
        }
    };

}
}


#endif
