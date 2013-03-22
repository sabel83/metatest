#ifndef METATEST_TEST_FIXTURE_HPP
#define METATEST_TEST_FIXTURE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <metatest/config.hpp>
#include <metatest/suite_path.hpp>
#include <metatest/test_result.hpp>

#include <string>
#include <map>
#include <list>
#include <iosfwd>

namespace metatest
{
  class test_driver;

  class test_suite
  {
  public:
    friend class test_driver;

    typedef std::map<std::string, test_suite> suite_map;
    typedef std::list<test_result> result_list;
    
    METATEST_DECL size_t failure_count() const;
    METATEST_DECL size_t count() const;
    
    METATEST_DECL const suite_map& suites() const;
    METATEST_DECL const result_list& results() const;
  private:
    suite_map _suites;
    result_list _results;

    void add(
      suite_path::iterator begin_,
      suite_path::iterator end_,
      const test_result& result_
    );
   };
}

#endif

