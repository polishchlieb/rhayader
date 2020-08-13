#ifndef SOVIET_TOKEN_HPP
#define SOVIET_TOKEN_HPP

#include "TokenType.hpp"
#include <string>
//#include <iostream>

namespace tokenizer {
    struct Token {
        TokenType type;
        std::string value;
        
        Token(TokenType type, std::string&& value)
            : type(type), value(std::move(value)) {
            std::cout << "created Token" << std::endl;
        }

        ~Token() {
             std::cout << "destroyed Token" << std::endl;
        }

        Token(const Token& other) {
            type = other.type;
            value = other.value;

            std::cout << "copied" << std::endl;
        }

        Token(Token&& other) {
            type = other.type;
            other.type = TokenType::undefined;

            value = std::move(other.value);

            std::cout << "moved" << std::endl;
        }
    };
}

#endif //SOVIET_TOKEN_HPP
