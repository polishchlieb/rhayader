#pragma once
#include <vector>
#include <string>
#include <regex>
#include "Token.hpp"

class Lexer {
public:
	static std::vector<Token> lex(const std::string line);
	static TokenType getType(const char c);
	static bool isOperator(const char c);
};