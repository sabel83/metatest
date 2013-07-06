# metates::to_stream_argument_list

## Synopsis

```cpp
template <
  class T1,
  // ...
  class Tn
>
struct to_stream_argument_list
{
  static std::ostream& run(std::ostream&);
  // unspecified
};
```

## Description

Tool for pretty-printing template arguments of a template instance. It takes
the arguments of the instance as template arguments and uses
[`to_stream`](to_stream.html) for pretty-printing them.

## Header

```cpp
#include <metatest/to_stream_argument_lis_argument_list.hpp>
```

## Example

```cpp
template <class A, class B>
struct plus
{
  // implementation of the plus metafunction
  
  struct to_stream
  {
    // display "plus<A, B>"
    static std::ostream& run(std::ostream& o)
    {
      o << "plus<";
      to_stream_argument_list<A, B>::run(o);
      return o << ">";
    }
  };
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


