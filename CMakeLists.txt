cmake_minimum_required(VERSION 3.22)
project(BST
        LANGUAGES C CXX
        VERSION 0.0.0)

include_directories(source)

set(CMAKE_CXX_STANDARD 23)

option(BUILD_TESTS "unit tests - boost required" OFF)
option(BUILD_BENCHMARK_TESTS "benchmark tests - google benchmark required" OFF)
option(BUILD_DOCS "doxygen required" OFF)


include(cmake/ResolveDeps.cmake)
include(cmake/EnableSanitize.cmake)
include(cmake/EnableLinter.cmake)


if ( BUILD_DOCS )
    include(cmake/EnableDocs.cmake)
endif ( BUILD_DOCS )

if ( BUILD_TESTS )
    include(cmake/EnableTests.cmake)
endif ( BUILD_TESTS )

if ( BUILD_BENCHMARK_TESTS )
    include(cmake/EnableBenchmark.cmake)
endif ( BUILD_BENCHMARK_TESTS )

add_executable(BST main.cpp)


include(cmake/EnablePrecompile.cmake)
target_precompile_headers(BST PUBLIC ${PRECOMPILED_HEADERS})
