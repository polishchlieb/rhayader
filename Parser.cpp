#include "Parser.hpp"

Parser::~Parser() {
	std::cout << "Parser made kaput, bye" << std::endl;
}

void Parser::parse(const std::vector<Token> tokens) {
	int i = 0;
	for (Token t : tokens) {}
}
