#ifndef METATEST_SUITE_PATH_HPP
#define METATEST_SUITE_PATH_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <metatest/config.hpp>

#include <string>
#include <list>

namespace metatest
{
  class suite_path
  {
  private:
    typedef std::list<std::string> elements;
  public:
    typedef elements::const_iterator iterator;
    
    METATEST_DECL suite_path();
    METATEST_DECL suite_path(const std::string& p_);
    METATEST_DECL suite_path(const std::list<std::string>& p_);
    
    METATEST_DECL iterator begin() const;
    METATEST_DECL iterator end() const;
    
    METATEST_DECL suite_path operator()(const std::string& e_) const;
  private:
    elements _elements;
  };
}

#endif

