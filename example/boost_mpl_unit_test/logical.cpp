// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <metatest/test.hpp>
#include <boost/mpl/logical.hpp>
#include <boost/mpl/bool.hpp>

namespace
{
  const metatest::suite_path suite ("logical");

  using boost::mpl::equal_to;
  using boost::mpl::true_;
  using boost::mpl::false_;
  using boost::mpl::and_;
  using boost::mpl::or_;
  using boost::mpl::not_;

  struct unknown;

  typedef equal_to<not_<true_>, false_> test_not_1;
  typedef equal_to<not_<false_>, true_> test_not_2;
  typedef not_<false_> test_not_3;
  typedef not_< not_<true_> > test_not_4;

  typedef and_<true_,true_> test_and_1;
  typedef not_< and_<false_,true_> > test_and_2;
  typedef not_< and_<true_,false_> > test_and_3;
  typedef not_< and_<false_,false_> > test_and_4;
  typedef not_< and_<false_,unknown> > test_and_5;
  typedef not_< and_<false_,unknown,unknown> > test_and_6;

  typedef or_<true_,true_> test_or_1;
  typedef or_<false_,true_> test_or_2;
  typedef or_<true_,false_> test_or_3;
  typedef not_< or_<false_,false_> > test_or_4;
  typedef or_<true_,unknown> test_or_5;
  typedef or_<true_,unknown,unknown> test_or_6;
}

METATEST_ADD_TEST(suite, test_not_1)
METATEST_ADD_TEST(suite, test_not_2)
METATEST_ADD_TEST(suite, test_not_3)
METATEST_ADD_TEST(suite, test_not_4)

METATEST_ADD_TEST(suite, test_and_1)
METATEST_ADD_TEST(suite, test_and_2)
METATEST_ADD_TEST(suite, test_and_3)
METATEST_ADD_TEST(suite, test_and_4)
METATEST_ADD_TEST(suite, test_and_5)
METATEST_ADD_TEST(suite, test_and_6)

METATEST_ADD_TEST(suite, test_or_1)
METATEST_ADD_TEST(suite, test_or_2)
METATEST_ADD_TEST(suite, test_or_3)
METATEST_ADD_TEST(suite, test_or_4)
METATEST_ADD_TEST(suite, test_or_5)
METATEST_ADD_TEST(suite, test_or_6)

