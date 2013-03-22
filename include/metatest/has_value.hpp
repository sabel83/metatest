#ifndef METATEST_HAS_VALUE_HPP
#define METATEST_HAS_VALUE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <metatest/to_stream_fwd.hpp>
#include <metatest/yes.hpp>
#include <metatest/no.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/always.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/integral_c.hpp>

namespace metatest
{
  // Based on C++ Template Metaprogramming, chapter 9.10
  template <class F, class ValueType>
  struct has_value
  {
    struct type
    {
      template <ValueType Value_>
      struct value_wrapper;
      
      // It needs an extra int argument to remove ambiguity between
      // this version and the one with ...
      template <class T>
      static
        typename
          boost::mpl::apply_wrap1<
            boost::mpl::always<yes>,
            boost::mpl::integral_c<ValueType, T::value>
          >::type
        tester(T*, int);
    
      // I have to pass a T* argument to make Visual C++ accept it
      template <class T>
      static no tester(T*, ...);
    
      static const bool
        value =
          sizeof(
            has_value<F, ValueType>::type::tester(static_cast<F*>(0), 13)
          )
          == sizeof(yes);
    };
  };
}

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, metatest::has_value, "has_value")

#endif

