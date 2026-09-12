module;

#include <iostream>
#include <functional>
#include <iostream>
#include <utility>
#include <string>
#include <random>
#include <typeinfo>
#include <any>

export module mod_agent;

export class Agent {
public:
    using Percept = std::any;   
    using Action  = std::string;
    using Fn = std::function<Action(const Percept&)>;

    bool alive = true;
    bool bump = false;
    std::vector<std::string> holding{};
    int performance = 0;

    explicit Agent(Fn f = nullptr) : f_(std::move(f)) {
        if (!f_) {
            std::cout << "Can't find a valid f for Agent, loading default.\n";
            f_ = [](const Percept&) -> Action {
                std::cout << "Percept=<...>; action? ";
                Action action;
                std::getline(std::cin, action);
                return action;
            };
        }
    }

    Action run(const Percept& percept) const {
        return f_(percept);
    }

private:
    Fn f_;
};

Agent::Fn random_agent_program(const std::vector<std::string>& actions) {
    return [actions](std::any percept) -> std::string {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, actions.size() - 1);
        return actions[dis(gen)];
    };
}

export Agent random_vacuum_agent() {
    return Agent(random_agent_program({"Right", "Left", "Suck", "NoOp"}));
}






















