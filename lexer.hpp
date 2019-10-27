#pragma once
#include <vector>
#include <string>
#include <regex>

enum TokenType {
	none = -1,
	number = 0,
	name = 1,
	string = 2,
	op = 3
};

struct Token {
	TokenType type;
	std::string value;
};

class Lexer {
public:
	static std::vector<Token> lex(const std::string line);
	static TokenType getType(const char c);
	static bool isOperator(const char c);
};