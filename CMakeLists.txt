#   CMakeLists.txt
#
#   Author: Paul Hamilton (paul@visualops.com)
#   Date: 27-May-2024
#
#   Input file for building flo.
#
#   Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
#   
#   https://github.com/visualopsholdings/flo

cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0167 NEW) # Boost

project (flo)
  find_package(Boost 1.85.0 COMPONENTS program_options unit_test_framework log_setup log url REQUIRED)
  find_package(yaml-cpp REQUIRED)
  add_definitions(-DBOOST_ALL_DYN_LINK) 
  enable_testing()

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BOOSTLIBS ${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_LOG_SETUP_LIBRARY} 
  ${Boost_LOG_LIBRARY} ${Boost_URL_LIBRARY})

include_directories(include)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_library(FloLib STATIC     
    src/processor.cpp 
    src/functions.cpp
    src/transform.cpp 
    src/state.cpp
    src/generic.cpp
    src/functions/if.cpp
    src/functions/true.cpp
    src/functions/dict.cpp
    src/functions/equal.cpp
    src/functions/getmember.cpp
    src/functions/setmember.cpp
    src/functions/string.cpp
    src/functions/select.cpp
    src/functions/apply.cpp
    src/functions/cur.cpp
    src/functions/pass.cpp
    src/functions/quote.cpp
    src/functions/list.cpp
    src/functions/map.cpp
    src/functions/filter.cpp
    src/functions/head.cpp
    src/functions/tail.cpp
    src/functions/length.cpp
  )
  target_link_libraries(FloLib reflectcpp ${BOOSTLIBS})

add_executable(flo src/flo.cpp)
  target_link_libraries(flo FloLib yaml-cpp::yaml-cpp ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${BOOSTLIBS})

add_executable(SimpleTest test/simpletest.cpp)
  target_link_libraries(SimpleTest FloLib yaml-cpp::yaml-cpp ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${BOOSTLIBS})

add_test(SimpleTest SimpleTest)

add_executable(HelloWorldTest test/helloworldtest.cpp)
  target_link_libraries(HelloWorldTest FloLib yaml-cpp::yaml-cpp ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${BOOSTLIBS})

add_test(HelloWorldTest HelloWorldTest)

add_executable(LibTest test/libtest.cpp)
  target_link_libraries(LibTest FloLib yaml-cpp::yaml-cpp ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${BOOSTLIBS})

add_test(LibTest LibTest)

add_executable(ApplyTest test/applytest.cpp test/utils.cpp)
  target_link_libraries(ApplyTest FloLib yaml-cpp::yaml-cpp ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${BOOSTLIBS})

add_test(ApplyTest ApplyTest)

add_executable(MapTest test/maptest.cpp test/utils.cpp)
  target_link_libraries(MapTest FloLib yaml-cpp::yaml-cpp ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${BOOSTLIBS})

add_test(MapTest MapTest)

add_executable(FilterTest test/filtertest.cpp test/utils.cpp)
  target_link_libraries(FilterTest FloLib yaml-cpp::yaml-cpp ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${BOOSTLIBS})

add_test(FilterTest FilterTest)

add_executable(LengthTest test/lengthtest.cpp test/utils.cpp)
  target_link_libraries(LengthTest FloLib yaml-cpp::yaml-cpp ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${BOOSTLIBS})

add_test(LengthTest LengthTest)
