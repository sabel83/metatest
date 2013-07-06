# metatest::test_driver

Class of a singleton object representing the entire hierarchy of the test
suites. The singleton object can be used to access the root the hierarchy.

## Header

```cpp
#include <metatest/test_driver.hpp>
```

## Methods

None of the methods throws an exception.

```cpp
static test_driver& test_driver::instance()
```

The singleton `test_driver` instance.

```cpp
const test_suite& test_driver::suite() const
```

Root of the test suite hierarchy.

```cpp
void test_driver::add(
  const suite_path& suite_,
  const test_result& result_
)
```

Add a new test result to a test suite.

## Example

```cpp
int process_results(const test_suite& root_);

int main()
{
  return process_results(test_driver::instance().suite());
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


