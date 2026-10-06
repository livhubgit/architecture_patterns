cmake_minimum_required(VERSION 3.14)
project(QuadraticSolver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_library(solver src/solve.cpp)
target_include_directories(solver PUBLIC src)

enable_testing()
add_executable(solver_tests tests/test_solve.cpp)
target_link_libraries(solver_tests solver GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(solver_tests)