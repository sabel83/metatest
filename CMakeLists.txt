# Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 2.6)
project(mpllibs)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}")
include(Asciidoc)

enable_testing()

include_directories(".")

set(BUILD_SHARED_LIBS ON)

subdirs(libs doc)

# build the documentation website
set(WEBSITE_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/website)

add_custom_command(
  OUTPUT ${WEBSITE_ROOT}
  COMMAND mkdir -p ${WEBSITE_ROOT}
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/style.css ${WEBSITE_ROOT}/style.css)

add_custom_command(
  OUTPUT ${WEBSITE_ROOT}/index.html
  COMMAND cat ${CMAKE_SOURCE_DIR}/index.html | sed 's/\\"libs\\//"/g' | sed 's/\\/html\\//\\//g' > ${WEBSITE_ROOT}/index.html
  DEPENDS ${CMAKE_SOURCE_DIR}/index.html ${WEBSITE_ROOT}
)

set(WEBSITE_FILES ${WEBSITE_ROOT}/index.html ${WEBSITE_ROOT}/style.css)

# metatest code samples
foreach(E
  boost_mpl_unit_test
  boost_test
  metatest_example
  stream_type
  boost_test_assertion
  ugly
  misc
  reverse
  exception_debug
)
  set(FILENAME example_${E}.html)
  set(SRC_FILE ${CMAKE_SOURCE_DIR}/libs/metatest/html/${FILENAME})
  set(DST_FILE ${WEBSITE_ROOT}/metatest/${FILENAME})

  set(WEBSITE_FILES ${WEBSITE_FILES} ${DST_FILE})
  add_custom_command(
    OUTPUT ${DST_FILE}
    COMMAND cp ${SRC_FILE} ${DST_FILE}
    DEPENDS example_${E}_output ${SRC_FILE}
  )
endforeach(E)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/libs/metatest/html/jquery.js
  ${WEBSITE_ROOT}/metatest/jquery.js
)
set(WEBSITE_FILES ${WEBSITE_FILES} ${WEBSITE_ROOT}/metatest/jquery.js)

# The libraries
foreach(L metatest metamonad metaparse safe_printf)
  set(DIR ${CMAKE_SOURCE_DIR}/libs/${L})
  file(GLOB FILES ${DIR}/doc/*.txt)
  list(REMOVE_ITEM FILES ${DIR}/doc/CMakeLists.txt)
  
  foreach(F ${FILES})
    get_filename_component(FN_BASE ${F} NAME_WE)
    set(FILENAME ${FN_BASE}.html)
    set(DST ${WEBSITE_ROOT}/${L}/${FILENAME})
    add_custom_command(
      OUTPUT ${DST}
      COMMAND cp ${DIR}/html/${FILENAME} ${DST}
      DEPENDS ${L}_documentation ${DIR}/html/${FILENAME}
    )
    set(WEBSITE_FILES ${WEBSITE_FILES} ${DST})
  endforeach(F)

  configure_file(${DIR}/html/style.css ${WEBSITE_ROOT}/${L}/style.css)
  set(WEBSITE_FILES ${WEBSITE_FILES} ${WEBSITE_ROOT}/${L}/style.css)
endforeach(L)

add_custom_target(website DEPENDS base_documentation ${WEBSITE_FILES})

