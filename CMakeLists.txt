# Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 2.6)
project(metatest)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(Pandoc)
include(Files)

enable_testing()

include_directories("include")

set(BUILD_SHARED_LIBS ON)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  subdirs(src test example)
else()
  # Documentation generation is supported on Unix only
  subdirs(src test example doc)
  
  # metatest code samples
  foreach(E
    boost_mpl_unit_test
    metatest_example
    stream_type
    boost_test_assertion
    ugly
    misc
    reverse
  )
    set(EXAMPLE_OUTPUTS ${EXAMPLE_OUTPUTS} example_${E}_output)
  endforeach(E)

  add_custom_target(website DEPENDS metatest_documentation ${EXAMPLE_OUTPUTS})
endif()


# Installation
macro(install_with_dir PREFIX_TO_CUT)
 
 string(LENGTH ${PREFIX_TO_CUT} PREFIX_LEN)

 foreach(F ${ARGN})
   string(REGEX MATCH "(.*)[/\\]" DIR ${F})
   string(LENGTH ${DIR} DIR_LEN)
   math(EXPR DIR_KEEP "${DIR_LEN} - ${PREFIX_LEN}")
   string(SUBSTRING ${DIR} ${PREFIX_LEN} ${DIR_KEEP} DIR2)
   install(FILES ${F} DESTINATION include/${DIR2})
 endforeach(F)
          
endmacro(install_with_dir)
           

file(GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
install_with_dir(${CMAKE_CURRENT_SOURCE_DIR} ${HEADER_FILES})



