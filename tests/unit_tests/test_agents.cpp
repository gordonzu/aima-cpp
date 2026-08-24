// Gordon Zuehlke on 8/27/18

import rv_agent;
import tv_environment;

#include <string>
#include <vector>
#include "gtest/gtest.h"

using namespace::testing;

class TestAgents: public Test {
public:
    TestAgents() = default;

};

TEST_F(TestAgents, testReflexVacuumAgent) {
    ReflexVacuumAgent agent{};
    TrivialVacuumEnvironment env{};

    env.add_object(agent);
    env.run();

    ASSERT_EQ(env.status, "{(1,0): 'Clean', (0,0): 'Clean'}");
}


