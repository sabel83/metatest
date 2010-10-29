// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/except.h>
#include <mpllibs/parser/one_char.h>
#include <mpllibs/parser/fail.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("except");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::except<mpllibs::parser::one_char, int13>,
        str_hello
      >::type,
      mpllibs::parser::nothing
    >
    TestWithGood;
  
  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::except<mpllibs::parser::fail, int13>,
        str_hello
      >::type::first,
      int13
    >
    TestWithBad;
}

MPLLIBS_ADD_TEST(suite, TestWithGood)
MPLLIBS_ADD_TEST(suite, TestWithBad)


