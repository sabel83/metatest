// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/any.h>
#include <mpllibs/parser/letter.h>

#include "common.h"
 
#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/equal_sequence.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/apply.hpp>

namespace
{ 
  const mpllibs::metatest::TestSuite suite("any");

  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::any<mpllibs::parser::letter>,
        str_
      >::type::first,
      boost::mpl::list<>
    >
    TestEmptyInput;
  
  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::any<mpllibs::parser::letter>,
        chars0
      >::type::first,
      boost::mpl::list<>
    >
    Test0;
  
  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::any<mpllibs::parser::letter>,
        chars1
      >::type::first,
      boost::mpl::list<char_h>
    >
    Test1;
  
  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::any<mpllibs::parser::letter>,
        chars2
      >::type::first,
      boost::mpl::list<char_h, char_e>
    >
    Test2;
  
  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::any<mpllibs::parser::letter>,
        chars3
      >::type::first,
      boost::mpl::list<char_h, char_e, char_l>
    >
    Test3;
  
  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::any<mpllibs::parser::letter>,
        chars4
      >::type::first,
      boost::mpl::list<char_h, char_e, char_l, char_l>
    >
    Test4;
  
  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::any<mpllibs::parser::letter>,
        chars5
      >::type::first,
      boost::mpl::list<char_h, char_e, char_l, char_l, char_o>
    >
    Test5;
}

MPLLIBS_ADD_TEST(suite, TestEmptyInput)
MPLLIBS_ADD_TEST(suite, Test0)
MPLLIBS_ADD_TEST(suite, Test1)
MPLLIBS_ADD_TEST(suite, Test2)
MPLLIBS_ADD_TEST(suite, Test3)
MPLLIBS_ADD_TEST(suite, Test4)
MPLLIBS_ADD_TEST(suite, Test5)

