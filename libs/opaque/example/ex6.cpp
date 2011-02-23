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


// Listing 3
struct C {};
BOOST_OPAQUE_PUBLIC_TYPEDEF(C, B);
BOOST_OPAQUE_PUBLIC_TYPEDEF(B, A);

void remove_warning(C) {}

void test() {
    A a;
    B ba = a; // okay: is_subst(A,B)
    C cb = ba; // okay: is_subst(B,C)
    C ca = a; // okay: is_subst(A,C)
    remove_warning(cb);
    remove_warning(ca);
}
