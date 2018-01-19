cmake_minimum_required(VERSION 2.6)
project(TemporaryProject_Test)

include_directories("../include" "googletest/include")

add_subdirectory("googletest")

add_executable(TemporaryProject_Test
	src/Calculator_Test.cpp)

# Linking the GoogleTest framework.
target_link_libraries(TemporaryProject_Test gtest gtest_main)

# Linking the tested library.
target_link_libraries(TemporaryProject_Test TemporaryProject)
