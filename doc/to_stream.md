# metatest::to_stream

## Synopsis

```cpp
template <class T>
struct to_stream
{
  static std::ostream& run(std::ostream& o_);
};
```

## Description

Tool for pretty-printing types at runtime. It takes the type as a compile-time
and the stream to print it to as a runtime argument. Pretty-printing support for
new types can be added by specialising this template and providing the `run`
method in the specialisation.

## Header

```cpp
#include <metatest/to_stream.hpp>
```

## Example

```cpp
int main()
{
  to_stream<const int**>::run(std::cout);
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


