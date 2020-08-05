#ifndef SOVIET_TOKENTYPE_HPP
#define SOVIET_TOKENTYPE_HPP

#include <string>
#include <stdexcept>

namespace tokenizer {
    enum class TokenType {
        name,
        number,
        string,
        add_op,
        sub_op,
        div_op,
        mul_op
    };

    std::string dumpTokenType(const TokenType type) {
        switch (type) {
            case TokenType::name: return "name";
            case TokenType::number: return "number";
            case TokenType::string: return "string";
            case TokenType::add_op: return "add_operator";
            case TokenType::sub_op: return "substract_operator";
            case TokenType::div_op: return "divide_operator";
            case TokenType::mul_op: return "multiply_operator";
        }
    }
}

#endif //SOVIET_TOKENTYPE_HPP
