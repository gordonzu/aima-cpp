module;

#include <iostream>
#include <concepts>
#include <functional>
#include <stdexcept>
#include <iostream>
#include <utility>
#include <concepts>
#include <string>
#include <any>

export module mod_agent;

export class Agent {
public:
    using Fn = std::function<std::string(std::any)>;

    Agent() = delete;

    static Agent create(Fn program = nullptr) {
        return Agent(std::move(program));
    }
    
    std::string whoami() const {
        return "<" + std::string(typeid(*this).name()) + ">";
    }

    bool is_alive() const {
        return alive_;
    }

private:
    explicit Agent(Fn p) {
        if (p == nullptr) {
            std::cout << "No valid program for " << this->whoami() << ", loading default." << '\n';

            this->p_ = [](std::any percept) -> std::string {
                std::string action;
                std::cout << "Percept=" << "percept_value" << "; action? ";
                std::getline(std::cin, action);
                return action;
            }; 
        } else {
              this->p_ = p;
        }
    }
    
    Fn p_;
    bool alive_ = true;
    bool bump_ = false;
    int performance_ = 0;
    std::vector<Agent> holding_;
};


