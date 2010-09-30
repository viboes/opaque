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

BOOST_OPAQUE_PUBLIC_TYPEDEF(unsigned,public_unsigned);
BOOST_OPAQUE_PUBLIC_TYPEDEF(unsigned,public_unsigned2);

void size_test() {

    BOOST_CHECK(sizeof(public_unsigned)==sizeof(unsigned));
}

void assign_test() {
    public_unsigned a(0), a2(1);
    public_unsigned2 b(0);

    //~ a=b; // error
    a=a2; // OK

    unsigned i;

    i=a;
    i=b;
    //~ a=i; // error
    //~ b=i; // error
}

void eq_test() {
    public_unsigned a(1), b(2), c(2);
    BOOST_CHECK(b==c);
    BOOST_CHECK((a==b)==false);

    unsigned u=1,v=2;
    BOOST_CHECK(a==1u);
    BOOST_CHECK(u==a);
    BOOST_CHECK(a==u);
    BOOST_CHECK((a==v)==false);
    BOOST_CHECK((v==a)==false);
}

void neq_test() {
    public_unsigned a(1), b(2), c(2);
    BOOST_CHECK(a!=b);
    BOOST_CHECK((b!=c)==false);
}


void lt_test() {
    public_unsigned a(1), b(2), c(2);
    BOOST_CHECK(a<b);
    BOOST_CHECK((b<a)==false);
    BOOST_CHECK((b<c)==false);
}

void gt_test() {
    public_unsigned a(1), b(2), c(2);
    BOOST_CHECK(b>a);
    BOOST_CHECK((a>b)==false);
    BOOST_CHECK((b>c)==false);
}

void le_test() {
    public_unsigned a(1), b(2), c(2);
    BOOST_CHECK(a<=b);
    BOOST_CHECK((b<=a)==false);
    BOOST_CHECK(b<=c);
}
void ge_test() {
    public_unsigned a(1), b(2), c(2);
    BOOST_CHECK(b>=a);
    BOOST_CHECK((a>=b)==false);
    BOOST_CHECK(b>=c);
}

void add_test() {
    public_unsigned a(1), b(2), c(3),d(4);
    BOOST_CHECK(a+b==c);
    BOOST_CHECK(c==a+b);
    BOOST_CHECK((a+b==d)==false);
    BOOST_CHECK((d==a+b)==false);

    //~ public_unsigned2 x;
    //~ a=a+x; // error

    unsigned u=3,v=0;
    BOOST_CHECK(a+b==3u);
    BOOST_CHECK(u==a+b);
    BOOST_CHECK(a+b==u);
    BOOST_CHECK((a+b==v)==false);
    BOOST_CHECK((v==a+b)==false);

}

void substract_test() {
    public_unsigned a(1), b(2), c(3),d(4);
    BOOST_CHECK(c-b==a);
    BOOST_CHECK(a==c-b);
    BOOST_CHECK((c-b==d)==false);
    BOOST_CHECK((d==c-b)==false);

    unsigned u=1,v=0;
    BOOST_CHECK(c-b==1u);
    BOOST_CHECK(u==c-b);
    BOOST_CHECK(c-b==u);
    BOOST_CHECK((c-b==v)==false);
    BOOST_CHECK((v==c-b)==false);

}

void multiply_test() {
    public_unsigned a(1), b(2), c(3),d(6);
    BOOST_CHECK(b*c==d);
    BOOST_CHECK(b==a*b);
    BOOST_CHECK((b*c==a)==false);
    BOOST_CHECK((d==a*b)==false);
}

void divide_test() {
    public_unsigned a(1), b(2), c(3),d(6);
    BOOST_CHECK(d/c==b);
    BOOST_CHECK(b==d/c);
    BOOST_CHECK((d/c==a)==false);
    BOOST_CHECK((a==d/c)==false);
}


void unariy_plus_test() {
    public_unsigned a(1);
    BOOST_CHECK(+a==a);
}

void unariy_minus_test() {
    public_unsigned a(1);
    BOOST_CHECK(-a==public_unsigned(-1));
}

void pre_increment_test() {
    public_unsigned a(1);
    public_unsigned b(2);
    BOOST_CHECK(++a==b);
}

void post_increment_test() {
    public_unsigned a(1);
    public_unsigned b(1);
    BOOST_CHECK(a++==b);
    BOOST_CHECK(a==public_unsigned(2));
}

test_suite* init_unit_test_suite(int, char*[])
{
  test_suite* test = BOOST_TEST_SUITE("public");

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
