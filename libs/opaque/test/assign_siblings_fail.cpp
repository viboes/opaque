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


// Listing 5

BOOST_OPAQUE_PRIVATE_TYPEDEF(int,A);
BOOST_OPAQUE_PRIVATE_TYPEDEF(int,B);


void public_multiple_levels_fail() {
    A a;
    B b;
    a=b; // compile error

}


