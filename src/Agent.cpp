module;

#include <concepts>
#include <functional>
#include <stdexcept>
#include <iostream>
#include <utility>
#include <concepts>
#include <any>

export module mod_agent;

export class Agent {
public:
    using Fn = std::function<std::string(std::any)>;

    Agent() = default;

    template <typename F>
    static Agent create(F&& f) requires std::constructible_from<Fn, F> {
        return Agent(std::forward<F>(f));
    }

    std::string run_agent_program(std::any arg) const { 
      return p_(std::move(arg));
    } 

private:
    explicit Agent(Fn p) : p_(std::move(p)) {
      if (!p_) throw std::invalid_argument("Agent requires a callable");
    }

    template <typename F>
    explicit Agent(F&& f) : p_(std::forward<F>(f)) {
      if (!p_) throw std::invalid_argument("Agent requires a callable");
    }

    Fn p_;
};

export void quack_agent() {
    std::cout << "Quack! Quack!" << '\n';
}

export void test_a() {
    std::cout << "Test_a!" << '\n';
}

export void test_b() {
    std::cout << "Test_b!" << '\n';
}



