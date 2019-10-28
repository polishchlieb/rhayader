#include "lexer.hpp"

std::vector<Token> Lexer::lex(const std::string line) {
	std::vector<Token> tokens;
	const int length = line.length();
	Token current = { none };

	if (length == 0) return tokens;

	for (int i = 0; i < length + 1; i++) {
		char c = line[i];
		TokenType type = getType(c);
		if (current.type == none)
			current.type = type;

		if (c == '\'' || c == '"') {
			if (current.type == string) {
				tokens.push_back(current);
				current.type = none;
				current.value = "";
				continue;
			} else {
				if (current.type != none)
					tokens.push_back(current);

				current.type = string;
				current.value = "";
				continue;
			}
		}

		if (current.type == string) {
			current.value += c;
			continue;
		}

		if (c == ' ') {
			if (current.type == none)
				continue;
			tokens.push_back(current);
			current.type = none;
			current.value = "";
			continue;
		}
		
		if (type != current.type && current.type != none) {
			tokens.push_back(current);
			current.type = type;
			current.value = c;
			continue;
		}

		current.value += c;
	}

	if (current.type != none)
		tokens.push_back(current);

	return tokens;
}

TokenType Lexer::getType(const char c) {
	if (isdigit(c)) return number;
	if (isalpha(c)) return name;
	if (c == ' ') return none;
	if (isOperator(c)) return op;
	return none;
}

bool Lexer::isOperator(const char c) {
	return c == '-' || c == '>' || c == '='
		|| c == '(' || c == ')' || c == ','
		|| c == '+' || c == '{' || c == '}';
}
