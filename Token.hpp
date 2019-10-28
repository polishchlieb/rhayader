#pragma once
#include <string>

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