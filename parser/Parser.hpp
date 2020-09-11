#ifndef SOVIET_PARSER_HPP
#define SOVIET_PARSER_HPP

#include "../tokenizer/Token.hpp"
#include <vector>
#include "nodes/nodes.hpp"
#include <memory>
#include <stack>
#include <stdexcept>

namespace soviet {
    class Parser {
    public:
        explicit Parser(Tokenizer& tokenizer) : tokenizer(tokenizer) {}

        std::shared_ptr<Node> parse() {
            switch (tokenizer.getCurrentToken().type) {
                case TokenType::number:
                    return parseNumber();
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
    };
}

#endif //SOVIET_PARSER_HPP
