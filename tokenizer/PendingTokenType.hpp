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
        op
    };

    std::string dumpPendingTokenType(const PendingTokenType type) {
        switch (type) {
            case PendingTokenType::none: return "none";
            case PendingTokenType::unknown: return "unknown";
            case PendingTokenType::name: return "name";
            case PendingTokenType::number: return "number";
            case PendingTokenType::string: return "string";
            case PendingTokenType::op: return "operator";
        }
    }

    TokenType applyPendingTokenType(const PendingTokenType type) {
        switch (type) {
            case PendingTokenType::name: return TokenType::name;
            case PendingTokenType::number: return TokenType::number;
            case PendingTokenType::string: return TokenType::string;
            case PendingTokenType::op: return TokenType::op;
            default:
                throw std::runtime_error("Couldn't convert pending token type " + dumpPendingTokenType(type) + " to token type");
        }
    }
}

#endif //SOVIET_PENDINGTOKENTYPE_HPP
