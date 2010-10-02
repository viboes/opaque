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

#ifndef BOOST_OPAQUE_LINEAR_HIERARCHY_HPP
#define BOOST_OPAQUE_LINEAR_HIERARCHY_HPP

#include <boost/mpl/vector.hpp>
#include <boost/mpl/fold.hpp>

namespace boost {

    ////// implementation //////
    namespace detail{

    template<typename  Final, typename UT, typename State, typename MetaMixin>
    struct do_inhetit : MetaMixin::template type< Final, UT, State> {
    };

    template<typename  Final, typename UT>
    struct inherit {
        template<typename State, typename MetaMixin>
        struct apply{
            typedef do_inhetit< Final, UT, State, MetaMixin> type;
        };
    };

    }

    template<typename MetaMixinSeq, typename Final, typename UT, typename Base>
    struct linear_hierarchy {
        typedef typename boost::mpl::fold<MetaMixinSeq, Base, detail::inherit<Final, UT> >::type type;
    };

}


#endif
