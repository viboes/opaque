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

    template <typename Final, typename UT, typename Base=base_new_type>
    struct underlying_access : Base {
        typedef Base base_type;
        underlying_access() {}
        underlying_access(UT val) : base_type(val) {}
        template <typename W>
        explicit underlying_access(W v)
            : base_type(v)
        {}

        Final const& final() const {
            return static_cast<Final const&>(*this);
        }
        Final& final() {
            return static_cast<Final&>(*this);
        }
        UT const& underlying() const {
            return final().underlying();
        }
        UT& underlying() {
            return final().underlying();
        }
    };

    // Base must inherit from underlying_access<>
    // T the underlying type must be regular
    template <typename Final, typename T, typename Base=underlying_access<Final, T, base_new_type> >
    class new_type : public Base
    {
    public:
        typedef T underlying_type;

        template <typename W>
        explicit new_type(W v) : val_(v) {}
        new_type(){}
        //~ new_type(const new_type & rhs) : val_(rhs.val_) {}
        explicit new_type(T v) : val_(v) {}
    protected:
        T val_;
        //~ new_type & operator=(const new_type & rhs) {
            //~ val_ = rhs.val_; return *this;
        //~ }

    public:
        T const& underlying() const {
            return val_;
        }
        T& underlying() {
            return val_;
        }

    };


}


#endif
