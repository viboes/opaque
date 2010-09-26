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

#ifndef BOOST_OPAQUE_PRIVATE_OPAQUE_TYPE_HPP
#define BOOST_OPAQUE_PRIVATE_OPAQUE_TYPE_HPP

#include <boost/opaque/opaque_type.hpp>

#include <boost/type_traits/is_class.hpp>
#include <boost/type_traits/is_base_of.hpp>

namespace boost {

    class base_private_opaque_type {};

    template <typename Final, typename UT, typename Base=base_new_type>
    struct transitive_explicit_substituable;

    namespace detail {

    template <typename Final, typename UT, typename Base, bool B>
    struct transitive_explicit_substituable_next_level;

    template <typename Final, typename UT, typename Base>
    struct transitive_explicit_substituable_next_level<Final, UT, Base, true>
        :  transitive_explicit_substituable<Final, typename UT::underlying_type, Base> { };

    template <typename Final, typename UT, typename Base>
    struct transitive_explicit_substituable_next_level<Final, UT, Base, false> :  Base { };

    }

    template <typename Final, typename UT, typename Base>
    struct transitive_explicit_substituable
#if defined(BOOST_NO_EXPLICIT_CONVERSION_OPERATORS)
    {};
#else
        : detail::transitive_explicit_substituable_next_level<Final, UT, Base,
                mpl::and_<is_class<UT>, is_base_of<base_public_opaque_type, UT> >::value>
    {
        explicit operator UT() const {
                return Final::final(this).underlying();
        }
    };
#endif    
        
    template <typename Final, typename T>
    class private_opaque_type : public 
            new_type< Final, T, 
                typename inherited_from_undelying<T, Final, 
                    base_private_opaque_type  
                >::type 
            >
    {
        typedef 
            new_type< Final, T, 
                typename inherited_from_undelying<T, Final, 
                    base_private_opaque_type 
                >::type 
            >
        base_type;
    protected:
        typedef private_opaque_type opaque_type_t;
    public:
        //~ Can instances of UT be explicitly converted to instances of OT? Yes
        //~ Can instances of UT be implicitly converted to instances of OT? No
        //~ Can instances of OT be explicitly converted to instances of UT? Yes. 
            //~ Waiting for explicit conversion operators,, the explicit conversion must be done through the underlying function
        //~ Can instances of OT be implicitly converted to instances of UT? No

        private_opaque_type() {};
        private_opaque_type(const opaque_type_t & rhs) : base_type(rhs.val_) {}
        private_opaque_type(const Final & rhs) : base_type(rhs.val_) {}
        explicit private_opaque_type(T v) : base_type(v) {};
        template <typename W>
        explicit private_opaque_type(W v)
            : base_type(v)
        {}
    };

}


#endif
