#pragma once
#include <map>
#include <any>
#include <string>
#include <iostream>

class Parser {
public:
	void parseLine(std::string line);

private:
	std::map<std::string, std::any> variables;
};