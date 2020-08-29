#ifndef SOVIET_PARSER_HPP
#define SOVIET_PARSER_HPP

#include "../tokenizer/Token.hpp"
#include <vector>
#include "nodes/nodes.hpp"
#include <memory>
#include <stack>
#include <stdexcept>

//namespace parser {
//    class Parser {
//    public:
//        std::shared_ptr<Node> parse(std::vector<tokenizer::Token>& tokens) {
////            return parseInfixExpression(tokens);
//        }
//
//    private:
//        std::stack<tokenizer::Token> operatorStack;
//        std::stack<std::shared_ptr<Node>> expressionStack;
//
//        std::shared_ptr<Node> parseInfixExpression(std::vector<tokenizer::Token>& tokens) {
//            for (auto& token : tokens) {
//                if (token.type == tokenizer::TokenType::open_bracket) {
//                    operatorStack.push(std::move(token));
//                } else if (token.type == tokenizer::TokenType::number) {
//                    const float value = std::stof(token.value);
//                    expressionStack.emplace(std::make_shared<NumberNode>(value));
//                } else if (token.type == tokenizer::TokenType::name) {
//                    expressionStack.emplace(std::make_shared<NameNode>(std::move(token.value)));
//                } else if (isOperator(token)) {
//                    while (!operatorStack.empty() && getOperatorPrecedence(operatorStack.top()) >= getOperatorPrecedence(token)) {
//                        parseInfixOperator();
//                    }
//                    operatorStack.push(std::move(token));
//                } else if (token.type == tokenizer::TokenType::close_bracket) {
//                    while (operatorStack.top().type != tokenizer::TokenType::open_bracket) {
//                        parseInfixOperator();
//                    }
//                    operatorStack.pop();
//                }
//            }
//
//            while (!operatorStack.empty()) {
//                parseInfixOperator();
//            }
//
//            auto value = std::move(expressionStack.top());
//            expressionStack.pop();
//
//            return std::move(value);
//        }
//
//        void parseInfixOperator() {
//            const auto op = std::move(operatorStack.top());
//            operatorStack.pop();
//
//            auto e2 = std::move(expressionStack.top());
//            expressionStack.pop();
//
//            auto e1 = std::move(expressionStack.top());
//            expressionStack.pop();
//
//            switch (op.type) {
//                case tokenizer::TokenType::add_op:
//                    createOperatorExpression<AddOpNode>(std::move(e1), std::move(e2));
//                    break;
//                case tokenizer::TokenType::sub_op:
//                    createOperatorExpression<SubOpNode>(std::move(e1), std::move(e2));
//                    break;
//                case tokenizer::TokenType::mul_op:
//                    createOperatorExpression<MulOpNode>(std::move(e1), std::move(e2));
//                    break;
//                case tokenizer::TokenType::div_op:
//                    createOperatorExpression<DivOpNode>(std::move(e1), std::move(e2));
//                    break;
//                case tokenizer::TokenType::equals_op:
//                    createOperatorExpression<EqualsOpNode>(std::move(e1), std::move(e2));
//                    break;
//                case tokenizer::TokenType::double_equals_op:
//                    createOperatorExpression<DoubleEqualsOpNode>(std::move(e1), std::move(e2));
//                    break;
//                default: break;
//            }
//        }
//
//        template<typename T, typename std::enable_if<std::is_base_of<Node, T>::value>::type* = nullptr>
//        void createOperatorExpression(std::shared_ptr<Node>&& e1, std::shared_ptr<Node>&& e2) {
//            expressionStack.push(
//                std::make_shared<T>(
//                    std::move(e1),
//                    std::move(e2)
//                )
//            );
//        }
//
//        static inline bool isOperator(const tokenizer::Token& token) {
//            using tokenizer::TokenType;
//            return token.type == TokenType::add_op || token.type == TokenType::sub_op
//                || token.type == TokenType::mul_op || token.type == TokenType::div_op
//                || token.type == TokenType::equals_op || token.type == TokenType::double_equals_op;
//        }
//
//        static unsigned int getOperatorPrecedence(const tokenizer::Token& token) {
//            switch (token.type) {
//                // numbers here really don't matter, precedence for multiply
//                // operator just has to be greater than precedence for add operator, etc.
//                case tokenizer::TokenType::add_op:
//                case tokenizer::TokenType::sub_op:
//                    return 2;
//                case tokenizer::TokenType::mul_op:
//                case tokenizer::TokenType::div_op:
//                    return 3;
//                case tokenizer::TokenType::equals_op:
//                case tokenizer::TokenType::double_equals_op:
//                    return 1;
//                case tokenizer::TokenType::open_bracket:
//                    // this has to be the lowest
//                    return 0;
//                default:
//                    throw std::runtime_error(tokenizer::dumpTokenType(token.type) + " is not an operator");
//            }
//        }
//    };
//}

namespace parser {
    class Parser {
    public:
        Parser(std::vector<tokenizer::Token>&& tokens) {
            this->tokens = std::move(tokens);
        }

        std::shared_ptr<Node> parse() {
            return std::shared_ptr<Node>();
        }

    private:
        std::vector<tokenizer::Token> tokens;
    };
}

#endif //SOVIET_PARSER_HPP
