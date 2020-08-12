#ifndef SOVIET_PENDINGTOKEN_HPP
#define SOVIET_PENDINGTOKEN_HPP

#include <string>
#include "PendingTokenType.hpp"
#include "Token.hpp"

namespace tokenizer {
    struct PendingToken {
        PendingTokenType type;
        std::string value;

        PendingToken(PendingTokenType type, std::string&& value)
            : type(type), value(std::move(value)) {}       

        Token toToken() {
            return Token{
                applyPendingTokenType(this->type),
                std::move(this->value)
            };
        }

        void clear() {
            this->type = PendingTokenType::none;
            this->value = "";
        }

        bool isEmpty() const {
            return this->type == PendingTokenType::none;
        }
    };
}

#endif //SOVIET_PENDINGTOKEN_HPP
