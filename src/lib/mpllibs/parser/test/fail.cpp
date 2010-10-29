// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/fail.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("fail");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::parser::fail, str_hello>::type,
      mpllibs::parser::nothing
    >
    TestFailForNonEmptyString;
}

MPLLIBS_ADD_TEST(suite, TestFailForNonEmptyString)


