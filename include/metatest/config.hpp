#ifndef METATEST_CONFIG_HPP
#define METATEST_CONFIG_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/config.hpp>

#ifdef METATEST_SOURCE
  #define METATEST_DECL BOOST_SYMBOL_EXPORT
#else
  #define METATEST_DECL BOOST_SYMBOL_IMPORT
#endif

#endif

