module;

#include <any>
#include <concepts>
#include <stdexcept>
#include <utility>
#include <iostream>
#include <vector>
#include <functional>

export module mod_environment;
import mod_agent;

export class Environment {
public:
    Environment() = default;

    template <typename F>
    static Environment create(F&& f) requires std::invocable<F&, Environment&> {
        return Environment(std::forward<F>(f));
    }

    void run() {
        p_(*this);
        for (const auto& agent : agents_) { 
            std::string result = agent.run_agent_program(x);
            std::cout << result << '\n';
        }
    }

    void add_agent(Agent a) { agents_.push_back(std::move(a)); }
    void increment() { x++; std::cout << x << '\n'; }

private:
    explicit Environment(std::function<void(Environment&)> p) : p_(std::move(p)) {
        if (!p_) throw std::invalid_argument("Environment requires a callable");
    }

    template <typename F>
    explicit Environment(F&& f) : p_(std::forward<F>(f)) {
        if (!p_) throw std::invalid_argument("Environment requires a callable");
    }

    std::vector<Agent> agents_;
    std::function<void(Environment&)> p_;
    int x = 0;

};

export void trivial_vacuum(Environment& env ) {
    std::cout << "Trivial Vacuum Environment!" << '\n';
    env.increment();
}

export void barking_environment() {
    std::cout << "Bark! Bark!" << '\n';
}


