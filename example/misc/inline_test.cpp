// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <metatest/test.hpp>

#include <boost/mpl/equal_to.hpp>

template<class T>
struct remove_parentheses_helper
{ typedef T type; };

template<class T>
struct remove_parentheses_helper<void (T)>
{ typedef T type; };

#define REMOVE_PARENTHESES(t) \
  remove_parentheses_helper<void (t)>::type

#define METATEST_TEST_IF_EQUAL(a, b, suite, test_name) \
  namespace \
  { \
    typedef boost::mpl::equal_to < \
          REMOVE_PARENTHESES(a) \
        , REMOVE_PARENTHESES(b) \
      > test_name; \
  } \
  METATEST_ADD_TEST(suite, test_name)

#include <boost/mpl/int.hpp>

namespace
{
  const metatest::suite_path suite ("inline_test");
  using namespace boost::mpl;
}

METATEST_TEST_IF_EQUAL((int_<0>), int_<0>, suite, test1)

namespace
{
  typedef equal_to<int_<0>, int_<0> > test2;
}

METATEST_ADD_TEST(suite, test2)

