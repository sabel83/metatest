#ifndef METATEST_TO_STREAM_ARGUMENT_LIST_HPP
#define METATEST_TO_STREAM_ARGUMENT_LIST_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <metatest/to_stream_fwd.hpp>

#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

#include <iostream>

namespace metatest
{
  #ifndef METATEST_TO_STREAM_ARGUMENT_LIST_MAX_ARG
    #define MEATEST_TO_STREAM_ARGUMENT_LIST_MAX_ARG 20
  #endif
  
  struct to_stream_argument_list_no_arg;
  
  namespace impl
  {
    template <int N, class T>
    struct to_stream_arg
    {
      static void run(std::ostream& o)
      {
        if (N > 0)
        {
          o << ", ";
        }
        to_stream<T>::run(o);
      }
    };

    template <int N>
    struct to_stream_arg<N, metatest::to_stream_argument_list_no_arg>
    {
      static void run(std::ostream&) {}
    };
  }

  #ifdef METATEST_TO_STREAM_CASE
    #error METATEST_TO_STREAM_CASE already defined
  #endif
  #define METATEST_TO_STREAM_CASE(z, n, unused) \
    metatest::impl::to_stream_arg<n, T##n>::run(o);
  
  template <
    BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
      METATEST_TO_STREAM_ARGUMENT_LIST_MAX_ARG,
      class T,
      to_stream_argument_list_no_arg
    )
  >
  struct to_stream_argument_list
  {
    static std::ostream& run(std::ostream& o)
    {
      BOOST_PP_REPEAT(
        METATEST_TO_STREAM_ARGUMENT_LIST_MAX_ARG,
        METATEST_TO_STREAM_CASE,
        ~
      );
      return o;
    }
    
    struct to_stream
    {
      static std::ostream& run(std::ostream& o)
      {
        o << "to_stream_argument_list<";
        to_stream_argument_list<
          BOOST_PP_ENUM_PARAMS(METATEST_TO_STREAM_ARGUMENT_LIST_MAX_ARG, T)
        >::run(o);
        return o << ">";
      }
    };
  };
  
  #undef METATEST_TO_STREAM_CASE
}

#endif

