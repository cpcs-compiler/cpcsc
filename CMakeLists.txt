cmake_minimum_required (VERSION 3.8)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "Prevented in-tree build. Please create a build directory outside of the source code and call cmake from there")
endif()

project ("cpcsc")

set (CMAKE_C_STANDARD 11)
set (CMAKE_C_STANDARD_REQUIRED ON)
set (CMAKE_C_EXTENSIONS OFF)

if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE "Debug")
endif (NOT CMAKE_BUILD_TYPE)

option (WITH_COVERAGE "Build with code coverage" OFF)

find_package (BISON REQUIRED)
find_package (FLEX REQUIRED)
find_package (LLVM CONFIG REQUIRED)

add_definitions (${LLVM_DEFINITIONS})
include_directories (
    src/
    ${LLVM_INCLUDE_DIRS}
)
llvm_map_components_to_libnames (llvm_libs core executionengine interpreter analysis native bitwriter)

add_subdirectory(src)

if (WITH_COVERAGE)
	add_compile_options (-O0 -g --coverage)
endif (WITH_COVERAGE)
