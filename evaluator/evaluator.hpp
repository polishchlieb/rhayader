#ifndef SOVIET_EVALUATOR_HPP
#define SOVIET_EVALUATOR_HPP

#include <memory>
#include "../parser/nodes/nodes.hpp"
#include "../parser/node_cast.hpp"

namespace evaluator {
    float evaluate(const std::shared_ptr<parser::Node>& node) {
        switch (node->type) {
            case parser::NodeType::NumberNode: {
                const auto& n = parser::node_cast<parser::NumberNode>(node);
                return n->value;
            }
            case parser::NodeType::AddOpNode: {
                const auto& n = parser::node_cast<parser::AddOpNode>(node);
                return evaluate(n->left) + evaluate(n->right);
            }
            case parser::NodeType::SubOpNode: {
                const auto& n = parser::node_cast<parser::SubOpNode>(node);
                return evaluate(n->left) - evaluate(n->right);
            }
            case parser::NodeType::MulOpNode: {
                const auto& n = parser::node_cast<parser::MulOpNode>(node);
                return evaluate(n->left) * evaluate(n->right);
            }
            case parser::NodeType::DivOpNode: {
                const auto& n = parser::node_cast<parser::DivOpNode>(node);
                return evaluate(n->left) / evaluate(n->right);
            }
            default:
                throw std::runtime_error("not implemented (yet)");
        }
    }
}

#endif //SOVIET_EVALUATOR_HPP
