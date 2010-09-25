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

void private_assign_test() {
    private_unsigned a, a2;
    private_unsigned2 b;

    //~ a=b; // error
    a=a2; // OK

    //~ unsigned i;

    //~ i=opaque_static_cast<unsigned>(a);
    //~ i=a; // error

    //~ i=b; // error
    //~ a=i; // error
    //~ b=i; // error
}

void private_eq_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_CHECK(b==c);
    BOOST_CHECK((a==b)==false);
}
#if 0
void private_eq_test_fails() {
    private_unsigned a;
    private_unsigned2 a2;
    BOOST_CHECK(a==a2);
}
#endif
void private_lt_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_CHECK(a<b);
    BOOST_CHECK((b<a)==false);
    BOOST_CHECK((b<c)==false);
}

void private_gt_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_CHECK(b>a);
    BOOST_CHECK((a>b)==false);
    BOOST_CHECK((b>c)==false);
}

void private_le_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_CHECK(a<=b);
    BOOST_CHECK((b<=a)==false);
    BOOST_CHECK(b<=c);
}
void private_ge_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_CHECK(b>=a);
    BOOST_CHECK((a>=b)==false);
    BOOST_CHECK(b>=c);
}

void private_add_test() {
    private_unsigned a(1), b(2), c(3),d(4);
    BOOST_CHECK(a+b==c);
    BOOST_CHECK(c==a+b);
    BOOST_CHECK((a+b==d)==false);
    BOOST_CHECK((d==a+b)==false);

    private_unsigned2 x;
    //~ a=a+x; // error

    //~ unsigned u=3,v=0;
    //~ BOOST_CHECK(a+b==3u);
    //~ BOOST_CHECK(u==a+b);
    //~ BOOST_CHECK(a+b==u);
    //~ BOOST_CHECK((a+b==v)==false);
    //~ BOOST_CHECK((v==a+b)==false);

}

void private_substract_test() {
    private_unsigned a(1), b(2), c(3),d(4);
    BOOST_CHECK(c-b==a);
    BOOST_CHECK(a==c-b);
    BOOST_CHECK((c-b==d)==false);
    BOOST_CHECK((d==c-b)==false);

    //~ unsigned u=1,v=0;
    //~ BOOST_CHECK(c-b==1u);
    //~ BOOST_CHECK(u==c-b);
    //~ BOOST_CHECK(c-b==u);
    //~ BOOST_CHECK((c-b==v)==false);
    //~ BOOST_CHECK((v==c-b)==false);

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


  test->add(BOOST_TEST_CASE(&private_assign_test));
  test->add(BOOST_TEST_CASE(&private_eq_test));
  test->add(BOOST_TEST_CASE(&private_lt_test));
  test->add(BOOST_TEST_CASE(&private_gt_test));
  test->add(BOOST_TEST_CASE(&private_le_test));
  test->add(BOOST_TEST_CASE(&private_ge_test));
  test->add(BOOST_TEST_CASE(&private_add_test));
  test->add(BOOST_TEST_CASE(&private_substract_test));
  test->add(BOOST_TEST_CASE(&unariy_plus_test));
  test->add(BOOST_TEST_CASE(&unariy_minus_test));
  test->add(BOOST_TEST_CASE(&pre_increment_test));
  test->add(BOOST_TEST_CASE(&post_increment_test));

  return test;
}


