include(GoogleTest)

add_executable(aima-cpp_unit_tests
    test_agents.cpp
)

target_compile_features(aima-cpp_unit_tests PRIVATE cxx_std_20)
target_link_libraries(aima-cpp_unit_tests PRIVATE aima-cpp_lib gtest gtest_main)

gtest_discover_tests(aima-cpp_unit_tests)
