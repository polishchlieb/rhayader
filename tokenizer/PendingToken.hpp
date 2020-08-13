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

        PendingToken(const PendingToken& other) {
            type = other.type;
            value = other.value;

            std::cout << "copied PendingToken" << std::endl;
        }

        PendingToken(PendingToken&& other) {
            type = other.type;
            other.type = PendingTokenType::none;
            value = std::move(other.value);
            
            std::cout << "moved PendingToken" << std::endl;
        }

        Token toToken() {
            return Token{
                applyPendingTokenType(this->type),
                std::move(this->value)
            };
        }

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
