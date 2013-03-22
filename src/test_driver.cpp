// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define METATEST_SOURCE

#include <metatest/test_driver.hpp>
#include <metatest/test_suite.hpp>

#include <boost/test/utils/trivial_singleton.hpp>

using metatest::test_driver;
using metatest::test_suite;
using metatest::test_result;
using metatest::suite_path;

test_driver& test_driver::instance()
{
  return boost::unit_test::singleton<test_driver>::instance();
}

void test_driver::add(const suite_path& suite_, const test_result& result_)
{
  _suite.add(suite_.begin(), suite_.end(), result_);
}

const test_suite& test_driver::suite() const
{
  return _suite;
}


