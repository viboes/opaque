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
BOOST_OPAQUE_PUBLIC_TYPEDEF(potential_energy,potential_energy2);

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
        energy::substituables,
        double
    >::value),
    SSSSSSSSSSS,
    (energy::substituables)
);

BOOST_OPAQUE_STATIC_ASSERT((
    mpl::contains<
        potential_energy::substituables,
        energy
    >::value),
    SSSSSSSSSSS,
    (potential_energy::substituables)
);

BOOST_OPAQUE_STATIC_ASSERT((
    mpl::contains<
        potential_energy::substituables,
        mass1_leng2_per_time2
    >::value),
    SSSSSSSSSSS,
    (potential_energy::substituables)
);

BOOST_OPAQUE_STATIC_ASSERT((
    mpl::contains<
        potential_energy::substituables,
        double
    >::value),
    SSSSSSSSSSS,
    (potential_energy::substituables)
);

void public_multiple_levels() {
    {
    double d=1;
    mass1_leng2_per_time2 x(d);
    energy e(d);
    potential_energy p(d);
    potential_energy2 p2(d);

    x = e; 
    e = p; 
    x = p; // 2 levels
    d = p; // 3 levels
    d = p2; // 4 levels
        
    }
}


test_suite* init_unit_test_suite(int, char*[])
{
  test_suite* test = BOOST_TEST_SUITE("public_multiple_levels");
  test->add(BOOST_TEST_CASE(&public_multiple_levels));

  return test;
}

