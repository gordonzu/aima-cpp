module;

#include <concepts>
#include <functional>
#include <stdexcept>
#include <iostream>
#include <utility>

export module mod_agent;

export class Agent {
public:
    Agent() = default;

    template <typename F>
    static Agent create(F&& f) requires std::invocable<F&> {
        return Agent(std::forward<F>(f));
    }

    void run() const { p_(); } 

private:
    explicit Agent(std::function<void()> p) : p_(std::move(p)) {
      if (!p_) throw std::invalid_argument("Agent requires a callable");
    }

    template <typename F>
    explicit Agent(F&& f) : p_(std::forward<F>(f)) {
      if (!p_) throw std::invalid_argument("Agent requires a callable");
    }

    std::function<void()> p_;
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



