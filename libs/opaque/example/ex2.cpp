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
using namespace boost::opaque;


BOOST_OPAQUE_PRIVATE_TYPEDEF(unsigned,game_score);
//BOOST_OPAQUE_INHERIT_FROM_UNDERLYING(game_score)

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
    BOOST_TEST(gs1<gs2);
    BOOST_TEST(gs1<=gs2);
    BOOST_TEST(gs2>=gs1);
    BOOST_TEST(res==game_score(3));
    BOOST_TEST(game_score(3)==res);

    game_score res2;
    res2=res+res;
    BOOST_TEST(res+res==game_score(6));
}

void next_id_test() {
    serial_number sn(1), res;
    res= next_id(sn);
    BOOST_TEST(res==serial_number(2));
    BOOST_TEST(serial_number(2)==res);

    BOOST_TEST(res+res==serial_number(4));

    BOOST_TEST(sn<res);
}

//~ void mix_test_fail() {
    //~ game_score sn(1), res;
    //~ res= next_id(sn);
    //~ BOOST_TEST(serial_number(3)==game_score(3));
//~ }


int main()
{
  accumulate_test();
  next_id_test();

  return boost::report_errors();
}


