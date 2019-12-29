#include <iostream>

#include "Lexer.hpp"
#include "Parser.hpp"
#include "Executor.hpp"
#include "file_reader.hpp"
#include "lexerhelper.hpp"

// #define NUB_DEBUG

int main(int argc, const char** argv) {
#ifndef NUB_DEBUG
	if (argc != 2)
		error("Error", "to little arguments");
#else
	argv[1] = "x64/Release/test.soviet";
#endif

	soviet::lexer::Lexer lexer;
	soviet::parser::Parser parser;
	auto executor = new soviet::executor::Executor;
	
	std::vector<std::string> lines;
	soviet::readLines(lines, argv[1]);

	for (unsigned int i = 0; i < lines.size(); ++i) {
		auto tokens = lexer.lex(lines[i]);
		soviet::lexer::helper::dump(tokens);
		auto tree = parser.parse(tokens);
		printTree(tree);
		// executor->execute(tree, i);
	}

	delete executor;
	return 0;
}