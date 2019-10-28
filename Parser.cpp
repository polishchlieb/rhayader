#include "Parser.hpp"

Parser::~Parser() {
	std::cout << "Parser made kaput, bye" << std::endl;
}

void Parser::parseLine(const std::vector<Token> tokens) {
	int i = 0;
	for (Token t : tokens) {
		if (t.value == "print") {
			std::cout << tokens[i + 2].value << std::endl;
		}
		else if (t.value == "=") {
			std::string name = tokens[i - 1].value;
			std::string value = tokens[i + 1].value;

			auto iterator = std::find_if(variables.begin(), variables.end(), [name](const Variable& var) {
				return var.name == name;
			});

			if (iterator == variables.end()) {
				std::string type = tokens[i - 2].value;
				std::any val;

				if (type == "int")
					val = std::stoi(value);
				else if (type == "string")
					val = value;

				variables.push_back(Variable{ name, type, val });
			} else {
				iterator->value = tokens[i + 1].value;
			}
		}
		else if (t.value == "variables") {
			for (Variable var : variables) {
				if (var.type == "int") {
					std::cout << "(" << var.type << ") " << var.name << " = " << std::to_string(std::any_cast<int>(var.value)) << std::endl;
				}
				else if (var.type == "string") {
					std::cout << "(" << var.type << ") " << var.name << " = " << std::any_cast<std::string>(var.value) << std::endl;
				}
			}
		}

		++i;
	}
}
