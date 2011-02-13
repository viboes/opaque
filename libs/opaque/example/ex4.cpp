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

// Listing 1
// Cartesian 3D coordinate types
BOOST_OPAQUE_PUBLIC_TYPEDEF(double, X);
BOOST_OPAQUE_PUBLIC_TYPEDEF(double, Y);
BOOST_OPAQUE_PUBLIC_TYPEDEF(double, Z);

// polar 3D coordinate types
BOOST_OPAQUE_PUBLIC_TYPEDEF(double, Rho);
BOOST_OPAQUE_PUBLIC_TYPEDEF(double, Theta);
BOOST_OPAQUE_PUBLIC_TYPEDEF(double, Phi);

class PhysicsVector {
public:
  PhysicsVector(X, Y, Z);
  PhysicsVector(Rho, Theta, Phi);
  //...
}; // PhysicsVector

void test() {
}


int main()
{
  test();

  return 0;
}


