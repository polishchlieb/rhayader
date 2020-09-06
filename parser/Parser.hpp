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
            return std::shared_ptr<Node>();
        }

    private:
        Tokenizer& tokenizer;
    };
}

#endif //SOVIET_PARSER_HPP
