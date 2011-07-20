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

// NEW_CLASS(NT,UT,(opaque::using_plus_assign))
struct NT :
    boost::opaque::new_class<NT, UT
    , boost::mpl::vector<
        boost::opaque::using_plus_assign 
    >
    >
{
    typedef
    boost::opaque::new_class<NT, UT
    , boost::mpl::vector<
        boost::opaque::using_plus_assign 
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

void same_test() {
  NT x(1);
  NT y(2);
  NT &z=(x+=y);
  BOOST_TEST(x.underlying()==3);
  BOOST_TEST(&x == &z);
}

#if 0
void ut1_test() {
  NT x(1);
  NT &z=(x+=2);
  BOOST_TEST(x.underlying()==3);
  BOOST_TEST(&x == &z);
}

void ut2_test() {
  UT x = 1;
  NT y(2);
  UT &z=(x+=y);
  BOOST_TEST(x.underlying()==3);
  BOOST_TEST(&x == &z);
}
#endif

int main()
{
  size_test();
  same_test();
  //ut1_test();
  //ut2_test();

  return boost::report_errors();
}
