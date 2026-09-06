add_library(aicpp_lib)

target_sources(aicpp_lib
    PUBLIC
        FILE_SET CXX_MODULES
        FILES
            Agent.cpp
            Context.cpp
)

target_compile_features(aicpp_lib PUBLIC cxx_std_20)
