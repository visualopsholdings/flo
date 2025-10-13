#   CMakeLists.txt
#
#   Author: Paul Hamilton (paul@visualops.com)
#   Date: 27-May-2024
#
#   Input file flo.
#
#   https://github.com/visualopsholdings/flo

cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0167 NEW) # Boost

project (flo)
  find_package(Boost 1.85.0 COMPONENTS program_options unit_test_framework log_setup log url REQUIRED)
  add_definitions(-DBOOST_ALL_DYN_LINK) 
  enable_testing()

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)

set(BOOSTLIBS ${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_LOG_SETUP_LIBRARY} 
  ${Boost_LOG_LIBRARY} ${Boost_URL_LIBRARY})

include_directories(include)

add_library(FloLib SHARED     
    src/processor.cpp 
    src/functions.cpp
    src/transform.cpp 
    src/state.cpp
    src/generic.cpp
    src/functions/null.cpp
    src/functions/if.cpp
    src/functions/true.cpp
    src/functions/dict.cpp
    src/functions/equal.cpp
    src/functions/getmember.cpp
    src/functions/setmember.cpp
    src/functions/string.cpp
    src/functions/select.cpp
  )
  target_link_libraries(FloLib reflectcpp ${BOOSTLIBS})

add_executable(Flo src/flo.cpp)
  target_link_libraries(Flo FloLib ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${BOOSTLIBS})

add_executable(SimpleTest test/simpletest.cpp)
  target_link_libraries(SimpleTest FloLib ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${BOOSTLIBS})

add_test(SimpleTest SimpleTest)

add_executable(HelloWorldTest test/helloworldtest.cpp)
  target_link_libraries(HelloWorldTest FloLib ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${BOOSTLIBS})

add_test(HelloWorldTest HelloWorldTest)
