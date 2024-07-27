#pragma once
#include <vector>
#include "Value.hpp"
#include <memory>
#include <string>
#include <unordered_map>

namespace rhayader {
    class Evaluator;

    class ModuleValue : public Value {
    public:
        explicit ModuleValue(Evaluator& evaluator);
        ModuleValue(Evaluator& evaluator, std::string name);
        ModuleValue(Evaluator& evaluator, std::string name, std::unordered_map<std::string, std::shared_ptr<Value>> variables);

        bool equals(const std::shared_ptr<Value>& other) override;
        std::shared_ptr<Value> clone() override;
        std::string dump() const override;

        std::string name;
        std::unordered_map<std::string, std::shared_ptr<Value>> variables;

        std::shared_ptr<Value> get(const std::string& prop);
    private:
        Evaluator& evaluator;
    };
}