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

#if 0
typedef int Int;

bool gt(Int a, Int b)
{
    if(a) return a > b;  // 1 don't fails even if a is not a bool
    else return 0;       // 2 don't fails even if 0 is not a bool
} 
#else
struct private_unsigned_tag;
typedef boost::new_type<unsigned, private_unsigned_tag, boost::mpl::vector<
    opaque::using_totally_ordered1<opaque::boolean> 
> > Int;
//~ BOOST_OPAQUE_PRIVATE_TYPEDEF(int, Int);

opaque::boolean gt(Int a, Int b)
{
    if(a!=Int(0)) return a > b;  // 1
    else return opaque::false_;       // 2
} 
#endif

    
void t() {
    BOOST_CHECK(gt(Int(1),Int(0)));
}

test_suite* init_unit_test_suite(int, char*[])
{
  test_suite* test = BOOST_TEST_SUITE("ex1");

  test->add(BOOST_TEST_CASE(&t));

  return test;
}


