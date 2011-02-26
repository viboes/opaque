//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Vicente J. Botet Escriba 2010.
// Distributed under the Boost
// Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or
// copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/opaque for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_OPAQUE_NEW_CLASS_HPP
#define BOOST_OPAQUE_NEW_CLASS_HPP

#include <boost/opaque/meta_mixin/linear_hierarchy.hpp>

namespace boost {
namespace opaque {

    class base_new_type {};

    template <
        typename Final,
        typename T,
        typename MetaMixinSeq=boost::mpl::vector0<>,
        typename Base=base_new_type
    >
    class new_class : public linear_hierarchy<MetaMixinSeq, Final, Base>::type
    {
    public:
        typedef T underlying_type;

        template <typename W>
        explicit new_class(W v) : val_(v) {}
        new_class(){}
        new_class(const new_class & rhs) : val_(rhs.val_) {}
        explicit new_class(T v) : val_(v) {}
    protected:
        T val_;

    public:
        underlying_type const& underlying() const {
            return val_;
        }
        underlying_type& underlying() {
            return val_;
        }

        template<typename F>
        static underlying_type& underlying(F* f){
            return final(f).underlying();
        }

        template<typename F>
        static underlying_type const& underlying(F const* f){
            return final(f).underlying();
        }

        template<typename F>
        static Final const& final(F const* f)  {
            return static_cast<Final const&>(*f);
        }
        template<typename F>
        static Final& final(F* f) {
            return static_cast<Final&>(*f);
        }

    };
  }

    template <
        typename T,
        typename Final,
        typename UT,
        typename MetaMixinSeq,
        typename Base
    >
    T opaque_static_cast(opaque::new_class<Final, UT, MetaMixinSeq, Base> const& v)
    {
        return static_cast<T>(v.underlying());
    }

}


#endif
