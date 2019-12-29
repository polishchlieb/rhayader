#pragma once
#include <string>
#include "TokenType.hpp"

namespace soviet {
	namespace lexer {
		struct Token {
			TokenType type;
			unsigned int line = 0;
			unsigned int position = 0;
			std::string value;
		};
	}
}