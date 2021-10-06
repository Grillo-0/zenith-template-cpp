cmake_minimum_required(VERSION 3.14)
set(This MyProject)
project(${This} C CXX)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#######################
# BUILDING GTEST DEPS #
#######################
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
set(Headers
    MyProject.hpp
)
set(Sources
    MyProject.cpp
)
add_library(${This} STATIC ${Sources} ${Headers})
add_subdirectory(test)

find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
    file(GLOB_RECURSE ALL_CXX_SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/*.[ch]pp
    )

    add_custom_target(
        TARGET format
        COMMAND clang-format
        -i
        -style=file
        ${ALL_CXX_SOURCE_FILES}
    )
endif()
