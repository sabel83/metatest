# METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_WITH_DEFAULTS

## Synopsis

```cpp
#define METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_WITH_DEFAULTS(
  min_arg_num,
  max_arg_num,
  name,
  display_name
) \
  // unspecified
```

## Description

Defines an overload of [`to_stream`](to_stream.html) for instances of the
template `name` taking `max_arg_num` arguments. The last
`max_arg_num - min_arg_num` template arguments have default values, thus
the template can be instantiated with `min_arg_num`, `min_arg_num + 1`, ...
`max_arg_num` number of arguments. `min_arg_num` and `max_arg_num` are integer
values. `display_name` is a constant expression that can be displayed in a
stream using `operator<<`. It is displayed as the name of the template.
[`to_stream`](to_stream.html) is called recursively for the template arguments.

## Header

```cpp
#include <metatest/to_stream_fwd.hpp>
```

## Example

```cpp
template <class A, class B = int, class C = int>
class custom_template;

METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_WITH_DEFAULTS(
  1,
  3,
  custom_template,
  "custom_template"
)
```

<p class="copyright">
Copyright Endre Tamas SAJO (baja at inf dot elte dot hu),
Abel Sinkovics (abel at elte dot hu), 2010.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)




