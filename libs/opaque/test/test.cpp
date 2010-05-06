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


//~ struct game_score: public_opaque_type<game_score, unsigned>
struct game_score: private_opaque_type<game_score, unsigned>
{
    // forward constructors
    game_score(){}
    template <typename T>
    // explicit game_score(T v) : public_opaque_type<game_score, unsigned>(v) {}
    explicit game_score(T v) : private_opaque_type<game_score, unsigned>(v) {}
    //BOOST_OPAQUE_PRIVATE_OPERATIONS(game_score,unsigned);
};    

BOOST_OPAQUE_PRIVATE_TYPEDEF(unsigned,game_score);

game_score accumulate( game_score g1, game_score g2 ) {
 return g1 + g2;
}

struct serial_number: public_opaque_type<serial_number, unsigned>
{
    // forward constructors
    serial_number(){}
    template <typename T>
    explicit serial_number(T v) : public_opaque_type<serial_number, unsigned>(v) {}
};    
//~ BOOST_OPAQUE_PUBLIC_TYPEDEF(unsigned,serial_number);
    

serial_number next_id( serial_number n ) {
 //return static_cast<serial_number>(n + 1u);
 // return opaque_static_cast<serial_number>(n + 1u);
 return serial_number(n + 1u);
}

void accumulate_test() {
    game_score gs1(1), gs2(2), res;
    res= accumulate(gs1,gs2);
    BOOST_CHECK(gs1<gs2);
    BOOST_CHECK(gs1<=gs2);
    BOOST_CHECK(gs2>=gs1);
    BOOST_CHECK(res==game_score(3));
    BOOST_CHECK(game_score(3)==res);
    
    game_score res2;
    res2=res+res;
    BOOST_CHECK(res+res==game_score(6));
}

void next_id_test() {
    serial_number sn(1), res;
    res= next_id(sn);
    BOOST_CHECK(res==serial_number(2));
    BOOST_CHECK(serial_number(2)==res);
    
    BOOST_CHECK(res+res==serial_number(4));
    
    BOOST_CHECK(sn<res);
}

//~ void mix_test_fail() {
    //~ game_score sn(1), res;
    //~ res= next_id(sn);
    //~ BOOST_CHECK(serial_number(3)==game_score(3));
//~ }


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

BOOST_OPAQUE_PRIVATE_TYPEDEF(unsigned,private_unsigned);
BOOST_OPAQUE_PRIVATE_TYPEDEF(unsigned,private_unsigned2);

void private_assign_test() {
    private_unsigned a, a2;
    private_unsigned2 b;
        
    //~ a=b; // error
    a=a2; // OK
    
    unsigned i;
    
    i=opaque_static_cast(a);
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
    public_unsigned a(1), b(2), c(3),d(4);
    BOOST_CHECK(a+b==c);
    BOOST_CHECK(c==a+b);
    BOOST_CHECK((a+b==d)==false);
    BOOST_CHECK((d==a+b)==false);

    public_unsigned2 x;
    //~ a=a+x; // error
    
    //~ unsigned u=3,v=0;
    //~ BOOST_CHECK(a+b==3u);
    //~ BOOST_CHECK(u==a+b);
    //~ BOOST_CHECK(a+b==u);
    //~ BOOST_CHECK((a+b==v)==false);
    //~ BOOST_CHECK((v==a+b)==false);
    
}

void private_substract_test() {
    public_unsigned a(1), b(2), c(3),d(4);
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

// Listing 7
BOOST_OPAQUE_PRIVATE_TYPEDEF(double,mass1_leng2_per_time2);
BOOST_OPAQUE_PUBLIC_TYPEDEF(mass1_leng2_per_time2,energy);
BOOST_OPAQUE_PUBLIC_TYPEDEF(energy,kinetic_energy);
BOOST_OPAQUE_PUBLIC_TYPEDEF(energy,potential_energy);
BOOST_OPAQUE_PUBLIC_TYPEDEF(energy,heat_energy);

double sqrt(double d) { return d;}
void public_multiple_levels_test() {
    //~ double d;
    mass1_leng2_per_time2 x;
    energy e;
    kinetic_energy k;
    potential_energy p, q;
      
    p = p + q; // ok
    e = p + q; // ok
    //~ x = p + q; // error two levels
    //~ test.cpp:287: error: no match for 'operator=' in 'x = boost::operator+(const potential_energy&, const potential_energy&)(((const potential_energy&)((const potential_energy*)(& q))))'
    //~ test.cpp:270: note: candidates are: mass1_leng2_per_time2& mass1_leng2_per_time2::operator=(const mass1_leng2_per_time2&)
    
    //~ e = k + p; // ok!!! error
    //~ test.cpp:287: error: ambiguous overload for 'operator+' in 'k + p'
    //~ ..\..\../boost/operators.hpp:255: note: candidates are: energy boost::operator+(const energy&, const energy&)
    //~ ..\..\../boost/operators.hpp:255: note:                 energy boost::operator+(const kinetic_energy&, const energy&)
    //~ ..\..\../boost/operators.hpp:255: note:                 energy boost::operator+(const energy&, const potential_energy&)    
    
    //~ k = p + q; // error
    //~ test.cpp:297: error: no match for 'operator=' in 'k = boost::operator+(const potential_energy&, const potential_energy&)(((const potential_energy&)((const potential_energy*)(& q))))'
    //~ test.cpp:272: note: candidates are: kinetic_energy& kinetic_energy::operator=(const kinetic_energy&)
    
    //~ d = sqrt(e); // error
    //~ test.cpp:302: error: cannot convert 'energy' to 'double' for argument '1' to 'double sqrt(double)'
}

test_suite* init_unit_test_suite(int, char*[])
{
  test_suite* test = BOOST_TEST_SUITE("ex1");
  test->add(BOOST_TEST_CASE(&accumulate_test));
  test->add(BOOST_TEST_CASE(&next_id_test));
  test->add(BOOST_TEST_CASE(&public_multiple_levels_test));
    
  test->add(BOOST_TEST_CASE(&public_assign_test));
  test->add(BOOST_TEST_CASE(&public_eq_test));
  test->add(BOOST_TEST_CASE(&public_lt_test));
  test->add(BOOST_TEST_CASE(&public_gt_test));
  test->add(BOOST_TEST_CASE(&public_le_test));
  test->add(BOOST_TEST_CASE(&public_ge_test));
  test->add(BOOST_TEST_CASE(&public_add_test));
  test->add(BOOST_TEST_CASE(&public_substract_test));

    
  test->add(BOOST_TEST_CASE(&private_assign_test));
  test->add(BOOST_TEST_CASE(&private_eq_test));
  test->add(BOOST_TEST_CASE(&private_lt_test));
  test->add(BOOST_TEST_CASE(&private_gt_test));
  test->add(BOOST_TEST_CASE(&private_le_test));
  test->add(BOOST_TEST_CASE(&private_ge_test));
  test->add(BOOST_TEST_CASE(&private_add_test));
  test->add(BOOST_TEST_CASE(&private_substract_test));
    
  return test;
}


