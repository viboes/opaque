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

void public_assign_test() {
    public_unsigned a, a2;
    public_unsigned2 b;

    //~ a=b; // error
    a=a2; // OK

    unsigned i;

    i=a;
    i=b;
    //~ a=i; // error
    //~ b=i; // error
}

void public_eq_test() {
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

void public_lt_test() {
    public_unsigned a(1), b(2), c(2);
    BOOST_CHECK(a<b);
    BOOST_CHECK((b<a)==false);
    BOOST_CHECK((b<c)==false);
}

void public_gt_test() {
    public_unsigned a(1), b(2), c(2);
    BOOST_CHECK(b>a);
    BOOST_CHECK((a>b)==false);
    BOOST_CHECK((b>c)==false);
}

void public_le_test() {
    public_unsigned a(1), b(2), c(2);
    BOOST_CHECK(a<=b);
    BOOST_CHECK((b<=a)==false);
    BOOST_CHECK(b<=c);
}
void public_ge_test() {
    public_unsigned a(1), b(2), c(2);
    BOOST_CHECK(b>=a);
    BOOST_CHECK((a>=b)==false);
    BOOST_CHECK(b>=c);
}

void public_add_test() {
    public_unsigned a(1), b(2), c(3),d(4);
    BOOST_CHECK(a+b==c);
    BOOST_CHECK(c==a+b);
    BOOST_CHECK((a+b==d)==false);
    BOOST_CHECK((d==a+b)==false);

    public_unsigned2 x;
    //~ a=a+x; // error

    unsigned u=3,v=0;
    BOOST_CHECK(a+b==3u);
    BOOST_CHECK(u==a+b);
    BOOST_CHECK(a+b==u);
    BOOST_CHECK((a+b==v)==false);
    BOOST_CHECK((v==a+b)==false);

}

void public_substract_test() {
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


test_suite* init_unit_test_suite(int, char*[])
{
  test_suite* test = BOOST_TEST_SUITE("public");

  test->add(BOOST_TEST_CASE(&public_assign_test));
  test->add(BOOST_TEST_CASE(&public_eq_test));
  test->add(BOOST_TEST_CASE(&public_lt_test));
  test->add(BOOST_TEST_CASE(&public_gt_test));
  test->add(BOOST_TEST_CASE(&public_le_test));
  test->add(BOOST_TEST_CASE(&public_ge_test));
  test->add(BOOST_TEST_CASE(&public_add_test));
  test->add(BOOST_TEST_CASE(&public_substract_test));

  return test;
}


