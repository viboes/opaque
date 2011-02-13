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

BOOST_OPAQUE_PUBLIC_TYPEDEF(unsigned,public_unsigned);
BOOST_OPAQUE_PUBLIC_TYPEDEF(unsigned,public_unsigned2);

void size_test() {

    BOOST_TEST(sizeof(public_unsigned)==sizeof(unsigned));
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
    BOOST_TEST(b==c);
    BOOST_TEST((a==b)==false);

    unsigned u=1,v=2;
    BOOST_TEST(a==1u);
    BOOST_TEST(u==a);
    BOOST_TEST(a==u);
    BOOST_TEST((a==v)==false);
    BOOST_TEST((v==a)==false);
}

void neq_test() {
    public_unsigned a(1), b(2), c(2);
    BOOST_TEST(a!=b);
    BOOST_TEST((b!=c)==false);
}


void lt_test() {
    public_unsigned a(1), b(2), c(2);
    BOOST_TEST(a<b);
    BOOST_TEST((b<a)==false);
    BOOST_TEST((b<c)==false);
}

void gt_test() {
    public_unsigned a(1), b(2), c(2);
    BOOST_TEST(b>a);
    BOOST_TEST((a>b)==false);
    BOOST_TEST((b>c)==false);
}

void le_test() {
    public_unsigned a(1), b(2), c(2);
    BOOST_TEST(a<=b);
    BOOST_TEST((b<=a)==false);
    BOOST_TEST(b<=c);
}
void ge_test() {
    public_unsigned a(1), b(2), c(2);
    BOOST_TEST(b>=a);
    BOOST_TEST((a>=b)==false);
    BOOST_TEST(b>=c);
}

void add_test() {
    public_unsigned a(1), b(2), c(3),d(4);
    BOOST_TEST(a+b==c);
    BOOST_TEST(c==a+b);
    BOOST_TEST((a+b==d)==false);
    BOOST_TEST((d==a+b)==false);

    //~ public_unsigned2 x;
    //~ a=a+x; // error

    unsigned u=3,v=0;
    BOOST_TEST(a+b==3u);
    BOOST_TEST(u==a+b);
    BOOST_TEST(a+b==u);
    BOOST_TEST((a+b==v)==false);
    BOOST_TEST((v==a+b)==false);

}

void substract_test() {
    public_unsigned a(1), b(2), c(3),d(4);
    BOOST_TEST(c-b==a);
    BOOST_TEST(a==c-b);
    BOOST_TEST((c-b==d)==false);
    BOOST_TEST((d==c-b)==false);

    unsigned u=1,v=0;
    BOOST_TEST(c-b==1u);
    BOOST_TEST(u==c-b);
    BOOST_TEST(c-b==u);
    BOOST_TEST((c-b==v)==false);
    BOOST_TEST((v==c-b)==false);

}

void multiply_test() {
    public_unsigned a(1), b(2), c(3),d(6);
    BOOST_TEST(b*c==d);
    BOOST_TEST(b==a*b);
    BOOST_TEST((b*c==a)==false);
    BOOST_TEST((d==a*b)==false);
}

void divide_test() {
    public_unsigned a(1), b(2), c(3),d(6);
    BOOST_TEST(d/c==b);
    BOOST_TEST(b==d/c);
    BOOST_TEST((d/c==a)==false);
    BOOST_TEST((a==d/c)==false);
}


void unariy_plus_test() {
    public_unsigned a(1);
    BOOST_TEST(+a==a);
}

void unariy_minus_test() {
    public_unsigned a(1);
    BOOST_TEST(-a==public_unsigned(-1));
}

void pre_increment_test() {
    public_unsigned a(1);
    public_unsigned b(2);
    BOOST_TEST(++a==b);
}

void post_increment_test() {
    public_unsigned a(1);
    public_unsigned b(1);
    BOOST_TEST(a++==b);
    BOOST_TEST(a==public_unsigned(2));
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
