

set(BINARY ${CMAKE_PROJECT_NAME})

add_library(${BINARY}_lib STATIC)
target_compile_features(${BINARY}_lib PRIVATE cxx_std_20)

# Register C++20 modules
target_sources(${BINARY}_lib
    PUBLIC
        FILE_SET CXX_MODULES
        FILES
            ReflexVacuumAgent.cpp
            TrivialVacuumEnvironment.cpp
)

