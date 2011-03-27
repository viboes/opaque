//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Vicente J. Botet Escriba 2011.
// Distributed under the Boost
// Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or
// copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/opaque for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_OPAQUE_MACROS_NEW_CLASS_HPP
#define BOOST_OPAQUE_MACROS_NEW_CLASS_HPP

#include <boost/config.hpp>
#include <boost/opaque/new_class.hpp>
#include <boost/opaque/macros.hpp>
#include <boost/preprocessor/seq/enum.hpp>


/**

 @brief

 @Params
 @Param{NC,the new class to be defined }
 @Param{UT,the underlying type}
 @Param{MMSEQ,the META_MIXIN_SEQ sequence}

 @Result If @c MMSEQ is <c>( (MM1) ... ((MMn) )</c>
 @code
  boost::opaque::new_class< NC, UT,
      boost::mpl::vector<MM1, ..., MMn>
  >
 @endcode

 */

#define BOOST_OPAQUE_NEW_CLASS(NC, UT, MMSEQ)                \
  boost::opaque::new_class< NC, UT,       \
      boost::mpl::vector<                                   \
          BOOST_PP_SEQ_ENUM(MMSEQ)                          \
      > >


#endif // BOOST_OPAQUE_MACROS_NEW_CLASS_HPP
