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

// Listing 5

BOOST_OPAQUE_PRIVATE_TYPEDEF(int,A);
BOOST_OPAQUE_PRIVATE_TYPEDEF(int,B);


void public_multiple_levels_fail() {
    A a;
    B b;
    a=b; // error

    //~ kinetic_energy k;
    //~ potential_energy p;

    //~ k = p; // error
    //~ test.cpp:297: error: no match for 'operator=' in 'k = boost::operator+(const potential_energy&, const potential_energy&)(((const potential_energy&)((const potential_energy*)(& q))))'
    //~ test.cpp:272: note: candidates are: kinetic_energy& kinetic_energy::operator=(const kinetic_energy&)

}


