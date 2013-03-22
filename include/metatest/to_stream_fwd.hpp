#ifndef METATEST_METATEST_TO_STREAM_FWD_HPP
#define METATEST_METATEST_TO_STREAM_FWD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/array/elem.hpp>

#include <iostream>

namespace metatest
{
  template <class T>
  struct to_stream;
}

#ifdef METATEST_DEFINE_TO_STREAM_FOR_TYPE
  #error METATEST_DEFINE_TO_STREAM_FOR_TYPE already defined
#endif
#define METATEST_DEFINE_TO_STREAM_FOR_TYPE(t, name) \
  namespace metatest \
  { \
    template <> \
    struct to_stream<t> \
    { \
      typedef to_stream type; \
      \
      static std::ostream& run(std::ostream& o_) \
      { \
        return o_ << name; \
      } \
    }; \
  }

#ifdef METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE
  #error METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE already defined
#endif
#define METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(t) \
  METATEST_DEFINE_TO_STREAM_FOR_TYPE(t, #t)

// "if"'s condition will be a compile-time constant expression.
#ifdef METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_N
  #error METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_N already defined
#endif
#define METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_N(z, n, unused) \
  if ((n) > 0) { \
    o_ << ", "; \
  } \
  to_stream<A##n>::run(o_);

#ifdef METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE
  #error METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE already defined
#endif
#define METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(n, t, name) \
  namespace metatest \
  { \
    template <BOOST_PP_ENUM_PARAMS(n, class A)> \
    struct to_stream<t<BOOST_PP_ENUM_PARAMS(n, A)> > \
    { \
      typedef to_stream type; \
      \
      static std::ostream& run(std::ostream& o_) \
      { \
        o_ << name << "<"; \
        BOOST_PP_REPEAT(n, METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_N, ~) \
        return o_ << ">"; \
      } \
    }; \
  }

#ifdef METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_WITH_DEFAULTS_N
  #error METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_WITH_DEFAULTS_N already defined
#endif
#define METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_WITH_DEFAULTS_N(z, n, args) \
  METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE( \
    n, \
    BOOST_PP_ARRAY_ELEM(0, args), \
    BOOST_PP_ARRAY_ELEM(1, args) \
  )

#ifdef METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_WITH_DEFAULTS
  #error METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_WITH_DEFAULTS already defined
#endif
#define METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_WITH_DEFAULTS( \
  n_min, \
  n_max, \
  t, \
  name \
) \
  BOOST_PP_REPEAT_FROM_TO( \
    n_min, \
    n_max, \
    METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_WITH_DEFAULTS_N, \
    (2, (t, name))\
  )


METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  metatest::to_stream,
  "to_stream"
)

#endif

