#ifndef METATEST_GET_TYPE_VALUE_HPP
#define METATEST_GET_TYPE_VALUE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <metatest/get_value.hpp>
#include <metatest/get_type.hpp>

#include <boost/mpl/identity.hpp>

#include <metatest/to_stream_fwd.hpp>

namespace metatest
{
  template <class T, class Default>
  struct get_type_value :
    get_value<
      typename get_type<T, boost::mpl::identity<Default> >::type,
      Default
    >
  {};
}

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  2,
  metatest::get_type_value,
  "get_type_value"
)

#endif

