#ifndef SOVIET_PENDINGTOKEN_HPP
#define SOVIET_PENDINGTOKEN_HPP

#include <string>
#include <vector>
#include "PendingTokenType.hpp"
#include "Token.hpp"

namespace tokenizer {
    struct PendingToken {
        PendingTokenType type;
        std::string value;

        PendingToken(PendingTokenType type, std::string&& value)
            : type(type), value(std::move(value)) {}       

        PendingToken(const PendingToken& other)
            : type(other.type), value(other.value) {}

        PendingToken(PendingToken&& other)
            : type(other.type), value(std::move(other.value)) {
            other.type = PendingTokenType::none;
        }

        /* Token toToken() {
            return Token{
                applyPendingTokenType(this->type),
                std::move(this->value)
            };
        } */

        static void pushToken(std::vector<Token>& tokens, PendingToken& token) {
            tokens.emplace_back(
                applyPendingTokenType(token.type),
                std::move(token.value)
            );
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
