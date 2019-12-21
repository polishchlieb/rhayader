#include "Lexer.hpp"
#include <iostream>

int main(int argc, char** argv) {
	Lexer l;
	auto lines = { l.lex("int a = 10"), l.lex("int b = &a"), l.lex("a = 2"), l.lex("print(b)") };
	for (auto tokens : lines) {
		for (auto token : tokens) {
			std::cout << "Line: " << token.line << " Position: " << token.position
				<< " Type: " << token.type << " Value: " << token.value << std::endl;
		}
		std::cout << std::endl;
	}
}