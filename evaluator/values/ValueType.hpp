#pragma once
#include <string>

namespace rhayader {
    enum class ValueType {
        NumberValue,
        BooleanValue,
        StringValue,
        UndefinedValue,
        FunctionValue,
        ExplicitReturnValue,
        ArrayValue,
        MapValue,
        RangeValue,
        NullValue,
        ModuleValue
    };

    std::string dumpValueType(const ValueType type);
}
