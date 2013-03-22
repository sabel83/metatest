// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <metatest/test.hpp>

#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/not.hpp>

namespace
{
  const metatest::suite_path suite ("is_sequence");

  using namespace boost::mpl;

  template<typename T> struct std_vector
  {
    T* begin();
  };

  struct UDT {};

  typedef not_<is_sequence< std_vector<int> > > test1;
  typedef not_<is_sequence< int_<0> > > test2;
  typedef not_<is_sequence< int > > test3;
  typedef not_<is_sequence< int& > > test4;
  typedef not_<is_sequence< UDT > >  test5;
  typedef not_<is_sequence< UDT* > > test6;
  typedef is_sequence< range_c<int,0,0> > test7;
  typedef is_sequence< list<> > test8;
  typedef is_sequence< list<int> > test9;
  typedef is_sequence< vector<> > test10;
  typedef is_sequence< vector<int> > test11;
}

METATEST_ADD_TEST(suite, test1)
METATEST_ADD_TEST(suite, test2)
METATEST_ADD_TEST(suite, test3)
METATEST_ADD_TEST(suite, test4)
METATEST_ADD_TEST(suite, test5)
METATEST_ADD_TEST(suite, test6)
METATEST_ADD_TEST(suite, test7)
METATEST_ADD_TEST(suite, test8)
METATEST_ADD_TEST(suite, test9)
METATEST_ADD_TEST(suite, test10)
METATEST_ADD_TEST(suite, test11)

