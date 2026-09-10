add_library(aima-cpp_lib)

target_sources(aima-cpp_lib
    PUBLIC
        FILE_SET CXX_MODULES
        FILES
            Agent.cpp
            Environment.cpp
)

target_compile_features(aima-cpp_lib PUBLIC cxx_std_20)
