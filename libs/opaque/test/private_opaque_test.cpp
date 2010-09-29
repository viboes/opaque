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



BOOST_OPAQUE_PRIVATE_TYPEDEF(unsigned,private_unsigned);
BOOST_OPAQUE_PRIVATE_TYPEDEF(unsigned,private_unsigned2);

void size_test() {

    BOOST_CHECK(sizeof(private_unsigned)==sizeof(unsigned));
}

void assign_test() {
    private_unsigned a, a2;
    private_unsigned2 b;

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
    BOOST_CHECK(b==c);
    BOOST_CHECK((a==b)==false);
}

void neq_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_CHECK(a!=b);
    BOOST_CHECK((b!=c)==false);
}

void lt_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_CHECK(a<b);
    BOOST_CHECK((b<a)==false);
    BOOST_CHECK((b<c)==false);
}

void gt_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_CHECK(b>a);
    BOOST_CHECK((a>b)==false);
    BOOST_CHECK((b>c)==false);
}

void le_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_CHECK(a<=b);
    BOOST_CHECK((b<=a)==false);
    BOOST_CHECK(b<=c);
}
void ge_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_CHECK(b>=a);
    BOOST_CHECK((a>=b)==false);
    BOOST_CHECK(b>=c);
}

void add_test() {
    private_unsigned a(1), b(2), c(3),d(4);
    BOOST_CHECK(a+b==c);
    BOOST_CHECK(c==a+b);
    BOOST_CHECK((a+b==d)==false);
    BOOST_CHECK((d==a+b)==false);
}

void substract_test() {
    private_unsigned a(1), b(2), c(3),d(4);
    BOOST_CHECK(c-b==a);
    BOOST_CHECK(a==c-b);
    BOOST_CHECK((c-b==d)==false);
    BOOST_CHECK((d==c-b)==false);
}

void multiply_test() {
    private_unsigned a(1), b(2), c(3),d(6);
    BOOST_CHECK(b*c==d);
    BOOST_CHECK(b==a*b);
    BOOST_CHECK((b*c==a)==false);
    BOOST_CHECK((d==a*b)==false);
}

void divide_test() {
    private_unsigned a(1), b(2), c(3),d(6);
    BOOST_CHECK(d/c==b);
    BOOST_CHECK(b==d/c);
    BOOST_CHECK((d/c==a)==false);
    BOOST_CHECK((a==d/c)==false);
}


void unariy_plus_test() {
    private_unsigned a(1);
    BOOST_CHECK(+a==a);
}

void unariy_minus_test() {
    private_unsigned a(1);
    BOOST_CHECK(-a==private_unsigned(-1));
}

void pre_increment_test() {
    private_unsigned a(1);
    private_unsigned b(2);
    BOOST_CHECK(++a==b);
}

void post_increment_test() {
    private_unsigned a(1);
    private_unsigned b(1);
    BOOST_CHECK(a++==b);
    BOOST_CHECK(a==private_unsigned(2));
}


test_suite* init_unit_test_suite(int, char*[])
{
  test_suite* test = BOOST_TEST_SUITE("private");


  test->add(BOOST_TEST_CASE(&size_test));
  test->add(BOOST_TEST_CASE(&assign_test));
  test->add(BOOST_TEST_CASE(&eq_test));
  test->add(BOOST_TEST_CASE(&neq_test));
  test->add(BOOST_TEST_CASE(&lt_test));
  test->add(BOOST_TEST_CASE(&gt_test));
  test->add(BOOST_TEST_CASE(&le_test));
  test->add(BOOST_TEST_CASE(&ge_test));
  test->add(BOOST_TEST_CASE(&add_test));
  test->add(BOOST_TEST_CASE(&substract_test));
  test->add(BOOST_TEST_CASE(&multiply_test));
  test->add(BOOST_TEST_CASE(&divide_test));
  test->add(BOOST_TEST_CASE(&unariy_plus_test));
  test->add(BOOST_TEST_CASE(&unariy_minus_test));
  test->add(BOOST_TEST_CASE(&pre_increment_test));
  test->add(BOOST_TEST_CASE(&post_increment_test));

  return test;
}


