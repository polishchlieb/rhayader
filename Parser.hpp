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

typedef struct Node {
	Token token;
	Node* children;
};

class Parser {
public:
	~Parser();
	void parse(const std::vector<Token> tokens);

private:
	std::vector<Variable> variables;
};