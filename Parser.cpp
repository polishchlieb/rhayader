#include "Parser.hpp"
#include "lexertk.hpp"

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
			variables.insert(std::pair<std::string, std::string>(
				generator[i - 1].value,
				generator[i + 1].value
			));
		}
		else if (t.value == "variables") {
			for (std::pair<std::string, std::any> variable : variables) {
				std::cout << variable.first << " = " << std::any_cast<std::string>(variable.second) << std::endl;
			}
		}
	}
}
