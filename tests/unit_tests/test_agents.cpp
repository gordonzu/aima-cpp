#include <gtest/gtest.h>

import mod_agent;
import mod_environment;

void quack() { std::cout << "Quack!\n"; }
void bark()  { std::cout << "Bark!\n"; }

TEST(AgentConstructorTest, MakeAgentCreateTakeCallable)
{
    auto x = Agent::create(quack);
    x.run(); 
}

TEST(AgentsModulesTest, ImportsCompileAndPass) 
{
    auto x = Agent();
    auto y = Environment();

    (void)x;
    (void)y;
    SUCCEED();
}


