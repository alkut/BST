if ( BUILD_TESTS )
    set(Boost_USE_STATIC_LIBS ON)
    find_package(Boost 1.74 COMPONENTS unit_test_framework REQUIRED)
    if(Boost_FOUND)
        include_directories(${Boost_INCLUDE_DIRS})
        message(STATUS "Using Boost Version ${Boost_VERSION}")
    else()
        message(FATAL_ERROR "Appropriate Version of Boost haven't been found")
    endif()
endif ( BUILD_TESTS)

if ( BUILD_BENCHMARK_TESTS )
    find_package(benchmark 1.7 REQUIRED)
    if (benchmark_FOUND)
        include_directories(${benchmark_INCLUDE_DIR})
        message(STATUS "Using benchmark Version ${benchmark_VERSION}")
    else()
        message(FATAL_ERROR "Appropriate Version of benchmark haven't been found")
    endif()
endif ( BUILD_BENCHMARK_TESTS )