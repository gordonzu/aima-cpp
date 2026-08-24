include(GoogleTest)

add_executable(aicpp_unit_tests
    test_agents.cpp
)

target_compile_features(aicpp_unit_tests PRIVATE cxx_std_20)
target_link_libraries(aicpp_unit_tests PRIVATE aicpp_lib gtest gtest_main)

gtest_discover_tests(aicpp_unit_tests)
