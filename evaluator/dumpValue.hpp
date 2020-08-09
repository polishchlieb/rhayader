#ifndef SOVIET_DUMPVALUE_HPP
#define SOVIET_DUMPVALUE_HPP

#include <string>
#include <memory>
#include "values/values.hpp"

namespace evaluator {
    std::string dumpValue(const std::shared_ptr<Value>& value) {
        switch (value->type) {
            case ValueType::NumberValue: {
                const auto& v = value_cast<NumberValue>(value);
                return std::to_string(v->value);
            }
        }
    }
}

#endif //SOVIET_DUMPVALUE_HPP
