#include <iostream>
#include <chrono>

#include "Lexer.hpp"

// Windows 10 Pro 1903
// Intel Core i5-7500 3.40Ghz
// 16 GB RAM
// Result: about 0.5s

inline void testLexerSpeed() {
	soviet::lexer::Lexer lexer;

	const std::string line = "print(\"Hello world\")";

	auto start = std::chrono::system_clock::now();
	for (unsigned int i = 0; i < 1000000; i++) {
		auto tokens = lexer.lex(line);
	}
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed = end - start;
	std::cout << "Time elapsed: " << elapsed.count() << std::endl;
}