#pragma once
#include <iostream>
#include <vector>
#include "Lexer.hpp"

namespace soviet {
	namespace lexer {
		namespace helper {
			inline std::string toString(TokenType type) {
				switch (type) {
					case TokenType::name: return "name";
					case TokenType::none: return "none";
					case TokenType::number: return "number";
					case TokenType::op: return "operator";
					case TokenType::string: return "string";
				}
			}

			inline void dump(const std::vector<Token>& tokens) {
				for (auto& token : tokens) {
					std::cout << "Line: " << token.line
						<< " Position: " << token.position
						<< " Type: " << toString(token.type)
						<< " Value: " << token.value
						<< std::endl;
				}
			}
		}
	}
}