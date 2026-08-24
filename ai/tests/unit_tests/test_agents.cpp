#include <gtest/gtest.h>

import rv_agent;
import tv_environment;

TEST(AgentsModulesTest, ImportsCompileAndPass) {
    ReflexVacuumAgent agent{};
    TrivialVacuumEnvironment environment{};

    (void)agent;
    (void)environment;
    SUCCEED();
}
