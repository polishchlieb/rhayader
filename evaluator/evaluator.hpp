#ifndef SOVIET_EVALUATOR_HPP
#define SOVIET_EVALUATOR_HPP

#include <memory>
#include "../parser/nodes/nodes.hpp"
#include "../parser/node_cast.hpp"
#include "values/values.hpp"

namespace evaluator {
    std::shared_ptr<Value> evaluate(const std::shared_ptr<parser::Node>& node) {
        switch (node->type) {
            case parser::NodeType::NumberNode: {
                const auto& n = parser::node_cast<parser::NumberNode>(node);
                return std::make_shared<NumberValue>(n->value);
            }
            case parser::NodeType::AddOpNode: {
                const auto& n = parser::node_cast<parser::AddOpNode>(node);
                const auto left = value_cast<NumberValue>(evaluate(n->left));
                const auto right = value_cast<NumberValue>(evaluate(n->right));
                return std::make_shared<NumberValue>(left->value + right->value);
            }
            case parser::NodeType::SubOpNode: {
                const auto& n = parser::node_cast<parser::SubOpNode>(node);
                const auto left = value_cast<NumberValue>(evaluate(n->left));
                const auto right = value_cast<NumberValue>(evaluate(n->right));
                return std::make_shared<NumberValue>(left->value - right->value);
            }
            case parser::NodeType::MulOpNode: {
                const auto& n = parser::node_cast<parser::MulOpNode>(node);
                const auto left = value_cast<NumberValue>(evaluate(n->left));
                const auto right = value_cast<NumberValue>(evaluate(n->right));
                return std::make_shared<NumberValue>(left->value * right->value);
            }
            case parser::NodeType::DivOpNode: {
                const auto& n = parser::node_cast<parser::DivOpNode>(node);
                const auto left = value_cast<NumberValue>(evaluate(n->left));
                const auto right = value_cast<NumberValue>(evaluate(n->right));
                return std::make_shared<NumberValue>(left->value / right->value);
            }
            default:
                throw std::runtime_error("not implemented (yet)");
        }
    }
}

#endif //SOVIET_EVALUATOR_HPP
