#include <iostream>

#include "Lexer.hpp"
#include "Parser.hpp"
#include "Executor.hpp"
#include "file_reader.hpp"
#include "parserhelper.hpp"
#include "lexerhelper.hpp"
#include "argshelper.hpp"

// #define NUB_DEBUG

int main(int argc, const char** argv) {
	soviet::ArgumentData data;
#ifndef NUB_DEBUG
	data = soviet::parseArgs(argc, argv);
#else
	auto defaultFileName = "x64/Release/test.soviet";
	data = soviet::parseArgs(1, &defaultFileName);
#endif

	soviet::lexer::Lexer lexer;
	soviet::parser::Parser parser;
	auto executor = new soviet::executor::Executor;

	std::vector<std::string> lines;
	soviet::readLines(lines, argv[1]);

	for (unsigned int i = 0; i < lines.size(); ++i) {
		auto tokens = lexer.lex(lines[i]);
		if (data.flags.has(soviet::SOVIET_DEBUG_PRINT))
			soviet::lexer::helper::dump(tokens);

		auto tree = parser.parse(tokens);
		if (data.flags.has(soviet::SOVIET_DEBUG_PRINT))
			soviet::parser::helper::printTree(tree);

		executor->execute(tree, i);
	}

	delete executor;
	return 0;
}