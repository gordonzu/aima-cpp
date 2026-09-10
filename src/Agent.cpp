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
    using Percept = std::any;
    using Program = std::function<std::string(std::any)>;

    Agent() = default;

    template <typename F>
    static Agent create(F&& f) requires std::constructible_from<Program, F> {
        return Agent(std::forward<F>(f));
    }

    std::string run() const {
        if (!has_percept_) throw std::logic_error("Agent percept not set");
        return run(percept_);
    } 

    std::string run(Percept p) const {
        if (!p_) throw std::logic_error("Agent program not set");
        return p_(std::move(p));
    }

    void set_percept(Percept p) {
        percept_ = std::move(p);
        has_percept_ = true;
    }

private:
    explicit Agent(Program p) : p_(std::move(p)) {
      if (!p_) throw std::invalid_argument("Agent requires a callable");
    }

    template <typename F>
    explicit Agent(F&& f) : p_(std::forward<F>(f)) {
      if (!p_) throw std::invalid_argument("Agent requires a callable");
    }

    Program p_;
    Percept percept_{};
    bool has_percept_ = false;
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



