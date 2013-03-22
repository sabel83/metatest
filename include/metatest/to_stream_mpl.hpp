#ifndef METATEST_TO_STREAM_MPL_HPP
#define METATEST_TO_STREAM_MPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <metatest/to_stream_sequence.hpp>

#include <boost/mpl/string.hpp>
#include <boost/mpl/at.hpp>

#include <boost/mpl/accumulate.hpp>
#include <boost/mpl/base.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/bitwise.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/copy_if.hpp>
#include <boost/mpl/count.hpp>
#include <boost/mpl/count_if.hpp>
#include <boost/mpl/divides.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/empty_base.hpp>
#include <boost/mpl/empty_sequence.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/erase.hpp>
#include <boost/mpl/erase_key.hpp>
#include <boost/mpl/filter_view.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/greater_equal.hpp>
#include <boost/mpl/greater.hpp>
#include <boost/mpl/inherit.hpp>
#include <boost/mpl/inherit_linearly.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/insert_range.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/key_type.hpp>
#include <boost/mpl/less_equal.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/lower_bound.hpp>
#include <boost/mpl/max_element.hpp>
#include <boost/mpl/min_element.hpp>
#include <boost/mpl/modulus.hpp>
#include <boost/mpl/not_equal_to.hpp>
#include <boost/mpl/order.hpp>
#include <boost/mpl/partition.hpp>
#include <boost/mpl/remove.hpp>
#include <boost/mpl/remove_if.hpp>
#include <boost/mpl/replace.hpp>
#include <boost/mpl/replace_if.hpp>
#include <boost/mpl/reverse.hpp>
#include <boost/mpl/reverse_iter_fold.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/mpl/sort.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/transform_view.hpp>
#include <boost/mpl/unique.hpp>
#include <boost/mpl/unpack_args.hpp>
#include <boost/mpl/upper_bound.hpp>
#include <boost/mpl/value_type.hpp>
#include <boost/mpl/void.hpp>
#include <boost/mpl/zip_view.hpp>
#include <boost/mpl/range_c.hpp>

#include <boost/type_traits/is_same.hpp>

#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/arithmetic/div.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>

namespace metatest
{
  template <class T, T Start, T Finish>
  struct to_stream<boost::mpl::range_c<T, Start, Finish> >
  {
    static std::ostream& run(std::ostream& o)
    {
      o << "range_c<";
      to_stream<T>::run(o);
      return o << ", " << Start << ", " << Finish << ">";
    }
  };

  template <class T, T N>
  struct to_stream<boost::mpl::integral_c<T, N> >
  {
    static std::ostream& run(std::ostream& o)
    {
      o << "integral_c<";
      to_stream<T>::run(o);
      return o << ", " << N << ">";
    }
  };

  template <size_t N>
  struct to_stream<boost::mpl::size_t<N> >
  {
    static std::ostream& run(std::ostream& o)
    {
      return o << "size_t<" << N << ">";
    }
  };

  template <long N>
  struct to_stream<boost::mpl::long_<N> >
  {
    static std::ostream& run(std::ostream& o)
    {
      return o << "long<" << N << ">";
    }
  };

  template <int N>
  struct to_stream<boost::mpl::int_<N> >
  {
    static std::ostream& run(std::ostream& o)
    {
      return o << "int<" << N << ">";
    }
  };

  template <BOOST_PP_ENUM_PARAMS(BOOST_MPL_STRING_MAX_PARAMS, int C)>
  struct to_stream<
    boost::mpl::string<BOOST_PP_ENUM_PARAMS(BOOST_MPL_STRING_MAX_PARAMS, C)>
  >
  {
    static std::ostream& run(std::ostream& o)
    {
      return
        o
          << "string<\""
          <<
            boost::mpl::c_str<
              boost::mpl::string<
                BOOST_PP_ENUM_PARAMS(
                  BOOST_PP_DIV(BOOST_MPL_LIMIT_STRING_SIZE, 4),
                  C
                )
              >
            >::type::value
          << "\">";
    }
  };

  template <int N>
  struct to_stream<boost::mpl::arg<N> >
  {
    typedef to_stream type;
    
    static std::ostream& run(std::ostream& o_)
    {
      return o_ << "_" << N;
    }
  };

  template <char C>
  struct to_stream<boost::mpl::char_<C> >
  {
    typedef to_stream type;

    static std::ostream& run(std::ostream& o_)
    {
      return o_ << "char_<" << C << ">";
    }
  };
}

METATEST_DEFINE_TO_STREAM_FOR_TYPE(boost::mpl::bool_<true>, "true")
METATEST_DEFINE_TO_STREAM_FOR_TYPE(boost::mpl::bool_<false>, "false")
METATEST_DEFINE_TO_STREAM_FOR_TYPE(boost::mpl::void_, "void_")

