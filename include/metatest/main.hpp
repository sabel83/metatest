#ifndef METATEST_MAIN_HPP
#define METATEST_MAIN_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <metatest/test.hpp>
#include <metatest/plaintext_report.hpp>

#include <ostream>

int main()
{
  using metatest::plaintext_report;
  using std::cout;

  return plaintext_report(cout) ? 0 : 1;
}

#endif

