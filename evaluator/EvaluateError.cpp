#include "EvaluateError.hpp"

namespace rhayader {
	EvaluateError::EvaluateError(std::string value)
		: Error{ErrorType::Evaluate}, value(std::move(value))
	{}

	std::string EvaluateError::name() const noexcept {
		return "EvaluateError";
	}

	std::string EvaluateError::message() const noexcept {
		return this->value;
	}
}