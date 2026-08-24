// TrivialVacuumEnvironment.cpp gordonyx 8-24-26
//

module;

#include <string>
#include <vector>

export module tv_environment;

import rv_agent;

export class TrivialVacuumEnvironment {
    public:
        TrivialVacuumEnvironment() : status("Clean") {}

        void add_object(ReflexVacuumAgent agent);
        void run();

        std::string status;
};

void TrivialVacuumEnvironment::add_object(ReflexVacuumAgent agent) {
    return;
}

void TrivialVacuumEnvironment::run() {
    return;
}


