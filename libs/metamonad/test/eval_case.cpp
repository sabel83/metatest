// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/eval_case.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/type_traits.hpp>

#include <boost/mpl/equal_to.hpp>

#include "common.hpp"

namespace
{
  template <class A, class B>
  struct some_template;

  template <class A, class B>
  struct some_other_template;
}

BOOST_AUTO_TEST_CASE(test_eval_case)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::eval_case;
  using mpllibs::metamonad::matches;
  using mpllibs::metamonad::exception;
  using mpllibs::metamonad::no_case_matched;
  using mpllibs::metamonad::var;
  using mpllibs::metamonad::returns;

  using boost::is_same;

  using boost::mpl::equal_to;

  meta_require<
    is_same<
      exception<no_case_matched<int> >,
      eval_case< returns<int>,
        matches<double, float>
      >::type
    >
  >(MPLLIBS_HERE, "test_no_matches");

  meta_require<
    is_same<
      float,
      eval_case< returns<int>,
        matches<int, returns<float> >
      >::type
    >
  >(MPLLIBS_HERE, "test_match");

  meta_require<
    is_same<
      float,
      eval_case< returns<int>,
        matches<int, returns<float> >,
        matches<double, char>
      >::type
    >
  >(MPLLIBS_HERE, "test_first_matches");

  meta_require<
    is_same<
      float,
      eval_case< returns<int>,
        matches<double, char>,
        matches<int, returns<float> >
      >::type
    >
  >(MPLLIBS_HERE, "test_second_matches");

  meta_require<
    is_same<
      some_other_template<int, double>,
      eval_case< returns<some_template<int, double> >,
        matches< some_template<var<x>, var<y> >,
          returns<some_other_template<x, y> >
        >
      >::type
    >
  >(MPLLIBS_HERE, "test_vars_in_pattern");

  meta_require<
    equal_to<
      int13,
      eval_case< int11,
        matches< var<x>,
          eval_case< int2,
            matches<var<y>, boost::mpl::plus<x, y> >
          >
        >
      >::type
    >
  >(MPLLIBS_HERE, "test_nested_case");
}

