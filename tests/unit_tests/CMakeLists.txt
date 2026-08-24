

include(GoogleTest)

add_executable(${CMAKE_PROJECT_NAME}_run
    test_agents.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME}_run
    PRIVATE aicpp_lib GTest::gtest GTest::gtest_main
)

target_compile_features(${CMAKE_PROJECT_NAME}_run PRIVATE cxx_std_20)

enable_testing()
gtest_discover_tests(${CMAKE_PROJECT_NAME}_run)

