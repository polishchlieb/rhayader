#pragma once
#include <iostream>
#include <chrono>

#include "Lexer.hpp"
#include "Parser.hpp"

// Windows 10 Pro 1903
// Intel Core i5-7500 3.40Ghz
// 16 GB RAM
// Result: 0.152s

inline void testParserSpeed() {
	soviet::lexer::Lexer lexer;
	soviet::parser::Parser parser;

	const std::string line = "print(\"Hello world\")";

	auto tokens = lexer.lex(line);

	auto start = std::chrono::system_clock::now();
	for (unsigned int i = 0; i < 1000000; i++) {
		auto tok = tokens;
		auto tree = parser.parse(tok);
	}
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed = end - start;
	std::cout << "Time elapsed: " << elapsed.count() << std::endl;
}