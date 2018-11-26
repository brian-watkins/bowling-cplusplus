cmake_minimum_required(VERSION 3.7)
set (CMAKE_CXX_STANDARD 11)

set(PROJECT_NAME BowlingKata)
project(${PROJECT_NAME})

add_library(BowlingKata_Lib src/BowlingEngine.cpp)
add_executable(BowlingKata main.cpp)

target_link_libraries(BowlingKata BowlingKata_Lib)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} src/)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests/tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runTests BowlingKata_Lib)

enable_testing()

add_test(NAME BowlingKata_Tests COMMAND runTests)