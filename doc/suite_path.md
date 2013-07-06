# metatest::suite_path

`suite_path` instances represent locations in the test suite hierarchy.
Instances are immutable, thus their state can not be changed after
construction.

## Header

```cpp
#include <metatest/suite_path.hpp>
```

## Types

```cpp
suite_path::iterator
```

Bi-directional, read-only iterator of the elements of the path.

## Constructors

```cpp
suite_path::suite_path()
```

Construct an empty path.

```cpp
suite_path::suite_path(const std::string &)
```

Construct a single element path.

```cpp
suite_path::suite_path(const std::list<std::string> &)
```

Construct a path with multiple elements.

## Methods

None of the methods throws an exception.

```cpp
suite_path::iterator suite_path::begin() const
```

Iterator to the first element.

```cpp
suite_path::iterator suite_path::end() const
```

Iterator pointing after the last element.

```cpp
suite_path suite_path::operator()(const std::string &) const
```

Append a new element to the end of the path.

## Example

```cpp
const suite_path suite = suite_path("util")("curry");
```

<p class="copyright">
Copyright Endre Tamas SAJO (baja at inf dot elte dot hu),
Abel Sinkovics (abel at elte dot hu), 2010.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)


