#include "tokenizer/Tokenizer.hpp"
#include "parser/Parser.hpp"
#include "evaluator/evaluator.hpp"
#include "evaluator/dumpValue.hpp"

#ifdef DEBUG
#include "tokenizer/dumpTokens.hpp"
#include "parser/dumpNode.hpp"
#endif

int main() {
    soviet::Tokenizer t;
    soviet::Parser p;
    soviet::Evaluator e;

    while (true) {
        std::string input;

#ifdef DEBUG
        std::cout << "Input: ";
        std::getline(std::cin, input);
        std::cout << "---------------------" << std::endl;
#else
        std::cout << "> ";
        std::getline(std::cin, input);
#endif

        if (input == "exit") {
            break;
        }

#ifdef DEBUG
        auto tokens = t.tokenize(input);
        std::cout << "Tokenizer output:" << std::endl;
        soviet::dump(tokens);
        std::cout << "---------------------" << std::endl;

        auto rootNode = p.parse(tokens);
        std::cout << "Parser output:" << std::endl;
        soviet::dump(rootNode);
        std::cout << "---------------------" << std::endl;

        std::cout << "Evaluator output:" << std::endl;
        const auto value = e.evaluate(rootNode);
        std::cout << soviet::dumpValue(value) << std::endl << std::endl;
#else
        auto tokens = t.tokenize(input);
        const auto value = e.evaluate(
            p.parse(tokens)
        );

        std::cout << soviet::dumpValue(value) << std::endl;
#endif
    }
}

