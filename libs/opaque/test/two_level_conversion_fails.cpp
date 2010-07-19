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
#include <boost/mpl/assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/mpl/contains.hpp>

#include <boost/test/unit_test.hpp>

using namespace boost;
using namespace boost::unit_test;

// Listing 7
BOOST_OPAQUE_PUBLIC_TYPEDEF(double,mass1_leng2_per_time2);
BOOST_OPAQUE_PUBLIC_TYPEDEF(mass1_leng2_per_time2,energy);
BOOST_OPAQUE_PUBLIC_TYPEDEF(energy,kinetic_energy);
BOOST_OPAQUE_PUBLIC_TYPEDEF(energy,potential_energy);
BOOST_OPAQUE_PUBLIC_TYPEDEF(energy,heat_energy);

BOOST_OPAQUE_STATIC_ASSERT((
    is_same<
        mass1_leng2_per_time2::substituables,
        mpl::vector<double>
    >::value),
    SSSSSSSSSSS,
    (mass1_leng2_per_time2::substituables)
);

BOOST_OPAQUE_STATIC_ASSERT((
    mpl::contains<
        energy::substituables,
        mass1_leng2_per_time2
    >::value),
    SSSSSSSSSSS,
    (energy::substituables)
);

BOOST_OPAQUE_STATIC_ASSERT((
    mpl::contains<
        potential_energy::substituables,
        mass1_leng2_per_time2
    >::value),
    SSSSSSSSSSS,
    (potential_energy::substituables)
);

void public_multiple_levels_fail() {
    mass1_leng2_per_time2 x;
    energy e;
    potential_energy p, q;

    x = e; 
    e = p; 
    x = p; // error two levels
    //~ x = p + q; // error two levels
    //~ test.cpp:287: error: no match for 'operator=' in 'x = boost::operator+(const potential_energy&, const potential_energy&)(((const potential_energy&)((const potential_energy*)(& q))))'
    //~ test.cpp:270: note: candidates are: mass1_leng2_per_time2& mass1_leng2_per_time2::operator=(const mass1_leng2_per_time2&)

}


test_suite* init_unit_test_suite(int, char*[])
{
  test_suite* test = BOOST_TEST_SUITE("public_multiple_levels");
  test->add(BOOST_TEST_CASE(&public_multiple_levels_fail));

  return test;
}

