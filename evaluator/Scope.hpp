#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include "values/Value.hpp"

namespace rhayader {
    class Scope {
    public:
        void merge(Scope& other);
        void merge(Scope* other);

        std::unordered_map<std::string, std::shared_ptr<Value>> variables;
    };
}
