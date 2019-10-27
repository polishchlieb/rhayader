#include "Parser.hpp"
#include "lexertk.hpp"

Parser::~Parser() {
	std::cout << "Parser made kaput, bye" << std::endl;
}

void Parser::parseLine(std::string line) {
	lexertk::generator generator;
	if (!generator.process(line)) {
		std::cerr << "Blyat Vadim" << std::endl;
		return;
	}

	lexertk::helper::commutative_inserter ci;
	ci.process(generator);

	for (std::size_t i = 0; i < generator.size(); ++i) {
		lexertk::token t = generator[i];
		
		if (t.value == "print") {
			std::cout << generator[i + 2].value << std::endl;
		}
		else if (t.value == "=") {
			std::string name = generator[i - 1].value;
			std::string value = generator[i + 1].value;

			auto iterator = std::find_if(variables.begin(), variables.end(), [name](const Variable& var) {
				return var.name == name;
			});

			if (iterator == variables.end()) {
				std::string type = generator[i - 2].value;
				std::any val;

				if (type == "int")
					val = std::stoi(value);
				else if (type == "string")
					val = value;

				variables.push_back(Variable{ name, type, val });
			} else {
				iterator->value = generator[i + 1].value;
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
	}
}
