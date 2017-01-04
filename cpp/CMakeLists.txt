cmake_minimum_required (VERSION 2.8)
project (designpatterncpp)

include(ctest)

# CMAKE_BINARY_DIR => ${PROJECT_SOURCE_DIR}/build
# CMAKE_SOURCE_DIR => ${PROJECT_SOURCE_DIR}
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # put .exe and .dll files here
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # put .so files here (if you ever build on Linux)
set(CMAKE_MODULE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # put .dll and .so files for MODULE targets here
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)  # put .lib files here

set(CMAKE_FILES_DIRECTORY  ${CMAKE_BINARY_DIR}/CMakeFiles)  # the directory within the current binary directory that contains all the CMake generated files.

message(a "CMAKE_BINARY_DIR is ${CMAKE_BINARY_DIR}")
message(a "CMAKE_SOURCE_DIR is ${CMAKE_SOURCE_DIR}")
message(b "CMAKE_FILES_DIRECTORY  is ${CMAKE_FILES_DIRECTORY}")
message(c "CMAKE_RUNTIME_OUTPUT_DIRECTORY is ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(d "CMAKE_LIBRARY_OUTPUT_DIRECTORY is ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(e "CMAKE_MODULE_OUTPUT_DIRECTORY is ${CMAKE_MODULE_OUTPUT_DIRECTORY}")
message(f "CMAKE_ARCHIVE_OUTPUT_DIRECTORY is ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message(g "PROJECT_SOURCE_DIR is ${PROJECT_SOURCE_DIR}")


# The version number.
set (DESIGN_PATTERN_CPP_MAJOR 1)
set (DESIGN_PATTERN_CPP_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
   "${PROJECT_SOURCE_DIR}/inc/DesignPatternCPPConfig.h.in"
   "${PROJECT_BINARY_DIR}/inc/DesignPatternCPPConfig.h"
   )

# add the binary tree to the search path for include files
# so that we will find DesignPatternCPPConfig.h
include_directories("${PROJECT_BINARY_DIR}")
include_directories ("${PROJECT_SOURCE_DIR}/src/patterns")

# options
option (USE_DP_CLASSES "Use our design pattern classes" ON)

# add the MathFunctions library?
#
if (USE_DP_CLASSES)
   include_directories ("${PROJECT_SOURCE_DIR}/src/patterns")
   add_subdirectory (${PROJECT_SOURCE_DIR}/src/)
   #add_subdirectory (${PROJECT_SOURCE_DIR}/src/tests)
   #add_subdirectory (${PROJECT_SOURCE_DIR}/src/patterns)
   #set (EXTRA_LIBS ${EXTRA_LIBS} testlib)
endif (USE_DP_CLASSES)

install (FILES "${PROJECT_BINARY_DIR}/inc/DesignPatternCPPConfig.h"
                  DESTINATION ${PROJECT_BINARY_DIR}/inc)

# enable_testing()

# does the application run
add_test (testlib_utruns bin/testlib_ut 1 2 +)

#define a macro to simplify adding tests
macro (do_test name_ut arg1 arg2 arg3 result)
  add_test (${name_ut}_${arg1}_${arg2}_${arg3} bin/${name_ut} ${arg1} ${arg2} ${arg3})
  set_tests_properties (${name_ut}_${arg1}_${arg2}_${arg3}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endmacro (do_test)

# do a bunch of result based tests
do_test (testlib_ut 1 2 + "is 3")
do_test (testlib_ut 2 3.5 * "is 7")
do_test (testlib_ut 4.2 2.1 - "is 2.1")
do_test (testlib_ut 4.2 2 / "is 2.1")

do_test (builder_ut 1 1 _ "Pizza with pan baked dough, hot sauce and pepperoni")

do_test (factory_ut 1 1 _ "laptop")


# regular expression
set(contents "Hello\nWorld!")
message("contents='${contents}'")

string(REGEX MATCHALL "Hello[\\r\\n\\t ]*World!" matches ${contents})
message("Matches1:")
foreach(match ${matches})
  message("match='${match}'")
endforeach()

string(REGEX MATCHALL "Hello[\r\n\t ]*World!" matches ${contents})
message("Matches2:")
foreach(match ${matches})
  message("match='${match}'")
endforeach()

set(contents2 "Info: IoT Hub SDK for C, version 1.1.2\nfromConnectionString SUCCEEDED!")
message("contents2='${contents2}'")

string(REGEX MATCHALL "Info.*[\r\n\t ]*from.*SUCCEEDED" matches ${contents2})
message("Matches22:")
foreach(match ${matches})
  message("match22='${match}'")
endforeach()
