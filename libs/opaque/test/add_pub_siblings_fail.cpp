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
BOOST_OPAQUE_PRIVATE_TYPEDEF(int,B);

template <typename T>
void f(T v) {
}

void public_multiple_levels_fail() {
    
    A a;
    B b;
    a=a+b;
    
}


