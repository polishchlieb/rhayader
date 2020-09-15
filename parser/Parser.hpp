#ifndef SOVIET_PARSER_HPP
#define SOVIET_PARSER_HPP

#include "../tokenizer/Token.hpp"
#include <vector>
#include "nodes/nodes.hpp"
#include "../tokenizer/Tokenizer.hpp"
#include <memory>
#include <stack>
#include <stdexcept>

#ifdef DEBUG
#include <exception>
#endif

namespace soviet {
    class Parser {
    public:
        explicit Parser(Tokenizer& tokenizer) : tokenizer(tokenizer) {}

        std::shared_ptr<Node> parse() {
            switch (tokenizer.getCurrentToken().type) {
                case TokenType::number:
                    return parseNumber();
                default:
                    std::cout << "a.. ja mam to w dupie" << std::endl;
                    return nullptr; // segfault eppek
            }
        }

        std::shared_ptr<Node> parseNumber() {
             const auto result = std::make_shared<NumberNode>(
                 std::stof(tokenizer.getCurrentToken().value)
             );
             tokenizer.getNextToken();
             return result;
        }

    private:
        Tokenizer& tokenizer;
        std::shared_ptr<Node> rootNode;

        static int getOperatorPrecedence(Token& token) {
            switch (token.type) {
                case TokenType::add_op:
                case TokenType::sub_op:
                    return 1;
                case TokenType::mul_op:
                case TokenType::div_op:
                    return 2;
                default:
                #ifdef DEBUG
                    throw std::runtime_error(
                        "Couldn't get precedence of token of type "
                        + dumpTokenType(token.type)
                    );
                #endif
                    return -1;
            }
        }
    };
}

#endif //SOVIET_PARSER_HPP
