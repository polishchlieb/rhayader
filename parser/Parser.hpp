#ifndef SOVIET_PARSER_HPP
#define SOVIET_PARSER_HPP

#include "../tokenizer/Token.hpp"
#include <vector>
#include "nodes/nodes.hpp"
#include <memory>
#include <stack>

namespace parser {
    class Parser {
    public:
        std::shared_ptr<Node> parse(const std::vector<tokenizer::Token>& tokens) {
            for (const auto& token : tokens) {
                if (token.type == tokenizer::TokenType::add_op) {
                    while (!operatorStack.empty()) {
                        const auto op = std::move(operatorStack.top());
                        operatorStack.pop();

                        auto e2 = std::move(expressionStack.top());
                        expressionStack.pop();

                        auto e1 = std::move(expressionStack.top());
                        expressionStack.pop();

                        expressionStack.push(
                            std::make_shared<AddOpNode>(
                                std::move(e1),
                                std::move(e2)
                            )
                        );
                    }

                    operatorStack.push(token);
                } else if (token.type == tokenizer::TokenType::number) {
                    const float value = std::stof(token.value);
                    expressionStack.push(std::make_shared<NumberNode>(value));
                }
            }

            while (!operatorStack.empty()) {
                const auto op = std::move(operatorStack.top());
                operatorStack.pop();

                auto e2 = std::move(expressionStack.top());
                expressionStack.pop();

                auto e1 = std::move(expressionStack.top());
                expressionStack.pop();

                expressionStack.push(
                    std::make_shared<AddOpNode>(
                        std::move(e1),
                        std::move(e2)
                    )
                );
            }

            auto value = std::move(expressionStack.top());
            expressionStack.pop();
            return value;
        }

    private:
        std::stack<tokenizer::Token> operatorStack;
        std::stack<std::shared_ptr<Node>> expressionStack;
    };
}

#endif //SOVIET_PARSER_HPP
