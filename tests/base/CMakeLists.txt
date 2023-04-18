project(empty)

add_executable(empty empty_test.cpp)

target_link_libraries(empty PRIVATE Boost::unit_test_framework)

add_test(
        NAME empty
        COMMAND empty)