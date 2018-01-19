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

if(MSVC)
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

