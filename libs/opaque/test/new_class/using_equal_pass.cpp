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

#include <boost/detail/lightweight_test.hpp>

using namespace boost;

typedef int UT;
typedef short UT2;

// NEW_CLASS(NT,UT,(opaque::using_equal<>))
struct NT : 
    boost::opaque::new_class<NT, UT
    , boost::mpl::vector<
    	boost::opaque::using_equal<> 
    >
    >
{
    typedef 
    boost::opaque::new_class<NT, UT
    , boost::mpl::vector<
    	boost::opaque::using_equal<> 
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
    BOOST_TEST(sizeof(NT)==sizeof(UT));
}
#if 0
void default_constructor_test() {
	NT a;
}
void copy_from_ut_test() {
	UT ut(1);
	NT a(ut);
    BOOST_TEST(a.underlying()==ut);
}
void copy_from_ut2_test() {
	UT2 ut(1);
	NT a(ut);
    BOOST_TEST(a.underlying()==ut);
}
void copy_constructor_test() {
	NT a(1);
	NT b(a);
    BOOST_TEST(a.underlying()==b.underlying());
}

void assign_test() {
	NT a1, a2(2);
    a1=a2; // OK
    BOOST_TEST(a1.underlying()==a2.underlying());
}

void opaque_static_cast_test() {
	NT a(1);
    UT2 i;
    i=opaque_static_cast<UT2>(a);
    BOOST_TEST(i==a.underlying());
}
#endif
void equal_test() {
    NT a1(1), b2(2), c2(2);
    BOOST_TEST(b2==c2);
    BOOST_TEST((b2==a1)==false);
}

int main()
{

  size_test();
#if 0
  default_constructor_test();
  copy_from_ut_test();
  copy_from_ut2_test();
  copy_constructor_test();
  assign_test();
  opaque_static_cast_test();
#endif  
  equal_test();

  return boost::report_errors();
}
