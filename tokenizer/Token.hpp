#ifndef SOVIET_TOKEN_HPP
#define SOVIET_TOKEN_HPP

#include "TokenType.hpp"
#include <string>

namespace tokenizer {
    struct Token {
        TokenType type;
        std::string value;
        
        Token(TokenType type, std::string&& value)
            : type(type), value(std::move(value)) {}
    };
}

#endif //SOVIET_TOKEN_HPP
