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

#include <boost/mpl/vector.hpp>
#include <boost/mpl/fold.hpp>

namespace boost {

    class base_new_type {};

    ////// implementation //////
    namespace detail{

    template<typename NT, typename UT, typename State, typename Concept>
    struct do_inhetit : Concept::template type<NT, UT, State> {
    };

    template<typename NT, typename UT>
    struct inherit {
        template<typename State, typename Concept>
        struct apply{
            typedef do_inhetit<NT, UT, State, Concept> type;
        };
    };

    }
    template <typename T, typename Tag, typename Concepts=boost::mpl::vector0<>, typename Base=base_new_type>
    class new_type 
        : public 
            boost::mpl::fold<Concepts, Base, detail::inherit<new_type<T, Tag, Concepts, Base>, T> >::type
    {
        typedef typename 
            boost::mpl::fold<Concepts, Base, detail::inherit<new_type<T, Tag, Concepts, Base>, T> >::type
        base_type;

    public:
        typedef T underlying_type;

        template <typename W>
        explicit new_type(W v) : val_(v) {}
        new_type(){}
        new_type(const new_type & rhs) : val_(rhs.val_) {}
        explicit new_type(T v) : val_(v) {}
        //~ new_type & operator=(const new_type & rhs) {
            //~ val_ = rhs.val_; return *this;
        //~ }
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
        static new_type const& final(F const* f)  {
            return static_cast<new_type const&>(*f);
        }
        template<typename F>
        new_type& final(F* f) {
            return static_cast<new_type&>(*f);
        }

    };

    template <typename T, typename UT, typename Base, typename Tag >
    T opaque_static_cast(new_type<UT, Base,Tag> const& v)
    {
        return static_cast<T>(v.underlying());
    }

}


#endif
