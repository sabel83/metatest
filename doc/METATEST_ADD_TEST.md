# METATEST_ADD_TEST

## Synopsis

```cpp
#define METATEST_ADD_TEST(path, test) \
  // unspecified
```


## Description

Macro for registering a test case. `path` is a
[`suite_path`](suite_path.html) instance, `test` is a nullary template
metafunction evaluating to a boxed boolean value, the success of the test case.

At runtime, the test case is guaranteed to be registered in the test hierarchy
before `main` is called.

## Header

```cpp
#include <metatest/test.hpp>
```

## Example

```cpp
using boost::mpl::is_equal;
using boost::mpl::int_;

template <class A, class B>
struct metafunction_to_test;

const suite_path suite = suite_path("test")("suite");

typedef
  is_equal<int_<13>, metafunction_to_test<int_<19>, int_<83> > >
  test_case;

METATEST_ADD_TEST(suite, test_case)
```

<p class="copyright">
Copyright Endre Tamas SAJO (baja at inf dot elte dot hu),
Abel Sinkovics (abel at elte dot hu), 2010.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)




