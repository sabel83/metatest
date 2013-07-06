# metatest::html_report

## Synopsis

```cpp
bool html_report(std::ostream &os_)
```

## Description

Displays the test results as an HTML document. Returns `true` when there
was no failed test case. The HTML document assumes that
[`jquery.js`](http://jquery.com/) is in the same directory as the generated HTML
document itself.

## Header

```cpp
#include <metatest/html_report.hpp>
```

<p class="copyright">
Copyright Endre Tamas SAJO (baja at inf dot elte dot hu), 
Abel Sinkovics (abel at elte dot hu), 2010.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)


