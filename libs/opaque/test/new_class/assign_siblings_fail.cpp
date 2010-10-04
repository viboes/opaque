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

using namespace boost;

typedef unsigned UT;

// NEW_CLASS(NT1,UT)
struct NT1 : boost::new_class<NT1, UT> 
{
    typedef 
    boost::new_class<NT1, UT>
    base_type;
    
    NT1(){} 
    explicit NT1(unsigned v) : base_type(v) {}
    template <typename W> 
    explicit NT1(W w) 
        : base_type(w) 
    {}
    NT1(NT1 const& r) 
        : base_type(r.val_) 
    {}
};

// NEW_CLASS(NT2,UT)
struct NT2 : boost::new_class<NT2, UT> 
{
    typedef 
    boost::new_class<NT2, UT>
    base_type;
    
    NT2(){} 
    explicit NT2(unsigned v) : base_type(v) {}
    template <typename W> 
    explicit NT2(W w) 
        : base_type(w) 
    {}
    NT2(NT2 const& r) 
        : base_type(r.val_) 
    {}
};

void fail() {
    NT1 a;
    NT2 b(1);
    a=b; // compile error
}


