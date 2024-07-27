#pragma once
#include "Scope.hpp"

namespace rhayader {
    class Evaluator;

    class GlobalScope : public Scope {
    public:
        GlobalScope(Evaluator& evaluator);
    };
}
