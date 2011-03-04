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

#ifndef BOOST_OPAQUE_NEW_CLASS_MACRO_HPP
#define BOOST_OPAQUE_NEW_CLASS_MACRO_HPP

#include <boost/config.hpp>
#include <boost/opaque/new_class.hpp>
#include <boost/opaque/macros.hpp>
#include <boost/preprocessor/seq/enum.hpp>

#define BOOST_OPAQUE_NEW_CLASS(NC, UT,MMSEQ)                \
  boost::opaque::new_class< NC, UT,       \
      boost::mpl::vector<                                   \
          BOOST_PP_SEQ_ENUM(MMSEQ)                          \
      > >


#endif
