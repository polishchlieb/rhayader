#include "tokenizer/tokenizer.hpp"
#include "parser/Parser.hpp"
#include "parser/dumpNode.hpp"

int main() {
    tokenizer::Tokenizer t;
    const auto tokens = t.tokenize("(21 + 56) / (12 + 34)");

    parser::Parser p;
    const auto rootNode = p.parse(tokens);

    parser::dump(rootNode);

    return 0;
}
