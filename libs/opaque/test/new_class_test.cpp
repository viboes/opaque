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


struct private_unsigned :
    boost::opaque::new_class<private_unsigned, unsigned
    , boost::mpl::vector<opaque::using_equality_comparable<>
    >
    >
{
    typedef
    boost::opaque::new_class<private_unsigned, unsigned
    , boost::mpl::vector<opaque::using_equality_comparable<>
    >
    >
    base_type;

    private_unsigned(){}
    explicit private_unsigned(unsigned v) : base_type(v) {}
    template <typename W>
    explicit private_unsigned(W w)
        : base_type(w)
    {}
    private_unsigned(private_unsigned const& r)
        : base_type(r.val_)
    {}
};

struct private_unsigned2: boost::opaque::new_class<private_unsigned2, unsigned>
{
    typedef boost::opaque::new_class<private_unsigned2, unsigned> base_type;

    private_unsigned2(){}
    explicit private_unsigned2(unsigned v) : base_type(v) {}
    template <typename W>
    explicit private_unsigned2(W w)
        : base_type(w)
    {}
    private_unsigned2(private_unsigned2 const& r)
        : base_type(r.val_)
    {}
};

void size_test() {

    BOOST_TEST(sizeof(private_unsigned)==sizeof(unsigned));
    BOOST_TEST(sizeof(private_unsigned2)==sizeof(unsigned));
}

void private_assign_test() {
    private_unsigned a, a2;
    private_unsigned2 b;

    //~ a=b; // error
    a=a2; // OK

    unsigned short i;

    i=opaque_static_cast<unsigned short>(a);
    //~ i=a; // error

    //~ a=i; // error
}

void private_eq_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_TEST(b==c);
    BOOST_TEST((a==b)==false);
}
void private_neq_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_TEST(a!=b);
    BOOST_TEST((b!=c)==false);
}
//~ void private_lt_test() {
    //~ private_unsigned a(1), b(2), c(2);
    //~ BOOST_TEST(a<b);
    //~ BOOST_TEST((b<a)==false);
    //~ BOOST_TEST((b<c)==false);
//~ }
#if 0

void private_gt_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_TEST(b>a);
    BOOST_TEST((a>b)==false);
    BOOST_TEST((b>c)==false);
}

void private_le_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_TEST(a<=b);
    BOOST_TEST((b<=a)==false);
    BOOST_TEST(b<=c);
}
void private_ge_test() {
    private_unsigned a(1), b(2), c(2);
    BOOST_TEST(b>=a);
    BOOST_TEST((a>=b)==false);
    BOOST_TEST(b>=c);
}

void private_add_test() {
    private_unsigned a(1), b(2), c(3),d(4);
    BOOST_TEST(a+b==c);
    BOOST_TEST(c==a+b);
    BOOST_TEST((a+b==d)==false);
    BOOST_TEST((d==a+b)==false);

    private_unsigned2 x;
    //~ a=a+x; // error

    //~ unsigned u=3,v=0;
    //~ BOOST_TEST(a+b==3u);
    //~ BOOST_TEST(u==a+b);
    //~ BOOST_TEST(a+b==u);
    //~ BOOST_TEST((a+b==v)==false);
    //~ BOOST_TEST((v==a+b)==false);

}

void private_substract_test() {
    private_unsigned a(1), b(2), c(3),d(4);
    BOOST_TEST(c-b==a);
    BOOST_TEST(a==c-b);
    BOOST_TEST((c-b==d)==false);
    BOOST_TEST((d==c-b)==false);

    //~ unsigned u=1,v=0;
    //~ BOOST_TEST(c-b==1u);
    //~ BOOST_TEST(u==c-b);
    //~ BOOST_TEST(c-b==u);
    //~ BOOST_TEST((c-b==v)==false);
    //~ BOOST_TEST((v==c-b)==false);

}


#endif

int main()
{

  //~ size_test();
  private_assign_test();
  private_eq_test();
  private_neq_test();
  //~ private_lt_test();
  //~ private_gt_test();
  //~ private_le_test();
  //~ private_ge_test();
  //~ private_add_test();
  //~ private_substract_test();

  return boost::report_errors();
}
