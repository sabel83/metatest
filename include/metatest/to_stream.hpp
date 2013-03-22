#ifndef METATEST_TO_STREAM_HPP
#define METATEST_TO_STREAM_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <metatest/to_stream_fwd.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/tag.hpp>
#include <boost/mpl/eval_if.hpp>

namespace metatest
{
  template <class T>
  struct to_stream
  {
    typedef to_stream type;

    static std::ostream& run(std::ostream& o_)
    {
      // I can't use typeid, because it breaks for non-defined types
      return o_ << "???";
    }
  };
  
  template <class T>
  struct to_stream<T*>
  {
    typedef to_stream type;
    
    static std::ostream& run(std::ostream& o_)
    {
      return to_stream<T>::run(o_) << "*";
    }
  };

  template <class T>
  struct to_stream<T[]>
  {
    typedef to_stream type;
    
    static std::ostream& run(std::ostream& o_)
    {
      return to_stream<T>::run(o_) << "[]";
    }
  };

  template <class T>
  struct to_stream<T&>
  {
    typedef to_stream type;
    
    static std::ostream& run(std::ostream& o_)
    {
      return to_stream<T>::run(o_) << "&";
    }
  };

  template <class T>
  struct to_stream<const T>
  {
    typedef to_stream type;
    
    static std::ostream& run(std::ostream& o_)
    {
      return to_stream<T>::run(o_ << "const ");
    }
  };

  template <class T>
  struct to_stream<T* const>
  {
    typedef to_stream type;
    
    static std::ostream& run(std::ostream& o_)
    {
      return to_stream<T>::run(o_) << "* const";
    }
  };
}

METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(char)
METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(signed char)
METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(unsigned char)

METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(short)
METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(unsigned short)

METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(int)
METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(unsigned int)

METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(long)
METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(unsigned long)

METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(float)
METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(double)

METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(bool)

METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(void)

#ifndef METATEST_NO_TO_STREAM_MPL
#include <metatest/to_stream_mpl.hpp>
#endif

#endif

