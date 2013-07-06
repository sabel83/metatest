# METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE

## Synopsis

```cpp
#define METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(name) \
  // unspecified
```

## Description

Defines an overload of [`to_stream`](to_stream.html) for the type `name`.

## Header

```cpp
#include <metatest/to_stream_fwd.hpp>
```

## Example

```cpp
class custom_type;

METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(custom_type)
```

<p class="copyright">
Copyright Endre Tamas SAJO (baja at inf dot elte dot hu),
Abel Sinkovics (abel at elte dot hu), 2010.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)




