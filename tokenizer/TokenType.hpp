#ifndef SOVIET_TOKENTYPE_HPP
#define SOVIET_TOKENTYPE_HPP

#include <string>
#include <stdexcept>

namespace tokenizer {
    enum class TokenType {
        name,
        number,
        string,
        op
    };

    std::string dumpTokenType(const TokenType type) {
        switch (type) {
            case TokenType::name: return "name";
            case TokenType::number: return "number";
            case TokenType::string: return "string";
            case TokenType::op: return "operator";
        }
    }
}

#endif //SOVIET_TOKENTYPE_HPP
