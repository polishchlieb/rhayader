#include "ExplicitReturnValue.hpp"

rhayader::ExplicitReturnValue::ExplicitReturnValue(std::shared_ptr<Value> value)
	: Value{ValueType::ExplicitReturnValue}, value(std::move(value))
{}

bool rhayader::ExplicitReturnValue::equals(const std::shared_ptr<Value>& other) {
	return false;
}

std::shared_ptr<rhayader::Value> rhayader::ExplicitReturnValue::clone() {
	return std::make_shared<ExplicitReturnValue>(value->clone());
}

std::string rhayader::ExplicitReturnValue::dump() const {
	return "<explicit return value>";
}
