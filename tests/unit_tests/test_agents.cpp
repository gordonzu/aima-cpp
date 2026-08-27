#include <gtest/gtest.h>

import rv_agent;
import tv_environment;

TEST(AgentsModulesTest, ImportsCompileAndPass) 
{
    auto x = ReflexVacuumAgent();
    auto y = TrivialVacuumEnvironment();

    (void)x;
    (void)y;
    SUCCEED();
}


