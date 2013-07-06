# metatest::meta_warn

## Synopsis

```cpp
template <class Pred>
void meta_warn(const location& location_, const std::string& name_);

template <class Pred>
void meta_warn(const location& location_);
```

This template function simplifies passing template metaprogrmaming assertions to
Boost.Test. It creates a [`test_result`](test_result.html) from
the `Pred` predicate using `location_` and `name_` when available. The
success/failure flag and the reason string of the result is then passed to a
Boost.Test `WARN` assertion.

## Header

```cpp
#include <metatest/boost_test.hpp>
```

## Example

```cpp
BOOST_AUTO_TEST_CASE(example)
{
  meta_warn<
    boost::mpl::equal_to<boost::mpl::int_<13>, function_to_test<int>::type>
  >(METATEST_HERE);
}
```

<p class="copyright">
Copyright Endre Tamas SAJO (baja at inf dot elte dot hu),
Abel Sinkovics (abel at elte dot hu), 2010.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)



