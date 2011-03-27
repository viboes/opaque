//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Vicente J. Botet Escriba 2010. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/opaque for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#include <boost/opaque/macros/new_class.hpp>
#include <boost/opaque/meta_mixin/operators.hpp>

#include <boost/detail/lightweight_test.hpp>

using namespace boost;

typedef int UT;
typedef short UT2;

#ifdef BOOST_OPAQUE_NEW_CLASS

struct NT : public
BOOST_OPAQUE_NEW_CLASS(NT,UT,(opaque::using_not_equal<>))
{
  BOOST_OPAQUE_FORWARD_CONSTRUCTORS(NT,BOOST_OPAQUE_NEW_CLASS(NT,UT,(opaque::using_not_equal<>)));

};
#else
struct NT : public
    boost::opaque::new_class<NT, UT
    , boost::mpl::vector<
        boost::opaque::using_not_equal<>
    >
    >
{
    typedef
    boost::opaque::new_class<NT, UT
    , boost::mpl::vector<
        boost::opaque::using_not_equal<>
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
#endif


void size_test() {
    BOOST_TEST(sizeof(NT)==sizeof(UT));
}


void not_equal_test() {
    NT a1(1), b2(2), c2(2);
    BOOST_TEST(a1!=c2);
    BOOST_TEST((b2!=c2)==false);
}

int main()
{

  size_test();
  not_equal_test();

  return boost::report_errors();
}
