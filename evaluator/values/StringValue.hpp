#pragma once
#include <string>
#include "Value.hpp"

namespace rhayader {
    class StringValue : public Value {
    public:
        std::string value;

        explicit StringValue(std::string value);

        bool equals(const std::shared_ptr<Value>& other) override;
        std::shared_ptr<Value> clone() override;
        std::string dump() const override;

        void append(const std::string& str);
        size_t length() const;
        void replaceAll(const std::string& substr, const std::string& replaceWith);
        void toUpperCase();
        void toLowerCase();

        std::shared_ptr<Value> add(const std::shared_ptr<Value>& right);
        std::shared_ptr<Value> multiply(const std::shared_ptr<Value>& right);
    };
}
