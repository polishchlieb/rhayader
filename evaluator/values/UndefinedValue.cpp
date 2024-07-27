#include "UndefinedValue.hpp"

namespace rhayader {
	UndefinedValue::UndefinedValue() : Value{ValueType::UndefinedValue} {}

	bool UndefinedValue::equals(const std::shared_ptr<Value>& other) {
		return other->type == type;
	}

	std::shared_ptr<rhayader::Value> UndefinedValue::clone() {
		return std::make_shared<UndefinedValue>();
	}

	std::string UndefinedValue::dump() const {
		return "<undefined>";
	}
}