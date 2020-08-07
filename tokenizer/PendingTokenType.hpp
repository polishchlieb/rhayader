#ifndef SOVIET_PENDINGTOKENTYPE_HPP
#define SOVIET_PENDINGTOKENTYPE_HPP

#include "TokenType.hpp"
#include <stdexcept>
#include <string>

namespace tokenizer {
    enum class PendingTokenType {
        none,
        unknown,
        name,
        number,
        string,
        add_op,
        sub_op,
        div_op,
        mul_op,
        open_bracket,
        close_bracket
    };

    std::string dumpPendingTokenType(const PendingTokenType type) {
        switch (type) {
            case PendingTokenType::none: return "none";
            case PendingTokenType::unknown: return "unknown";
            case PendingTokenType::name: return "name";
            case PendingTokenType::number: return "number";
            case PendingTokenType::string: return "string";
            case PendingTokenType::add_op: return "add_operator";
            case PendingTokenType::sub_op: return "substract_operator";
            case PendingTokenType::div_op: return "divide_operator";
            case PendingTokenType::mul_op: return "multiply_operator";
            case PendingTokenType::open_bracket: return "open_bracket";
            case PendingTokenType::close_bracket: return "close_bracket";
        }
    }

    TokenType applyPendingTokenType(const PendingTokenType type) {
        switch (type) {
            case PendingTokenType::name: return TokenType::name;
            case PendingTokenType::number: return TokenType::number;
            case PendingTokenType::string: return TokenType::string;
            case PendingTokenType::add_op: return TokenType::add_op;
            case PendingTokenType::sub_op: return TokenType::sub_op;
            case PendingTokenType::div_op: return TokenType::div_op;
            case PendingTokenType::mul_op: return TokenType::mul_op;
            case PendingTokenType::open_bracket: return TokenType::open_bracket;
            case PendingTokenType::close_bracket: return TokenType::close_bracket;
            default:
                throw std::runtime_error("Couldn't convert pending token type " + dumpPendingTokenType(type) + " to token type");
        }
    }
}

#endif //SOVIET_PENDINGTOKENTYPE_HPP
