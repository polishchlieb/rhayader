#include "lexer.hpp"

namespace soviet {
	namespace lexer {
		std::vector<Token> Lexer::lex(const std::string& line) {
			lineNum++;

			std::vector<Token> tokens;
			const unsigned int length = static_cast<unsigned int>(line.length());
			Token current = { TokenType::none, lineNum, 1 };

			if (length == 0) return tokens;

			for (unsigned int i = 0; i < length + 1; ++i) {
				char c = line[i];

				auto type = getType(c);
				if (current.type == TokenType::none)
					current.type = type;

				if (c == '\'' || c == '"') {
					if (current.type == TokenType::string) {
						tokens.push_back(current);
						current.type = TokenType::none;
						current.value = "";
						continue;
					} else {
						if (current.type != TokenType::none)
							tokens.push_back(current);

						current.type = TokenType::string;
						current.value = "";
						current.position = i + 1;
						continue;
					}
				} else if (current.type == TokenType::string) {
					current.value += c;
					continue;
				} else if (c == ' ') {
					if (current.type == TokenType::none)
						continue;
					tokens.push_back(current);
					current.type = TokenType::none;
					current.value = "";
					current.position = i + 1;
					continue;
				} else if (type != current.type && current.type != TokenType::none) {
					tokens.push_back(current);
					current.type = type;
					current.value = c;
					current.position = i + 1;
					continue;
				} 
				// TODO: Normalize position!
				// TODO: Reduce operator stuff
				else if (current.value == ")" && c == ',') {
					tokens.push_back(current);
					current.type = type;
					current.value = c;
					current.position = i + 1;
					continue;
				} else if (current.value == ")" && c == ')') {
					tokens.push_back(current);
					current.type = type;
					current.value = c;
					current.position = i + 1;
					continue;
				}

				current.value += c;
			}

			if (current.type != TokenType::none)
				tokens.push_back(current);

			return tokens;
		}

		TokenType Lexer::getType(char c) {
			if (isdigit(c)) return TokenType::number;
			if (isalpha(c)) return TokenType::name;
			if (c == ' ') return TokenType::none;
			if (isOperator(c)) return TokenType::op;
			return TokenType::none;
		}

		bool Lexer::isOperator(char c) {
			return c == '-' || c == '>' || c == '='
				|| c == '(' || c == ')' || c == ','
				|| c == '+' || c == '{' || c == '}'
				|| c == '&';
		}
	}
}