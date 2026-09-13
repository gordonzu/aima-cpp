#include <gtest/gtest.h>

import mod_agent;
import mod_environment;

TEST(AgentTest, RunRandomVacuumAgent) {
   SUCCEED(); 
}


TEST(AgentTest, SetupTrivialVacuumEnvironment) {

    // initialize environment state
    


    // add the agent to the environment 
    auto x = random_vacuum_agent();
    auto y = trivial_vacuum_environment();
    y.add_object(x);

    ASSERT_EQ(1, y.count());


}

TEST(AgentTest, CreateDefaults) {
    auto x = Agent();
    auto y = Environment();

    (void)x;
    (void)y;
    SUCCEED();
}



/*TEST(EnvironmentCreateTest, MakeEnvironmentCreateTakeCallable)
{
   auto x = Environment::create(trivial_vacuum);
   x.run();

   //auto y = Environment::create([] { std::cout << "BARK!!" << '\n'; } );
   //y.run();
}
*/

/*TEST(AgentCreateTest, MakeAgentCreateTakeCallable)
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


    x.run(42);
    x.run(std::string("Hello"));
    x.run(3.14);
}
*/

