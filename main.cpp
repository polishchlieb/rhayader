#include <iostream>

#include "Lexer.hpp"
#include "Parser.hpp"
#include "Executor.hpp"
#include "file_reader.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		print("Error: ", 12);
		print("too little arguments\n");
		print("Hint: ", 11);
		print("use soviet filename instead\n");
		return 1;
	}

	soviet::lexer::Lexer lexer;
	soviet::parser::Parser parser;
	soviet::executor::Executor executor;
	
	std::vector<std::string> lines;
	soviet::readLines(lines, argv[1]);

	unsigned int lineNum = 0;
	for (const auto& line : lines) {
		lineNum++;
		auto tokens = lexer.lex(line);
		auto tree = parser.parse(tokens);
		executor.execute(tree, lineNum);
	}
}