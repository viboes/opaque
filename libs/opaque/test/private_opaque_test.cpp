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

#include <boost/detail/lightweight_test.hpp>

using namespace boost;



BOOST_OPAQUE_PRIVATE_TYPEDEF(unsigned,private_unsigned);
BOOST_OPAQUE_PRIVATE_TYPEDEF(unsigned,private_unsigned2);

void size_test() {

    BOOST_TEST(sizeof(private_unsigned)==sizeof(unsigned));
}

void assign_test() {
    private_unsigned a, a2(2);
    //~ private_unsigned2 b;

    //~ a=b; // error
    a=a2; // OK

    unsigned i;
#if !defined(BOOST_NO_EXPLICIT_CONVERSION_OPERATORS)
    // explicit conversion from OT to UT
    i=unsigned(a);
    //error: `OT' used where a `UT' was expected
#else
    i=a.underlying();
#endif
}

void eq_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_TEST(b==c);
    BOOST_TEST((a==b)==false);
}

void neq_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_TEST(a!=b);
    BOOST_TEST((b!=c)==false);
}

void lt_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_TEST(a<b);
    BOOST_TEST((b<a)==false);
    BOOST_TEST((b<c)==false);
}

void gt_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_TEST(b>a);
    BOOST_TEST((a>b)==false);
    BOOST_TEST((b>c)==false);
}

void le_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_TEST(a<=b);
    BOOST_TEST((b<=a)==false);
    BOOST_TEST(b<=c);
}
void ge_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_TEST(b>=a);
    BOOST_TEST((a>=b)==false);
    BOOST_TEST(b>=c);
}

void add_test() {
    private_unsigned a(1), b(2), c(3),d(4);
    BOOST_TEST(a+b==c);
    BOOST_TEST(c==a+b);
    BOOST_TEST((a+b==d)==false);
    BOOST_TEST((d==a+b)==false);
}

void substract_test() {
    private_unsigned a(1), b(2), c(3),d(4);
    BOOST_TEST(c-b==a);
    BOOST_TEST(a==c-b);
    BOOST_TEST((c-b==d)==false);
    BOOST_TEST((d==c-b)==false);
}

void multiply_test() {
    private_unsigned a(1), b(2), c(3),d(6);
    BOOST_TEST(b*c==d);
    BOOST_TEST(b==a*b);
    BOOST_TEST((b*c==a)==false);
    BOOST_TEST((d==a*b)==false);
}

void divide_test() {
    private_unsigned a(1), b(2), c(3),d(6);
    BOOST_TEST(d/c==b);
    BOOST_TEST(b==d/c);
    BOOST_TEST((d/c==a)==false);
    BOOST_TEST((a==d/c)==false);
}


void unariy_plus_test() {
    private_unsigned a(1);
    BOOST_TEST(+a==a);
}

void unariy_minus_test() {
    private_unsigned a(1);
    BOOST_TEST(-a==private_unsigned(-1));
}

void pre_increment_test() {
    private_unsigned a(1);
    private_unsigned b(2);
    BOOST_TEST(++a==b);
}

void post_increment_test() {
    private_unsigned a(1);
    private_unsigned b(1);
    BOOST_TEST(a++==b);
    BOOST_TEST(a==private_unsigned(2));
}


int main()
{

  size_test();
  assign_test();
  eq_test();
  neq_test();
  lt_test();
  gt_test();
  le_test();
  ge_test();
  add_test();
  substract_test();
  multiply_test();
  divide_test();
  unariy_plus_test();
  unariy_minus_test();
  pre_increment_test();
  post_increment_test();

  return boost::report_errors();
}
