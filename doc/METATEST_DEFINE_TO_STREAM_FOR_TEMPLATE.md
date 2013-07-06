# METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE

## Synopsis

```cpp
#define METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(arg_num, name, display_name) \
  // unspecified
```

## Description

Defines an overload of [`to_stream`](to_stream.html) for instances of the
template `name` taking `arg_num` arguments, where `arg_num` is an integer value.
`display_name` is a constant expression that can be displayed in a stream
using `operator<<`. It is displayed as the name of the template.
[`to_stream`](to_stream.html) is called recursively for the template
arguments.

## Header

```cpp
#include <metatest/to_stream_fwd.hpp>
```

## Example

```cpp
template <class A, class B, class C>
class custom_template;

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(3, custom_template, "custom_template")
```

<p class="copyright">
Copyright Endre Tamas SAJO (baja at inf dot elte dot hu),
Abel Sinkovics (abel at elte dot hu), 2010.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)




