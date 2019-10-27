#include "test.hpp"
#include "lexer.hpp"

void test() {
	auto tokens = Lexer::lex("hello world hello world");

	for (auto token : tokens) {
		std::cout << token << std::endl;
	}
}