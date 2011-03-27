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

void equal_test() {
    NT a1(1), b2(2), c2(2);
    BOOST_TEST(b2==c2);
    BOOST_TEST((b2==a1)==false);
}

int main()
{

  size_test();
  equal_test();

  return boost::report_errors();
}
