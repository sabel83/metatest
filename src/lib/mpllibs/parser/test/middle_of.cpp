// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/middle_of.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("middle_of");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::middle_of<lit_h, lit_e, lit_l>,
        str_hello
      >::type::first,
      char_e
    >
    TestThreeChars;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::middle_of<lit_x, lit_e, lit_l>,
        str_hello
      >::type,
      mpllibs::parser::nothing
    >
    TestFirstFails;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::middle_of<lit_h, lit_x, lit_l>,
        str_hello
      >::type,
      mpllibs::parser::nothing
    >
    TestSecondFails;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::middle_of<lit_h, lit_e, lit_x>,
        str_hello
      >::type,
      mpllibs::parser::nothing
    >
    TestThirdFails;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::middle_of<lit_h, lit_e, lit_l>,
        str_
      >::type,
      mpllibs::parser::nothing
    >
    TestEmptyInput;
}

MPLLIBS_ADD_TEST(suite, TestThreeChars)
MPLLIBS_ADD_TEST(suite, TestFirstFails)
MPLLIBS_ADD_TEST(suite, TestSecondFails)
MPLLIBS_ADD_TEST(suite, TestThirdFails)
MPLLIBS_ADD_TEST(suite, TestEmptyInput)


