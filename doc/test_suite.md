# metatest::test_suite

`suite_path` instances represent locations in the test suite hierarchy.
Instances are immutable, thus their state can not be changed after
construction.

## Header

```cpp
#include <metatest/test_suite.hpp>
```

## Types

```cpp
suite_path::suite_map
```

Associative container mapping `std::string` keys to `test_suite` values.

```cpp
suite_path::result_list
```

Container of [`test_result`](test_result.html) values.

## Constructors

No public constructors are available.

## Methods

None of the methods throws an exception.

```cpp
size_t test_suite::failure_count() const
```

Number of failed tests.

```cpp
size_t test_suite::count() const
```

Number of all tests.

```cpp
const test_suite::suite_map& test_suite::suites() const
```

Suites which have the current suite as parent.

```cpp
const test_suite::result_list& test_suite::results() const
```

Result objects corresponding to the tests within the current suite.

## Example

```cpp
int process_results(const test_suite& root_)
{
  return root_.failure_count() == 0 ? 0 : 1;
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


