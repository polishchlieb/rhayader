#pragma once
#include <string>
#include "TokenType.hpp"

namespace soviet {
	namespace lexer {
		struct Token {
			TokenType type;
			unsigned int line;
			unsigned int position;
			std::string value;
		};
	}
}