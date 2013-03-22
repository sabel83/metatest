#ifndef METATEST_XML_REPORT_HPP
#define METATEST_XML_REPORT_HPP

// Copyright Endre Tamas Sajo (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <metatest/config.hpp>

#include <iosfwd>

namespace metatest {

METATEST_DECL bool xml_report(std::ostream &os_);

} // namespace metatest

#endif // METATEST_XML_REPORT_HPP

