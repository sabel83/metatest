# metatest::location

`location` instances represent locations in the source code. Instances are
immutable, thus their state can not be changed after construction.

A special macro, [`METATEST_HERE`](METATEST_HERE.html) represents the current
location.

## Header

```cpp
#include <metatest/location.hpp>
```

## Constructors

```cpp
location::location(const std::string& filename_, int line_number_)
```

Creates a new instance with the specified properties.

## Methods

None of the methods throws an exception.

```cpp
const std::string& location::filename() const
```

Name of the file, where the test case was registered.

```cpp
int location::line_number() const
```

Line number, where the test case was registered.

<p class="copyright">
Copyright Endre Tamas SAJO (baja at inf dot elte dot hu), 
Abel Sinkovics (abel at elte dot hu), 2010.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)


