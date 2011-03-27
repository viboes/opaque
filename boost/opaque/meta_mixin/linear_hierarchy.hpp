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

/**
 * @file
 * Defines the @c linear_hierarchy meta-function.
 */

#ifndef BOOST_OPAQUE_LINEAR_HIERARCHY_HPP
#define BOOST_OPAQUE_LINEAR_HIERARCHY_HPP

#include <boost/mpl/vector.hpp>
#include <boost/mpl/fold.hpp>

namespace boost {
namespace opaque {

#ifndef BOOST_OPAQUE_DOXYGEN_INVOKED
    namespace opaque_detail {

    template<typename Final, typename State, typename MetaMixin>
    struct do_inhetit : MetaMixin::template type< Final, State> {
    };

    template<typename Final>
    struct inherit {
        template<typename State, typename MetaMixin>
        struct apply{
            typedef do_inhetit< Final, State, MetaMixin> type;
        };
    };

    }
#endif

    /** The linear_hierarchy metafunction gererates a linear hierarchy by folding the Mixins obtained by application of the MetaMixins in MetaMixinSeq.
     *
     * The nested type is equivalent to typename boost::mpl::fold<MetaMixinSeq, Base, implementation_defined<Final> >::type.
     */

    template<typename MetaMixinSeq, typename Final, typename Base>
    struct linear_hierarchy {
        typedef typename boost::mpl::fold<MetaMixinSeq, Base, 
            opaque_detail::inherit<Final> >::type type;
    };
}
}


#endif
