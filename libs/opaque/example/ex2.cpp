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
using namespace boost::opaque;
using namespace boost::unit_test;


BOOST_OPAQUE_PRIVATE_TYPEDEF(unsigned,game_score);

game_score accumulate( game_score g1, game_score g2 ) {
 return g1 + g2;
}

BOOST_OPAQUE_PUBLIC_TYPEDEF(unsigned,serial_number);


serial_number next_id( serial_number n ) {
 return n + serial_number(1u);
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


test_suite* init_unit_test_suite(int, char*[])
{
  test_suite* test = BOOST_TEST_SUITE("ex2");
  test->add(BOOST_TEST_CASE(&accumulate_test));
  test->add(BOOST_TEST_CASE(&next_id_test));

  return test;
}


