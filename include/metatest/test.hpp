#ifndef METATEST_TEST_HPP
#define METATEST_TEST_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <metatest/test_driver.hpp>
#include <metatest/test_result.hpp>

#ifdef METATEST_ADD_TEST
  #error METATEST_ADD_TEST already defined
#endif
// We have to use a namespace not used anywhere else to avoid
// test cases being replaced by other classes in the background
#define METATEST_ADD_TEST(suite, name) \
  namespace metatest_test_cases \
  { \
    namespace \
    { \
      struct name##_executor \
      { \
        name##_executor() \
        { \
          metatest::test_driver::instance().add( \
            (suite), \
            metatest::test_result::build<name>(METATEST_HERE, #name) \
          ); \
        } \
        \
        static name##_executor instance; \
      }; \
      \
      name##_executor name##_executor::instance; \
    } \
  }

#endif

