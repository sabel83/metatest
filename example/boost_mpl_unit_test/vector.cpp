// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <metatest/test.hpp>

#include <boost/mpl/vector.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/pop_back.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/not.hpp>

#include <boost/type_traits/is_same.hpp>

namespace
{
  const metatest::suite_path suite ("vector");

  using namespace boost::mpl;
  using boost::is_same;

  typedef vector0<> v0;
  typedef vector1<char> v1;
  typedef vector2<char,long> v2;
  typedef vector9<char,bool,char,char,char,char,bool,long,int> v9;

  typedef vector<> w0;
  typedef vector<char> w1;
  typedef vector<char,long> w2;
  typedef vector<char,char,char,char,char,char,char,char,int> w9;

  typedef equal<v0, v0::type> test_equal_1;
  typedef equal<v1, v1::type> test_equal_2;
  typedef equal<v2, v2::type> test_equal_3;
  typedef equal<v9, v9::type> test_equal_4;

  typedef equal_to< size<v0>::type, int_<0> > test_size_1;
  typedef equal_to< size<v1>::type, int_<1> > test_size_2;
  typedef equal_to< size<v2>::type, int_<2> > test_size_3;
  typedef equal_to< size<v9>::type, int_<9> > test_size_4;

  typedef empty<v0> test_empty_1;
  typedef not_<empty<v1> > test_empty_2;
  typedef not_<empty<v2> > test_empty_3;
  typedef not_<empty<v9> > test_empty_4;

  typedef is_same< front<v1>::type, char > test_front_1;
  typedef is_same< front<v2>::type, char > test_front_2;
  typedef is_same< front<v9>::type, char > test_front_3;

  typedef is_same< back<v1>::type, char > test_back_1;
  typedef is_same< back<v2>::type, long > test_back_2;
  typedef is_same< back<v9>::type, int > test_back_3;

  typedef is_same<
        deref< begin<v2>::type >::type
      , char
    > test_iter_1;

  typedef is_same<
        deref< next<begin<v2>::type>::type >::type
      , long
    > test_iter_2;

  typedef is_same<
        next< next<begin<v2>::type>::type >::type
      , end<v2>::type
    > test_iter_3;

  typedef is_same<
        back<
            push_back<v0, int>::type
        >::type
      , int
    > test_push_1;

  typedef is_same<
        back<
            push_front<
                push_back<v0, int>::type
              , char
            >::type
        >::type
      , int
    > test_push_2;

  typedef is_same<
        front<
            push_back<
                push_front<
                    push_back<v0, int>::type
                  , char
                >::type
              , long
            >::type
        >::type
      , char
    > test_push_3;

  typedef is_same<
        back<
            push_back<
                push_front<
                    push_back<v0, int>::type
                  , char
                >::type
              , long
            >::type
        >::type
      , long
    > test_push_4;

  typedef equal<
        push_back<v0, int>::type
      , push_back<v0, int>::type::type
    > test_push_5;

  typedef equal<
        push_front<
            push_back<v0, int>::type
          , char
        >::type
      , push_front<
            push_back<v0, int>::type
          , char
        >::type::type
    > test_push_6;

  typedef equal<
        push_back<
            push_front<
                push_back<v0, int>::type
              , char
            >::type
          , long
        >::type
      , push_back<
            push_front<
                push_back<v0, int>::type
              , char
            >::type
          , long
        >::type::type
    > test_push_7;

  typedef is_same< back<v9>::type, int > test_pop_1;

  typedef is_same<
        back< pop_back<v9>::type >::type
      , long
    > test_pop_2;

  typedef is_same<
        back<
            pop_front< pop_back<v9>::type >::type
        >::type
      , long
    > test_pop_3;

  typedef is_same<
        front<
            pop_front< pop_back<v9>::type >::type
        >::type
      , bool
    > test_pop_4;

  typedef equal<v9, v9::type> test_pop_5;

  typedef equal<
        pop_back<v9>::type
      , pop_back<v9>::type::type
    > test_pop_6;

  typedef equal<
        pop_front< pop_back<v9>::type >::type
      , pop_front< pop_back<v9>::type >::type::type
    > test_pop_7;

  typedef equal<w0, w0::type> test_unnumbered_1;
  typedef equal<w1, w1::type> test_unnumbered_2;
  typedef equal<w2, w2::type> test_unnumbered_3;
  typedef equal<w9, w9::type> test_unnumbered_4;

  typedef equal_to< size<w0>::type, int_<0> > test_unnumbered_5;
  typedef equal_to< size<w1>::type, int_<1> > test_unnumbered_6;
  typedef equal_to< size<w2>::type, int_<2> > test_unnumbered_7;
  typedef equal_to< size<w9>::type, int_<9> > test_unnumbered_8;
}

METATEST_ADD_TEST(suite, test_equal_1)
METATEST_ADD_TEST(suite, test_equal_2)
METATEST_ADD_TEST(suite, test_equal_3)
METATEST_ADD_TEST(suite, test_equal_4)

METATEST_ADD_TEST(suite, test_size_1)
METATEST_ADD_TEST(suite, test_size_2)
METATEST_ADD_TEST(suite, test_size_3)
METATEST_ADD_TEST(suite, test_size_4)

METATEST_ADD_TEST(suite, test_empty_1)
METATEST_ADD_TEST(suite, test_empty_2)
METATEST_ADD_TEST(suite, test_empty_3)
METATEST_ADD_TEST(suite, test_empty_4)

METATEST_ADD_TEST(suite, test_front_1)
METATEST_ADD_TEST(suite, test_front_2)
METATEST_ADD_TEST(suite, test_front_3)
METATEST_ADD_TEST(suite, test_back_1)
METATEST_ADD_TEST(suite, test_back_2)
METATEST_ADD_TEST(suite, test_back_3)

METATEST_ADD_TEST(suite, test_iter_1)
METATEST_ADD_TEST(suite, test_iter_2)
METATEST_ADD_TEST(suite, test_iter_3)

METATEST_ADD_TEST(suite, test_push_1)
METATEST_ADD_TEST(suite, test_push_2)
METATEST_ADD_TEST(suite, test_push_3)
METATEST_ADD_TEST(suite, test_push_4)
METATEST_ADD_TEST(suite, test_push_5)
METATEST_ADD_TEST(suite, test_push_6)
METATEST_ADD_TEST(suite, test_push_7)

METATEST_ADD_TEST(suite, test_pop_1)
METATEST_ADD_TEST(suite, test_pop_2)
METATEST_ADD_TEST(suite, test_pop_3)
METATEST_ADD_TEST(suite, test_pop_4)
METATEST_ADD_TEST(suite, test_pop_5)
METATEST_ADD_TEST(suite, test_pop_6)
METATEST_ADD_TEST(suite, test_pop_7)

METATEST_ADD_TEST(suite, test_unnumbered_1)
METATEST_ADD_TEST(suite, test_unnumbered_2)
METATEST_ADD_TEST(suite, test_unnumbered_3)
METATEST_ADD_TEST(suite, test_unnumbered_4)
METATEST_ADD_TEST(suite, test_unnumbered_5)
METATEST_ADD_TEST(suite, test_unnumbered_6)
METATEST_ADD_TEST(suite, test_unnumbered_7)
METATEST_ADD_TEST(suite, test_unnumbered_8)

