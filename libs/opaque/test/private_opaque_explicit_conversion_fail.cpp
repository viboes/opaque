//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Vicente J. Botet Escriba 2010. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/opaque for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#include <boost/opaque/opaque.hpp>

#include <boost/test/unit_test.hpp>

using namespace boost;
using namespace boost::unit_test;


BOOST_OPAQUE_PRIVATE_TYPEDEF(int,A);

template <typename T> void f(T ) {}

void public_multiple_levels_fail() {
    
    A a;
 #if !defined(BOOST_NO_EXPLICIT_CONVERSION_OPERATORS)
    // explicit conversion from OT to UT works in this case so make compile fail
#error `struct A' used where a `int' was expected
#else
    int i;
    i=int(a);
    f(i);
    //error: `OT' used where a `UT' was expected
#endif

}


