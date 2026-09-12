module;

#include <any>
#include <concepts>
#include <stdexcept>
#include <utility>
#include <iostream>
#include <vector>
#include <functional>
#include <variant>

export module mod_environment;
import mod_agent;

export struct Wall { int i = 0; };

export class Environment {
public:
    using Object = std::variant<std::monostate, Agent, Wall>;
    using Fn = std::function<void(Environment&)>;

    explicit Environment(Fn f = nullptr) : f_(std::move(f)) {
        if (!f_) {
            std::cout << "No valid f for Environment, loading default.\n";
        }
    }

    void run() {
        f_(*this);
        for (const auto& obj : objects_) { 
            if(auto* a = std::get_if<Agent>(&obj)) {
                auto action = a->run("test");
                std::cout << action << '\n';
            }
            std::cout << "Not an agent.\n";
        }
    }

    void add_object(Object x) { objects_.push_back(std::move(x)); }
    void increment() { x++; std::cout << x << '\n'; }

private:
    std::vector<Object> objects_;
    std::function<void(Environment&)> f_;
    int x = 0;

};

export Environment trivial_vacuum_environment() {
   return Environment(); 
}

/*export void trivial_vacuum(Environment& env ) {
    std::cout << "Trivial Vacuum Environment!" << '\n';
    env.increment();
}*/

/*export void barking_environment() {
    std::cout << "Bark! Bark!" << '\n';
}*/


