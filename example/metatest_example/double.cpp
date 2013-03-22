// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <metatest/test.hpp>

#include <metatest/to_stream_fwd.hpp>

#include <boost/mpl/times.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

using metatest::suite_path;

using boost::mpl::equal_to;
using boost::mpl::int_;

// Metafunction to test
template <class T>
struct double_ : boost::mpl::times<T, boost::mpl::int_<2> > {};

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, double_, "double_")

namespace
{
  const suite_path suite("example");

  typedef equal_to<double_<int_<13> >::type, int_<26> > test_success;
}

METATEST_ADD_TEST(suite, test_success)


