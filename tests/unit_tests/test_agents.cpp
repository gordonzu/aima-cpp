#include <gtest/gtest.h>

import mod_agent;
import mod_environment;

TEST(EnvironmentCreateTest, MakeEnvironmentCreateTakeCallable)
{
   auto x = Environment::create(trivial_vacuum);
   x.run();

   //auto y = Environment::create([] { std::cout << "BARK!!" << '\n'; } );
   //y.run();
}

TEST(AgentCreateTest, MakeAgentCreateTakeCallable)
{
    auto x = Agent::create(quack_agent);
    x.run();

    auto y = Agent::create([] { std::cout << "QUACK!!" << '\n'; } );
    y.run();
}

TEST(AgentsModulesTest, ImportsCompileAndPass) 
{
    auto x = Agent();
    auto y = Environment();

    (void)x;
    (void)y;
    SUCCEED();
}


