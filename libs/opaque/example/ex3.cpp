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


using namespace boost;
using namespace boost::opaque;

// Listing 7
#if 1
BOOST_OPAQUE_PUBLIC_TYPEDEF(double,mass1_leng2_per_time2);
BOOST_OPAQUE_PUBLIC_TYPEDEF(mass1_leng2_per_time2,energy);
BOOST_OPAQUE_PUBLIC_TYPEDEF(energy,kinetic_energy);
BOOST_OPAQUE_PUBLIC_TYPEDEF(energy,potential_energy);
BOOST_OPAQUE_PUBLIC_TYPEDEF(energy,heat_energy);
#else
BOOST_OPAQUE_PUBLIC_CLASS(double,mass1_leng2_per_time2);
BOOST_OPAQUE_PUBLIC_CLASS(mass1_leng2_per_time2,energy);
BOOST_OPAQUE_PUBLIC_CLASS(energy,kinetic_energy);
BOOST_OPAQUE_PUBLIC_CLASS(energy,potential_energy);
BOOST_OPAQUE_PUBLIC_CLASS(energy,heat_energy);
#endif
BOOST_OPAQUE_INHERIT_FROM_UNDERLYING(mass1_leng2_per_time2)
BOOST_OPAQUE_INHERIT_FROM_UNDERLYING(energy)
BOOST_OPAQUE_INHERIT_FROM_UNDERLYING(kinetic_energy)
BOOST_OPAQUE_INHERIT_FROM_UNDERLYING(potential_energy)
BOOST_OPAQUE_INHERIT_FROM_UNDERLYING(heat_energy)

void public_multiple_levels_test() {
    energy e;
    energy e2;
    potential_energy p, q;
    
    e = p;
    p = p + q; // ok
    e = p + e; // ok
    e = e + q; // ok
}


int main()
{
  public_multiple_levels_test();


  return 0;
}


