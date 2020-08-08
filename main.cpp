#include "tokenizer/Tokenizer.hpp"
#include "parser/Parser.hpp"
#include "evaluator/evaluator.hpp"

int main() {
    tokenizer::Tokenizer t;
    const auto tokens = t.tokenize("(2 + 2) * 2");

    parser::Parser p;
    const auto rootNode = p.parse(tokens);

    float value = evaluator::evaluate(rootNode);
    std::cout << value << std::endl;
    return 0;
}