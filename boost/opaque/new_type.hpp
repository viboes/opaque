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

#ifndef BOOST_OPAQUE_NEW_TYPE_HPP
#define BOOST_OPAQUE_NEW_TYPE_HPP

namespace boost {

    class base_new_type {};


    // T the underlying type must be regular
    template <typename Final, typename T, typename Base=base_new_type >
    class new_type : public Base
    {
    public:
        typedef T underlying_type;

        template <typename W>
        explicit new_type(W v) : val_(v) {}
        new_type(){}
        new_type(const new_type & rhs) : val_(rhs.val_) {}
        explicit new_type(T v) : val_(v) {}
    protected:
        T val_;
        new_type & operator=(const new_type & rhs) {
            val_ = rhs.val_; return *this;
        }

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
        Final& final(F* f) {
            return static_cast<Final&>(*f);
        }

    };

    template <typename T, typename Final, typename UT, typename Base >
    T opaque_static_cast(new_type<Final, UT, Base> const& v)
    {
        return static_cast<T>(v.underlying());
    }

}


#endif
