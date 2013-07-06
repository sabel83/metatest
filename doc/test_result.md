# metatest::test_result

`test_result` instances represent results of a compile-time tests at runtime.
Instances are immutable, thus their state can not be changed after
construction.

## Header

```cpp
#include <metatest/test_result.hpp>
```

## Constructors

```cpp
test_result::test_result(
  const std::string& name_,                                                                   
  const location& location_,
  bool success_,
  const std::string& reason_
)
```

Creates a new instance with the specified properties.

## Methods

None of the methods throws an exception.

```cpp
bool test_result::has_name() const
```

Whether the result object has a name.

```cpp
const std::string& test_result::get_name() const
```

Name of the current test.

```cpp
const location& test_result::get_location() const
```

Location of the test body within the source.

```cpp
bool test_result::success() const
```

Success/fail status.

```cpp
bool test_result::has_reason() const
```

Whether the result object has a description.

```cpp
const std::string& test_result::get_reason() const
```

Description of the test result.

```cpp
template <class Pred>
static test_result test_result::build(
  const location& location_,
  const std::string& name_ = std::string()
)
```

Builds a `test_result` instance by evaluating the predicate.

## Operators

```cpp
std::ostream& operator<<(std::ostream& o_, const test_result& result_);
```

Pretty-prints the test result to the stream.

<p class="copyright">
Copyright Endre Tamas SAJO (baja at inf dot elte dot hu),
Abel Sinkovics (abel at elte dot hu), 2010.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)


