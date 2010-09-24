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

#ifndef BOOST_OPAQUE_OPAQUE_TYPE_HPP
#define BOOST_OPAQUE_OPAQUE_TYPE_HPP

#include <boost/opaque/new_type.hpp>
#include <boost/opaque/combined_operators.hpp>

namespace boost {    

    template <typename T, typename Final, typename Base>
    struct inherited_from_undelying {
        struct type : 
            boost::totally_ordered< Final
            , boost::integer_arithmetic< Final
              , boost::bitwise< Final
                , boost::unit_steppable< Final
                  , opaque::ope::less_than<Final
                    , opaque::ope::equal<Final
                      , opaque::ope::plus_assign<Final
                        , opaque::ope::minus_assign<Final
                          , opaque::ope::multiply_assign<Final
                            , opaque::ope::divide_assign<Final
                              , opaque::ope::modulus_assign<Final
                                , underlying_access< Final, T, Base >
                              >
                            >
                          >
                        >
                      >
                    >
                  >
                >
              >
            >
          >
        {};  

    };
    
    template <typename Final, typename T, typename Base>
    class opaque_type : public new_type<Final, T, typename inherited_from_undelying<T, Final, Base>::type >
    {
    public:
        typedef
            new_type<Final, T, typename inherited_from_undelying<T, Final, Base>::type > base_type;

        template <typename W>
        explicit opaque_type(W v)
            : base_type(v)
        {
        }

        opaque_type() {}
        opaque_type(const opaque_type & rhs) : base_type(rhs.val_) {}
        opaque_type(const Final & rhs) : base_type(rhs.val_){}
        explicit opaque_type(T v) : base_type(v) {}
            
    };



}


#endif
