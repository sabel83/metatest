#ifndef METATEST_HAS_TYPE_HPP
#define METATEST_HAS_TYPE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <metatest/to_stream_fwd.hpp>

#include <boost/mpl/has_xxx.hpp>

namespace metatest
{
  BOOST_MPL_HAS_XXX_TRAIT_DEF(type)
}

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, metatest::has_type, "has_type")

#endif

