module;

#include <iostream>
#include <vector>
#include <functional>

export module mod_environment;
import mod_agent;

export class Environment {
public:
    Environment() = default;

    template <typename F>
    static Environment create(F&& f) requires std::invocable<F&> {
        return Environment(std::forward<F>(f));
    }

    void run() const {
        p_();
        for (const auto& agent : agents_) agent.run(); 
    }

    void add_agent(Agent a) { agents_.push_back(std::move(a)); }

private:
    explicit Environment(std::function<void()> p) : p_(std::move(p)) {
        if (!p_) throw std::invalid_argument("Environment requires a callable");
    }

    template <typename F>
    explicit Environment(F&& f) : p_(std::forward<F>(f)) {
        if (!p_) throw std::invalid_argument("Environment requires a callable");
    }

    std::vector<Agent> agents_;
    std::function<void()> p_;


};

export void barking_environment() {
    std::cout << "Bark! Bark!" << '\n';
}
