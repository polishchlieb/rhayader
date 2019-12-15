#include "Reader.hpp"
#include "Parser.hpp"
#include "lexer.hpp"

#include <time.h>
#include <stdlib.h>
#include "utils.hpp"

int main(int argc, char** argv) {
	auto s1 = soviet::Node{
		"10",
		soviet::Type::number
	};

	auto s2 = soviet::Node{
		"12",
		soviet::Type::number
	};

	std::vector<soviet::Node> operation;
	operation.push_back(s1);
	operation.push_back(s2);

	soviet::Node n{
		"+",
		soviet::op,
		operation
	};

	soviet::parse(n);
	/*std::vector<std::string> arguments;
	for (int i = 0; i < argc; i++) {
		arguments.push_back(static_cast<std::string>(argv[i]));
	}

	if (arguments.size() != 2) {
		std::cerr << "Blyat Vadim" << std::endl;
		exit(0);
	}

	Reader r(arguments[1]); Parser p;
	for (std::string line : r.lines) {
		std::vector<Token> tokens = Lexer::lex(line);
		for (auto token : tokens) {
			std::cout << token.value << ":" << token.type << " ";
		}
		std::cout << std::endl;
		p.parse(tokens);
	}

	r.close();

	return 0;*/
}