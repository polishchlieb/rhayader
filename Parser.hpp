#pragma once
#include <vector>
#include <any>
#include <string>
#include <iostream>
#include <algorithm>
#include "Token.hpp"

struct Variable {
	std::string name;
	std::string type;
	std::any value;
};

class Parser {
public:
	~Parser();
	void parseLine(const std::vector<Token> tokens);

private:
	std::vector<Variable> variables;
};