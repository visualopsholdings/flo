#   CMakeLists.txt
#
#   Author: Paul Hamilton (paul@visualops.com)
#   Date: 27-May-2024
#
#   Input file flo.
#
#   https://github.com/visualopsholdings/flo

cmake_minimum_required(VERSION 3.5)

project (flo)
  find_package(Boost 1.85.0 COMPONENTS program_options unit_test_framework log_setup log json url REQUIRED)
  add_definitions(-DBOOST_ALL_DYN_LINK) 
  enable_testing()

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

set(BOOSTLIBS ${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_LOG_SETUP_LIBRARY} 
  ${Boost_LOG_LIBRARY} ${Boost_JSON_LIBRARY} ${Boost_URL_LIBRARY})

include_directories(include)

add_executable(SimpleTest test/simpletest.cpp 
    src/processor.cpp 
    src/functions.cpp
    src/transform.cpp 
    src/state.cpp
    src/method.cpp
    src/functions/map.cpp
    src/functions/null.cpp
    src/functions/if.cpp
    src/functions/true.cpp
    src/functions/dict.cpp
    )
  target_link_libraries(SimpleTest ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${BOOSTLIBS})

add_test(SimpleTest SimpleTest)
