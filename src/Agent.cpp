module;

#include <concepts>
#include <iostream>
#include <functional>
#include <stdexcept>
#include <vector>

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


