#pragma once
#include <vector>
#include <any>
#include <string>
#include <iostream>

struct Variable {
	std::string name;
	std::string type;
	std::any value;
};

class Parser {
public:
	~Parser();
	void parseLine(std::string line);

private:
	std::vector<Variable> variables;
};