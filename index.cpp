#include "Reader.hpp"
#include "Parser.hpp"
#include "lexer.hpp"

#include <time.h>

int main(int argc, char** argv) {
	std::vector<std::string> arguments;
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

	return 0;
}