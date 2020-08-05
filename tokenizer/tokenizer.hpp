#ifndef SOVIET_TOKENIZER_HPP
#define SOVIET_TOKENIZER_HPP

#include <vector>
#include <string>
#include <iostream>
#include "Token.hpp"
#include "PendingToken.hpp"

namespace tokenizer {
    class Tokenizer {
    public:
        std::vector<Token> tokenize(const std::string& line) {
            for (const char c : line) {
                parseChar(c);
            }

            if (!previous.isEmpty())
                tokens.push_back(previous.toToken());

            return tokens;
        }
    private:
        std::vector<Token> tokens;
        PendingToken previous{PendingTokenType::none, ""};

        void parseChar(const char c) {
            switch (previous.type) {
                case PendingTokenType::none: parseNone(c); break;
                case PendingTokenType::string: parseString(c); break;
                case PendingTokenType::number: parseNumber(c); break;
                case PendingTokenType::name: parseName(c); break;
                case PendingTokenType::add_op: parseAddOp(c); break;
                case PendingTokenType::sub_op: parseSubOp(c); break;
                case PendingTokenType::mul_op: parseMulOp(c); break;
                case PendingTokenType::div_op: parseDivOp(c); break;
                default:
                    throw std::runtime_error("not implemented (yet)");
            }
        }

        static PendingTokenType getType(const char c) {
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

        void parseNone(const char c) {
            const auto type = getType(c);
            switch (getType(c)) {
                case PendingTokenType::number:
                case PendingTokenType::name:
                case PendingTokenType::add_op:
                case PendingTokenType::sub_op:
                case PendingTokenType::div_op:
                case PendingTokenType::mul_op:
                    previous.type = type;
                    previous.value += c;
                    break;
                case PendingTokenType::string:
                case PendingTokenType::unknown:
                    previous.type = type;
                    break;
                case PendingTokenType::none:
                    break;
            }
        }

        void parseString(const char c) {
            if (c == '\'' || c == '"') {
                tokens.push_back(previous.toToken());
                previous.clear();
                return;
            }

            previous.value += c;
        }

        void parseNumber(const char c) {
            const auto type = getType(c);
            if (type == PendingTokenType::number) {
                previous.value += c;
                return;
            }

            tokens.push_back(previous.toToken());
            previous.clear();
            parseChar(c);
        }

        void parseName(const char c) {
            const auto type = getType(c);
            if (type == PendingTokenType::name || type == PendingTokenType::number) {
                previous.value += c;
                return;
            }

            tokens.push_back(previous.toToken());
            previous.clear();
            parseChar(c);
        }

        void parseAddOp(const char c) {
            tokens.push_back(previous.toToken());
            previous.clear();
            parseChar(c);
        }

        void parseSubOp(const char c) {
            tokens.push_back(previous.toToken());
            previous.clear();
            parseChar(c);
        }

        void parseMulOp(const char c) {
            tokens.push_back(previous.toToken());
            previous.clear();
            parseChar(c);
        }

        void parseDivOp(const char c) {
            tokens.push_back(previous.toToken());
            previous.clear();
            parseChar(c);
        }
    };
}

#endif //SOVIET_TOKENIZER_HPP
