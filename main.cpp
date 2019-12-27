#include <iostream>

#include "Lexer.hpp"
#include "Parser.hpp"
#include "Executor.hpp"
#include "file_reader.hpp"
#include "lexerhelper.hpp"

#ifndef NUB_DEBUG
// #define NUB_DEBUG
#endif

int main(int argc, const char** argv) {
#ifndef NUB_DEBUG
	if (argc != 2) {
		print("Error: ", 12);
		print("too little arguments\n");
		print("Hint: ", 11);
		print("use soviet filename instead\n");
		return 1;
	}
#else
	argv[1] = "x64/Release/test.soviet";
#endif

	soviet::lexer::Lexer lexer;
	soviet::parser::Parser parser;
	soviet::executor::Executor executor;
	
	std::vector<std::string> lines;
	soviet::readLines(lines, argv[1]);

	unsigned int lineNum = 0;
	for (const auto& line : lines) {
		lineNum++;
		auto tokens = lexer.lex(line);
		soviet::Node tree = parser.parse(tokens);
		executor.execute(tree, lineNum);
	}
}