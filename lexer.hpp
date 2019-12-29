#pragma once
#include <vector>
#include <string>

#include "Token.hpp"
#include "TokenType.hpp"

namespace soviet {
	namespace lexer {
		class Lexer {
		public:
			std::vector<Token> lex(const std::string& line);
		private:
			static TokenType getType(char);
			static bool isOperator(char);

			unsigned int lineNum = 0;
		};
	}
}