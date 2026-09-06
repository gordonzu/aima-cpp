#include <gtest/gtest.h>

import mod_agent;
import mod_context;

TEST(AgentsModulesTest, ImportsCompileAndPass) 
{
    auto x = Agent();
    auto y = Context();

    (void)x;
    (void)y;
    SUCCEED();
}


