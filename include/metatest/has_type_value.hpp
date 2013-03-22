#ifndef METATEST_HAS_TYPE_VALUE_HPP
#define METATEST_HAS_TYPE_VALUE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <metatest/to_stream_fwd.hpp>
#include <metatest/has_value.hpp>
#include <metatest/get_type.hpp>

namespace metatest
{
  template <class T, class ValueType>
  struct has_type_value :
    has_value<typename get_type<T, int>::type, ValueType>
  {};
}

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  2,
  metatest::has_type_value,
  "has_type_value"
)

#endif

