#pragma once
#include <vector>
#include <string>
#include "Token.hpp"

class Lexer {
public:
	std::vector<Token> lex(const std::string&);
	static TokenType getType(const char);
	static bool isOperator(const char);

private:
	int line = 0;
};