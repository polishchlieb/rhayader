#pragma once
#include <string>

enum TokenType {
	none,
	number,
	name,
	string,
	op
};

struct Token {
	TokenType type;
	int line;
	int position;
	std::string value;
};