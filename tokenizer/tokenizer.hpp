#ifndef SOVIET_TOKENIZER_HPP
#define SOVIET_TOKENIZER_HPP

#include <vector>
#include <string>
#include <iostream>
#include "Token.hpp"
#include "PendingToken.hpp"

namespace tokenizer {
    PendingTokenType getType(const char c) {
        if (isdigit(c)) return PendingTokenType::number;
        if (isalpha(c)) return PendingTokenType::name;
        if (c == ' ') return PendingTokenType::none;
        if (c == '\'' || c == '"') return PendingTokenType::string;
        if (c == '+') return PendingTokenType::add_op;
        if (c == '-') return PendingTokenType::sub_op;
        if (c == '*') return PendingTokenType::mul_op;
        if (c == '/') return PendingTokenType::div_op;
        return PendingTokenType::unknown;
    }

    std::vector<Token> tokenize(const std::string& line) {
        std::vector<Token> tokens;
        PendingToken current{PendingTokenType::none, ""};

        for (const char c : line) {
        iteration:
            if (current.type == PendingTokenType::none) {
                const auto type = getType(c);
                switch (getType(c)) {
                    case PendingTokenType::number:
                    case PendingTokenType::name:
                    case PendingTokenType::add_op:
                    case PendingTokenType::sub_op:
                    case PendingTokenType::div_op:
                    case PendingTokenType::mul_op:
                        current.type = type;
                        current.value += c;
                        break;
                    case PendingTokenType::string:
                    case PendingTokenType::unknown:
                        current.type = type;
                        break;
                    case PendingTokenType::none:
                        break;
                }
                continue;
            }

            if (current.type == PendingTokenType::string) {
                if (c == '\'' || c == '"') {
                    tokens.push_back(current.toToken());
                    current.clear();
                    continue;
                }

                current.value += c;
                continue;
            }

            if (current.type == PendingTokenType::number) {
                const auto type = getType(c);
                if (type == PendingTokenType::number) {
                    current.value += c;
                    continue;
                }

                tokens.push_back(current.toToken());
                current.clear();
                goto iteration;
            }

            if (current.type == PendingTokenType::name) {
                const auto type = getType(c);
                if (type == PendingTokenType::name || type == PendingTokenType::number) {
                    current.value += c;
                    continue;
                }

                tokens.push_back(current.toToken());
                current.clear();
                goto iteration;
            }

            if (current.type == PendingTokenType::add_op) {
                tokens.push_back(current.toToken());
                current.clear();
                goto iteration;
            }
        }

        if (!current.isEmpty())
            tokens.push_back(current.toToken());

        return tokens;
    }
}

#endif //SOVIET_TOKENIZER_HPP