METATEST_DEFINE_TO_STREAM_FOR_TYPE(boost::mpl::empty_sequence, "empty_sequence")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::filter_view, "filter_view")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  2,
  boost::mpl::iterator_range,
  "iterator_range"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::joint_view, "joint_view")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::single_view, "single_view")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  2,
  boost::mpl::transform_view,
  "transform_view"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::zip_view, "zip_view")

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::at, "at")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::back, "back")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::begin, "begin")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::clear, "clear")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::empty, "empty")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::end, "end")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::erase, "erase")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::erase_key, "erase_key")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::front, "front")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::has_key, "has_key")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::insert, "insert")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  3,
  boost::mpl::insert_range,
  "insert_range"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::is_sequence, "is_sequence")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::key_type, "key_type")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::order, "order")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::pop_back, "pop_back")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::pop_front, "pop_front")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::push_back, "push_back")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::push_front, "push_front")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  boost::mpl::sequence_tag,
  "sequence_tag"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::size, "size")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::value_type, "value_type")

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::advance, "advance")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::distance, "distance")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::next, "next")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::prior, "prior")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::deref, "deref")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  boost::mpl::iterator_category,
  "iterator_category"
)

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  boost::mpl::back_inserter,
  "back_inserter"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  boost::mpl::front_inserter,
  "front_inserter"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::inserter, "inserter")

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::fold, "fold")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::iter_fold, "iter_fold")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  3,
  boost::mpl::reverse_fold,
  "reverse_fold"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  3,
  boost::mpl::reverse_iter_fold,
  "reverse_iter_fold"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::accumulate, "accumulate")

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::find, "find")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::find_if, "find_if")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::contains, "contains")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::count, "count")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::count_if, "count_if")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::lower_bound, "lower_bound")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::upper_bound, "upper_bound")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::min_element, "min_element")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::max_element, "max_element")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::equal, "equal")

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::copy, "copy")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::copy_if, "copy_if")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::transform, "transform")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(4, boost::mpl::replace, "replace")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(4, boost::mpl::replace_if, "replace_if")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::remove, "remove")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::remove_if, "remove_if")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::unique, "unique")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(4, boost::mpl::partition, "partition")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  4,
  boost::mpl::stable_partition,
  "stable_partition"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::sort, "sort")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::reverse, "reverse")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  2,
  boost::mpl::reverse_copy,
  "reverse_copy"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  3,
  boost::mpl::reverse_copy_if,
  "reverse_copy_if"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  3,
  boost::mpl::reverse_transform,
  "reverse_transform"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  4,
  boost::mpl::reverse_replace,
  "reverse_replace"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  3,
  boost::mpl::reverse_replace_if,
  "reverse_replace_if"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  3,
  boost::mpl::reverse_remove,
  "reverse_remove"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  3,
  boost::mpl::reverse_remove_if,
  "reverse_remove_if"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  3,
  boost::mpl::reverse_unique,
  "reverse_unique"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  4,
  boost::mpl::reverse_partition,
  "reverse_partition"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  4,
  boost::mpl::reverse_stable_partition,
  "reverse_stable_partition"
)

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::if_, "if_")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(3, boost::mpl::eval_if, "eval_if")

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::unpack_args, "unpack_args")

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::lambda, "lambda")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::protect, "protect")

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::modulus, "modulus")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::negate, "negate")

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::less, "less")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::less_equal, "less_equal")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::greater, "greater")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  2,
  boost::mpl::greater_equal,
  "greater_equal"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::equal_to, "equal_to")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  2,
  boost::mpl::not_equal_to,
  "not_equal_to"
)

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::not_, "not_")

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::shift_left, "shift_left")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::shift_right, "shift_right")

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::first, "first")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::second, "second")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::base, "base")

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::c_str, "c_str")

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::identity, "identity")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::always, "always")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::inherit, "inherit")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  3,
  boost::mpl::inherit_linearly,
  "inherit_linearly"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(
  2,
  boost::mpl::numeric_cast,
  "numeric_cast"
)
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::min, "min")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::max, "max")
METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(1, boost::mpl::sizeof_, "sizeof_")

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::mpl::pair, "pair")

METATEST_DEFINE_TO_STREAM_FOR_TYPE(boost::mpl::empty_base, "empty_base")

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(2, boost::is_same, "is_same")




#ifdef METATEST_DEFINE_APPLY_N
  #error METATEST_DEFINE_APPLY_N already defined
#endif
#define METATEST_DEFINE_APPLY_N(z, n, unused) \
  METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE( \
    BOOST_PP_INC(n), \
    boost::mpl::apply##n, \
    "apply" #n \
  )

BOOST_PP_REPEAT(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, METATEST_DEFINE_APPLY_N, ~)

#undef METATEST_DEFINE_APPLY_N




#ifdef METATEST_MULTI_ARG_METAFUNCTION
  #error METATEST_MULTI_ARG_METAFUNCTION already defined
#endif
#define METATEST_MULTI_ARG_METAFUNCTION(z, n, name) \
  METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(n, boost::mpl::name, #name)

#ifdef METATEST_DEF_MULTI_ARG
  #error METATEST_DEF_MULTI_ARG already defined
#endif
#define METATEST_DEF_MULTI_ARG(name) \
  BOOST_PP_REPEAT_FROM_TO( \
    1, \
    BOOST_MPL_LIMIT_METAFUNCTION_ARITY, \
    METATEST_MULTI_ARG_METAFUNCTION, \
    name \
  )
  
METATEST_DEF_MULTI_ARG(apply)
METATEST_DEF_MULTI_ARG(bind)
METATEST_DEF_MULTI_ARG(plus)
METATEST_DEF_MULTI_ARG(minus)
METATEST_DEF_MULTI_ARG(times)
METATEST_DEF_MULTI_ARG(divides)
METATEST_DEF_MULTI_ARG(and_)
METATEST_DEF_MULTI_ARG(or_)
METATEST_DEF_MULTI_ARG(bitand_)
METATEST_DEF_MULTI_ARG(bitor_)
METATEST_DEF_MULTI_ARG(bitxor_)

#undef METATEST_DEF_MULTI_ARG
#undef METATEST_MULTI_ARG_METAFUNCTION


#endif

