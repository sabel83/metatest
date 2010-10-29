// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/first_of.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("first_of");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::first_of<lit_h, lit_e>,
        str_hello
      >::type::first,
      char_h
    >
    TestTwoChars;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::first_of<lit_x, lit_e>,
        str_hello
      >::type,
      mpllibs::parser::nothing
    >
    TestFirstFails;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::first_of<lit_h, lit_x>,
        str_hello
      >::type,
      mpllibs::parser::nothing
    >
    TestSecondFails;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::parser::first_of<lit_h, lit_e>, str_>::type,
      mpllibs::parser::nothing
    >
    TestEmptyInput;
}

MPLLIBS_ADD_TEST(suite, TestTwoChars)
MPLLIBS_ADD_TEST(suite, TestFirstFails)
MPLLIBS_ADD_TEST(suite, TestSecondFails)
MPLLIBS_ADD_TEST(suite, TestEmptyInput)

