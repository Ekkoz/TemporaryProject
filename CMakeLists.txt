cmake_minimum_required(VERSION 2.6)
project(TemporaryProject)

add_library(TemporaryProject
	src/Calculator.cpp)

include_directories("include")

option(BUILD_TESTS "compile tests executable" OFF)

if(BUILD_TESTS)
	add_subdirectory("test")
endif(BUILD_TESTS)

#
# The whole MSVC
#
if(MSVC)
	if(BUILD_TESTS)
		set(MSVC_RUNTIME "dynamic")
	endif()
	# Default to statically-linked runtime.
	if("${MSVC_RUNTIME}" STREQUAL "")
  		set(MSVC_RUNTIME "static")
	endif()
	# Set compiler options.
	set(variables
	  CMAKE_C_FLAGS_DEBUG
	  CMAKE_C_FLAGS_MINSIZEREL
	  CMAKE_C_FLAGS_RELEASE
	  CMAKE_C_FLAGS_RELWITHDEBINFO
	  CMAKE_CXX_FLAGS_DEBUG
	  CMAKE_CXX_FLAGS_MINSIZEREL
	  CMAKE_CXX_FLAGS_RELEASE
	  CMAKE_CXX_FLAGS_RELWITHDEBINFO
	)
	if(${MSVC_RUNTIME} STREQUAL "static")
	  message(STATUS
	    "MSVC -> forcing use of statically-linked runtime."
	  )
	  foreach(variable ${variables})
	    if(${variable} MATCHES "/MD")
	      string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
	    endif()
	  endforeach()
	else()
	  message(STATUS
	    "MSVC -> forcing use of dynamically-linked runtime."
	  )
	  foreach(variable ${variables})
	    if(${variable} MATCHES "/MT")
	      string(REGEX REPLACE "/MT" "/MD" ${variable} "${${variable}}")
	    endif()
	  endforeach()
	endif()
endif()
