#include "NoTokensError.hpp"

namespace rhayader {
	NoTokensError::NoTokensError() : Error{ErrorType::NoTokens} {}

	std::string NoTokensError::message() const {
		return "";
	}

	std::string NoTokensError::name() const {
		return "NoTokensError";
	}
}