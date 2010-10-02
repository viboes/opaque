//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Vicente J. Botet Escriba 2010. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/opaque for documentation.
//
//////////////////////////////////////////////////////////////////////////////


// Listing 2
struct A { };
struct B { B(A); };
struct C { C(B); };

void test() {
	A a;
	B ba = a; // okay: is_subst(A,B)
	C cb = ba; // okay: is_subst(B,C)
	C ca = a; // oops: ! is_subst(A,C) per [ISO03, §13.3.3.1.2/1]
	// error: conversion from `A' to non-scalar type `C' requested
}

