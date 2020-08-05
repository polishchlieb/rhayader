#include "tokenizer/tokenizer.hpp"
#include <iostream>

int main() {
    const auto tokens = tokenizer::tokenize("2 + 2");
    for (const auto& token : tokens) {
        std::cout << "(" << tokenizer::dumpTokenType(token.type) << ") " << token.value << std::endl;
    }
    return 0;
}
