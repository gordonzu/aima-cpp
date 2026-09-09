#include <gtest/gtest.h>

import mod_agent;
import mod_context;

void quack() { std::cout << "Quack!\n"; }
void bark()  { std::cout << "Bark!\n"; }

TEST(AgentConstructorTest, MakeCreateFunctionTakeCallable)
{
    auto x = Agent::create(quack);
    x.run(); 
}

TEST(AgentsModulesTest, ImportsCompileAndPass) 
{
    auto x = Agent();
    auto y = Context();

    (void)x;
    (void)y;
    SUCCEED();
}


