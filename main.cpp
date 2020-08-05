#include "tokenizer/tokenizer.hpp"
#include <iostream>

int main() {
    tokenizer::Tokenizer t;
    const auto tokens = t.tokenize("1 + 2 - 3 * 4 / 5");
    for (const auto& token : tokens) {
        std::cout << "(" << tokenizer::dumpTokenType(token.type) << ") " << token.value << std::endl;
    }

    return 0;
}
