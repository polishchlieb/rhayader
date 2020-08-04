#ifndef SOVIET_PENDINGTOKEN_HPP
#define SOVIET_PENDINGTOKEN_HPP

#include <string>
#include "PendingTokenType.hpp"
#include "Token.hpp"

namespace tokenizer {
    struct PendingToken {
        PendingTokenType type;
        std::string value;

        Token toToken() {
            return Token{
                applyPendingTokenType(this->type),
                this->value
            };
        }

        void clear() {
            this->type = PendingTokenType::none;
            this->value = "";
        }
    };
}

#endif //SOVIET_PENDINGTOKEN_HPP
