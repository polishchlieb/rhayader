#ifndef SOVIET_PARSER_HPP
#define SOVIET_PARSER_HPP

#include "../tokenizer/Token.hpp"
#include <vector>
#include "nodes/nodes.hpp"
#include "TokenIterator.hpp"
#include <memory>
#include <stack>
#include <stdexcept>

#ifdef DEBUG
#include <exception>
#endif

#include "../util/util.hpp"

namespace soviet {
    class Parser {
    public:
        std::shared_ptr<Node> parse(TokenIterator&& iterator) {
            this->iterator = std::move(iterator);
            return this->parseExpression();
        }

    private:
        TokenIterator iterator;

        std::shared_ptr<Node> parseExpression() {
            return this->parseAdditive();
        }

        std::shared_ptr<Node> parsePrimary() {
            auto& token = this->iterator.getNextToken();
            switch (token.type) {
                case TokenType::open_bracket: {
                    const auto operand = this->parseExpression();
                    this->iterator.getNextToken(); // eat )
                    return operand;
                }
                case TokenType::number:
                    return std::make_shared<NumberNode>(
                        std::stof(token.value)
                    );
                case TokenType::name:
                    return std::make_shared<NameNode>(
                        std::move(token.value)
                    );
                default:
                    throw std::runtime_error(
                        "parsePrimary was called with token of type "
                            + dumpTokenType(token.type)
                            + " which is not defined"
                    );
            }
        }

        std::shared_ptr<Node> parseAdditive() {
            auto operand1 = this->parseMultiplicative();
            while (isIn(
                iterator.peekNextToken().type,
                TokenType::add_op, TokenType::sub_op
            )) {
                const auto op = iterator.getNextToken();
                auto operand2 = parseMultiplicative();
                // todo: handle substract operator
                operand1 = std::make_shared<AddOpNode>(
                    std::move(operand1),
                    std::move(operand2)
                );
            }
            return operand1;
        }

        std::shared_ptr<Node> parseMultiplicative() {
            auto operand1 = this->parsePrimary();

            while (isIn(
                iterator.peekNextToken().type,
                TokenType::mul_op, TokenType::div_op
            )) {
                const auto op = iterator.getNextToken();
                auto operand2 = parsePrimary();
                // todo: handle divide operator
                operand1 = std::make_shared<MulOpNode>(
                    std::move(operand1),
                    std::move(operand2)
                );
            }
            return operand1;
        }
    };
}

#endif //SOVIET_PARSER_HPP
