cmake_minimum_required(VERSION 2.6)
project(TemporaryProject)

add_library(TemporaryProject
	src/Calculator.cpp)

include_directories("include")

option(BUILD_TESTS "compile tests executable" OFF)

if(BUILD_TESTS)
	add_subdirectory("test")
endif(BUILD_TESTS)
