#include "tokenizer/tokenizer.hpp"
#include <iostream>

int main() {
    const auto tokens = tokenizer::tokenize("3 'hello'");
    for (const auto& token : tokens) {
        std::cout << "(" << tokenizer::dumpTokenType(token.type) << ") " << token.value << std::endl;
    }
    return 0;
}
