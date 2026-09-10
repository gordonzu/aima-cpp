#include <gtest/gtest.h>

import mod_agent;
import mod_environment;

/*TEST(EnvironmentCreateTest, MakeEnvironmentCreateTakeCallable)
{
   auto x = Environment::create(trivial_vacuum);
   x.run();

   //auto y = Environment::create([] { std::cout << "BARK!!" << '\n'; } );
   //y.run();
}
*/

TEST(AgentCreateTest, MakeAgentCreateTakeCallable)
{
    auto x = Agent::create([](std::any value) -> std::string {
        if (auto p = std::any_cast<int>(&value)) {
            return "int: " + std::to_string(*p);
        }
        if (auto p = std::any_cast<std::string>(&value)) {
            return "string: " + *p;
        }
        return std::string("unsupported type[: ") + value.type().name();
    });


    x.run_agent_program(42);
    x.run_agent_program(std::string("Hello"));
    x.run_agent_program(3.14);
}

TEST(AgentsModulesTest, ImportsCompileAndPass) 
{
    auto x = Agent();
    auto y = Environment();

    (void)x;
    (void)y;
    SUCCEED();
}


