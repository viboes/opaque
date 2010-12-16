//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Vicente J. Botet Escriba 2010. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/opaque for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#include <boost/opaque/new_class.hpp>
#include <boost/opaque/meta_mixin/operators.hpp>

#include <boost/test/unit_test.hpp>

using namespace boost;
using namespace boost::unit_test;

typedef int UT;
typedef short UT2;

// NEW_CLASS(NT,UT,(opaque::using_greater_than_equal<>))
struct NT : 
    boost::opaque::new_class<NT, UT
    , boost::mpl::vector<
    	boost::opaque::using_greater_than_equal<> 
    >
    >
{
    typedef 
    boost::opaque::new_class<NT, UT
    , boost::mpl::vector<
    	boost::opaque::using_greater_than_equal<> 
    >
    >
    base_type;
    
    NT(){} 
    explicit NT(unsigned v) : base_type(v) {}
    template <typename W> 
    explicit NT(W w) 
        : base_type(w) 
    {}
    NT(NT const& r) 
        : base_type(r.val_) 
    {}
};


void size_test() {
    BOOST_CHECK(sizeof(NT)==sizeof(UT));
}
#if 0
void default_constructor_test() {
	NT a;
}
void copy_from_ut_test() {
	UT ut(1);
	NT a(ut);
    BOOST_CHECK(a.underlying()==ut);
}
void copy_from_ut2_test() {
	UT2 ut(1);
	NT a(ut);
    BOOST_CHECK(a.underlying()==ut);
}
void copy_constructor_test() {
	NT a(1);
	NT b(a);
    BOOST_CHECK(a.underlying()==b.underlying());
}

void assign_test() {
	NT a1, a2(2);
    a1=a2; // OK
    BOOST_CHECK(a1.underlying()==a2.underlying());
}

void opaque_static_cast_test() {
	NT a(1);
    UT2 i;
    i=opaque_static_cast<UT2>(a);
    BOOST_CHECK(i==a.underlying());
}
#endif
void greater_than_equal_test() {
    NT a1(1), b2(2), c2(2);
    BOOST_CHECK(b2>=a1);
    BOOST_CHECK((a1>=b2)==false);
    BOOST_CHECK(b2>=c2);
}

test_suite* init_unit_test_suite(int, char*[])
{
  test_suite* test = BOOST_TEST_SUITE("new_class.greater_than_equal_pass");

  test->add(BOOST_TEST_CASE(&size_test));
#if 0
  test->add(BOOST_TEST_CASE(&default_constructor_test));
  test->add(BOOST_TEST_CASE(&copy_from_ut_test));
  test->add(BOOST_TEST_CASE(&copy_from_ut2_test));
  test->add(BOOST_TEST_CASE(&copy_constructor_test));
  test->add(BOOST_TEST_CASE(&assign_test));
  test->add(BOOST_TEST_CASE(&opaque_static_cast_test));
#endif  
  test->add(BOOST_TEST_CASE(&greater_than_equal_test));

  return test;
}
