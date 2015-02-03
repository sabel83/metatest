# metatest

Metatest is a unit testing framework for C++ template metaprograms. It can be
integrated into other C++ unit testing frameworks and has its own reporting
capabilities as well. There are no special steps in the compilation of unit
tests compared to other C++ code.

## Table of contents

## Getting the library

* Download the source code from [github](http://github.com/sabel83/metatest).
* [build and install](build.html) the library

## License

The library is published under the
[Boost Software License](http://www.boost.org/LICENSE_1_0.txt).

## Introduction

The basic principle of Metatest is to compile the source, evaluate test cases
at compile time and generate an executable that outputs a detailed and
customizable report on the results.

The exact procedure is as follows:  Test cases are written as nullary
metafunctions returning wrapped boolean values.  These metafunctions are
evaluated and, depending on the fail/success statuses, report items are
generated utilizing the framework's own type pretty-printing facility.
Pretty-printing is needed to display detailed error messages.  For example
when a test case compares the result of a metafunction evaluation with the
expected value and they differ, the test framework should display the result
and the expected value in the report. Our solution achieves this by generating a
string at compile-time containing all these details.  In order for classes -
data, metaprograms operate on - to be usable with the framework,
we need to be able to convert them into strings.

Test results are then collected in STL containers in a test suite hierarchy,
the root of which is located in a global test driver object.  This hierarchy
is accessible through an iterator interface.  Test result objects provide
their own methods via which fail/success statuses, test names and detailed
descriptions can be accessed.
  
The test cases are collected into *test suites*.  A test suite can
contain test cases and further test suites, thus the tests are collected in a
tree structure of nested suites.  This hierarchy is built at runtime, by the
constructors of global objects.  This tree can be processed by regular C++
code, the root can be accessed as a singleton object.  The tree provides
STL-like iterators to process the children of each node.  This data-structure
can be used to either generate a report directly or to integrate compile-time
tests into runtime testing frameworks.  In our implementation we provide a
number of report generators and a tool that adds compile-time tests to the
Boost unit testing framework's test suite hierarchy.

Test cases are registered in the driver by constructors of global objects.
Our implementation provides a convenient macro for creating these global
objects.  It takes two parameters - an object representing the location of the
test case in the test suite hierarchy and the name of the metafunction.

## Basic usage

First, the following header must be included.

```cpp
#include <metatest/test.hpp>
```

Individual tests are organized in a test suite hierarchy.  To create a suite,
first, a suite path must be declared by creating an instance of
[`suite_path`](suite_path.html).
Using `operator()` suite paths can be constructed the following way:

```cpp
const suite_path my_suite_path = suite_path("a")("b")("c");
```

Test cases are written as nullary template metafunctions, each returning a
wrapped boolean value.  They are added to the test suites by registering them
using the supplied [`METATEST_ADD_TEST`](METATEST_ADD_TEST.html) macros.
  
The root of the test suite hierarchy is added to a global test driver
singleton object through which the hierarchy can be traversed at runtime.
A number of default `main` functions are provided building different
(plain text, xml, Boost test, etc.) reports.

A default `main` generating plain text report on the standard output is
available by including the following header.

```cpp
#include <metatest/main.hpp>
```

### Example

In this section we assume that we have a template metafunction, `my_reverse`,
that reverses `boost::mpl::vector` values. 
With the above applied, we get the following test suite for `my_reverse`.

```cpp
const suite_path suite = suite_path("my_suite")("my_reverse");

typedef vector<> empty;
typedef vector<char> one;
typedef vector<char, short, int, long> four;

typedef vector<long, int, short, char> four_r;

typedef equal< my_reverse<empty>::type, empty > empty_test;
typedef equal< my_reverse<one>::type, one > one_test;
typedef equal< my_reverse<four>::type, four_r > four_test;

METATEST_ADD_TEST(suite, empty_test)
METATEST_ADD_TEST(suite, one_test)
METATEST_ADD_TEST(suite, four_test)
```

By compiling it, the unit tests are executed. Assuming that our `my_reverse`
implementation is correct, the default plain text reporter outputs the following
report.

```
The following tests have been executed:
  my_suite::my_reverse::empty_test: OK
  my_suite::my_reverse::one_test: OK
  my_suite::my_reverse::four_test: OK
========================
Number of tests: 3
Number of failures: 0
```

To simulate library bugs, we modify the suite.

```cpp
const suite_path suite = suite_path("my_suite")("my_reverse");

typedef vector<> empty;
typedef vector<char> one;
typedef vector<char, short, int, long> four;

typedef vector<long, int, short, char> four_r;

typedef equal< my_reverse<empty>::type, one > empty_test;
typedef equal< my_reverse<one>::type, empty > one_test;
typedef equal< my_reverse<four>::type, four > four_test;

METATEST_ADD_TEST(suite, empty_test)
METATEST_ADD_TEST(suite, one_test)
METATEST_ADD_TEST(suite, four_test)
```

When run, this yields the following summary.

```
The following tests have been executed:
  my_suite::my_reverse::empty_test: FAIL (test.cpp:31)
        equal<mpl::vector<>, mpl::vector<char>, is_same<_, _>>
  my_suite::my_reverse::one_test: FAIL (test.cpp:32)
        equal<mpl::vector<char>, mpl::vector<>, is_same<_, _>>
  my_suite::my_reverse::four_test: FAIL (test.cpp:33)
        equal<mpl::vector<long, int, short, char>, mpl::vector<char, short, int, long>, is_same<_, _>>
========================
Number of tests: 3
Number of failures: 3
```

Besides being concise, this output does not depend on the compiler.  The format
is standard, but also customizable.

This example can be found in the `example/reverse` directory of the library.

## Customizing test reports

The framework offers facilities for customization in two ways - first, report
formats can be customized, and second, custom types can be registered for pretty
printing.

### Customizing reports

Test results are collected by a [`test_driver`](test_driver.html) singleton
object. This
object provides means to access the root of the test suite hierarchy from
which test suites, and individual test results can be acquired.  This whole
system comprises run-time structures that provide iterators for traversal.

A [`test_suite`](test_suite.html) object represents one node of the test suite
hierarchy. It contains zero or more nested [`test_suite`](test_suite.html)
objects and zero or more [`test_result`](test_result.html) objects, representing
test results.

A [`test_result`](test_result.html) object represents the result of one
compile-time test. It either succeeds or fails, and in case it fails, the
[`test_result`](test_result.html) object will provide a reason in the form of
an `std::string`. 

A [`location`](location.html) object represents a location in the source code.
It can used to display in the report, where a specific test case comes from. 

As an example, test results in the first tier of the test suite hierarchy can
be printed as follows:

```cpp
int main()
{
  using std::cout;
  
  const test_suite &results = test_driver::instance().suite().results();

  for (test_suite::result_list::const_iterator it =
          results.begin();
        it != results.end();
        ++it)
  {
    if (it->success())
    {
      cout << "OK";
    }
    else
    {
      cout << "FAIL (" << it->get_location() << ")";
      if (it->has_reason())
      {
        cout << "\n\t" << it->get_reason();
      }
    }
  }
}
```

### Pretty printing custom types

For pretty printing types, the framework provides a metafunction,
[`to_stream`](to_stream.html), which, as a class, provides a static `run` method
taking an output stream as its parameter and pretty printing the type to the
stream:

```cpp
template <class T>
struct to_stream
{
  // unspecified

  static std::ostream& run(std::ostream&);
};
```

To use [`to_stream`](to_stream.html) with a custom type, one has to specialise
this template directly and make use of pattern matching through template
specialisation. We demonstrate the specialisation for for user-defined types in
the following example.

```cpp
struct UDT {};

template<>
struct to_stream<UDT>
{
  typedef to_stream type;

  static std::ostream& run(std::ostream& os)
  { return os << "UDT"; }
}
```

The `to_stream` metafunction is defined in the following header:

```cpp
#include <metatest/to_stream.hpp>
```

This header defines `to_stream` and adds pretty printing to metafunctions,
metafunction classes and data types of Boost mpl. Unfortunately, in order to
do this, it has to include every public header of mpl. This feature can be
disabled (and re-enabled when needed) by defining the
`METATEST_NO_TO_STREAM_MPL` macro before including the `to_stream.hpp` header.

To include the declaration of `to_stream` only, the following header is
provided:

```cpp
#include <metatest/to_stream_fwd.hpp>
```

A number of convenience utilities are provided for pretty printing. After
including `to_stream_fwd.hpp` the following macros can be used to define
specializations of `to_stream` for classes and template instances:

* [`METATEST_DEFINE_TO_STREAM_FOR_TYPE(name, display_name)`](METATEST_DEFINE_TO_STREAM_FOR_TYPE.html) <br />
  define a specialization of `to_stream` for type `name` that displays
  `display_name`
* [`METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(name)`](METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE.html) <br />
  same as `METATEST_DEFINE_TO_STREAM_FOR_TYPE(name, "name")`
* [`METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE(arg_num, name, display_name)`](METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE.html) <br />
  define a specialization of `to_stream` for instances of template `name` with
  `arg_num` arguments. The result is displayed as
  `display_name<arg1, arg2, ...>`, where the arguments are pretty-printed
  recursively
* [`METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_WITH_DEFAULTS(min_arg_num, max_arg_num, name, display_name)`](METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_WITH_DEFAULTS.html) <br />
  define a specialization of `to_stream` for instances of template `name` with
  `min_arg_num`, `min_arg_num + 1, ..., max_arg_num` arguments. The result is
  displayed as `display_name<arg1, arg2, ...>`, where the arguments are
  pretty-printed recursively

These macros expect that they are not used in any namespace.

When pretty-printing compile-time data-types and metafunctions, a recurring
task is pretty-printing arguments of a templates recursively. A metafunction
called [`to_stream_argument_list`](to_stream_argument_list.html) is provided
for taking-care of pretty-printing template arguments. It uses
[`to_stream`](to_stream.html) to write `<T1, ..., Tn>` to the stream. Here is
an example usage:

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

This code displays the name of the metafunction and the `<`, `>` characters and
uses `to_stream_argument_list` to display the arguments.

## Pre-defined reporting tools

The library provides the following report generating functions:

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>
      `bool` [`plaintext_report`](plaintext_report.html)`(std::ostream &os)`
    </td>
    <td>generates a plain-text report.</td>
  </tr>
  <tr>
    <td>
      `bool` [`xml_report`](xml_report.html)`(std::ostream &os)`
    </td>
    <td>generates an xml report.</td>
  </tr>
  <tr>
    <td>
      `bool` [`html_report`](html_report.html)`(std::ostream &os)`
    </td>
    <td>generates an html/javascript report.</td>
  </tr>
</table>

The library provides different headers that can be included in a compilation
unit to define a `main` function doing some sort of pretty printing. Using them,
the contents of the `main.cpp` can be one `include`. The following headers are
available:

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`<metatest/main.hpp>`</td>
    <td>calls `plaintext_report`</td>
  </tr>
  <tr>
    <td>`<metatest/main_html.hpp>`</td>
    <td>calls `html_report`</td>
  </tr>
  <tr>
    <td>`<metatest/main_boost.hpp>`</td>
    <td>calls `build_metatest_test_suite`</td>
  </tr>
</table>

## Integration with other unit testing libraries

Compile-time assertions can be turned into runtime ones by passing the result of
the compile-time assertion to a runtime testing framework as a constant value.
Metatest provides the [`meta_warn`](meta_warn.html),
[`meta_check`](meta_check.html) and [`meta_require`](meta_require.html)
utilities for passing the result of compile-time assertions to the Boost.Test
framework. In case of failures, the error report provided by Boost.Test
contains the pretty-printed expression as well.

## Best practices

* Keep your test cases in different compilation units.
* Create a static `test_suite` object called `suite` in every compilation unit
  and use that for test cases. You will be able to move around test cases easily
  in the future.
* Keep every test-related object and class in the unnamed namespace to make
  them local to the compilation unit. This way name collisions between tests in
  different test suites are avoided.

## Examples

### boost_mpl_unit_test

A number of existing unit tests for Boost.MPL ported to use metatest
instead of static assertions. The output was generated using the HTML output
generator capability of metatest.

[source code](https://github.com/sabel83/metatest/tree/master/example/boost_mpl_unit_test) <br />
[output](example_boost_mpl_unit_test.html) <br />

### boost_test_assertion

Demonstarting the use of `meta_check`, `meta_warn` and `meta_require`. The
output was generated by Boost.Test. Using these assertion functions, one can
write Boost.Test test cases checking both the compile-time and runtime parts of
the code.

[source code](https://github.com/sabel83/metatest/tree/example/boost_test_assertion) <br />
[output](example_boost_test_assertion.html) <br />

### metatest_example

This example shows how to use the plain text reporter provided by metatest. It
prints the report as plain text to the standard output. This is ideal for
integrating with a command-line build system, such as Make.

[source code](https://github.com/sabel83/metatest/tree/master/example/metatest_example) <br />
[output](example_metatest_example.html) <br />

### misc

This example contains macros making it possible to write metatest test cases
without using an extra `typedef` per test case. Such macros were not added to
metatest, because when the test cases contain syntax errors, the compiler can
give better error messages when no macros are used. This example can be used to
experiment with the interface and compare error messages in both cases. The
output contains no errors.

[source code](https://github.com/sabel83/metatest/tree/master/example/misc) <br />
[output](example_misc.html) <br />

### reverse

This example demonstrates the difference between the error report using
different testing tools. The same tests (containing failures) can be run using
metatest and another solution based on static assertions.

[source code](https://github.com/sabel83/metatest/tree/master/example/reverse) <br />
[output](example_reverse.html) <br />

### stream_type

Example demonstrating how the type pretty-printing utility, `to_stream` can be
used.

[source code](https://github.com/sabel83/metatest/tree/master/example/stream_type) <br />
[output](example_stream_type.html) <br />

## Related publications

Ábel Sinkovics, Endre Sajó, Zoltán Porkoláb: <br />
*Towards more reliable C++ template metaprograms*, <br />
In Jaan Penjam: 12th Symposium on Programming Languages and Software Tools
(SPLST'11), Tallinn, Estonia, 5-7 October, 2011., pp. 260-271. <br />

Ábel Sinkovics: <br />
*Unit testing of C++ template metaprograms*, <br />
In Proceedings of the 8th Joint Conference on Matematics and Computer Science,
MaCS 2010, Selected papers, pp. 375-384 <br />


## Reference

Test case registration tools

* [suite_path](suite_path.html)
* [METATEST_ADD_TEST](METATEST_ADD_TEST.html)

Classes building up the test suite hierarchy at runtime

* [test_driver](test_driver.html)
* [test_suite](test_suite.html)
* [test_result](test_result.html)
* [location](location.html)
* [METATEST_HERE](METATEST_HERE.html)

Type pretty-printing tools

* [to_stream](to_stream.html)
* [to_stream_argument_list](to_stream_argument_list.html)
* [METATEST_DEFINE_TO_STREAM_FOR_TYPE](METATEST_DEFINE_TO_STREAM_FOR_TYPE.html)
* [METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE](METATEST_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE.html)
* [METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE](METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE.html)
* [METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_WITH_DEFAULTS](METATEST_DEFINE_TO_STREAM_FOR_TEMPLATE_WITH_DEFAULTS.html)

Report generators provided by the library:

* [plaintext_report](plaintext_report.html)
* [xml_report](xml_report.html)
* [html_report](html_report.html)

Integration with Boost.Test:

* [meta_warn](meta_warn.html)
* [meta_check](meta_check.html)
* [meta_require](meta_require.html)

<p class="copyright">
Copyright Endre Tamas SAJO (baja at inf dot elte dot hu), 
Abel Sinkovics (abel at elte dot hu), 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

<a href="https://github.com/sabel83/metatest"><img style="width: 149px; height: 149px; position: absolute; top: 0; right: 0; border: 0;" src="https://s3.amazonaws.com/github/ribbons/forkme_right_darkblue_121621.png" alt="Fork me on GitHub"></a>

