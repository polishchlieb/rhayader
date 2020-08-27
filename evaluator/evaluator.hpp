#ifndef SOVIET_EVALUATOR_HPP
#define SOVIET_EVALUATOR_HPP

#include <memory>
#include "../parser/nodes/nodes.hpp"
#include "../parser/node_cast.hpp"
#include "values/values.hpp"
#include <unordered_map>

namespace evaluator {
    class Evaluator {
    public:
        std::shared_ptr<Value> evaluate(const std::shared_ptr<parser::Node>& node) {
            switch (node->type) {
                case parser::NodeType::NumberNode:
                    return evaluateNumberNode(node);
                case parser::NodeType::NameNode:
                    return evaluateNameNode(node);
                case parser::NodeType::AddOpNode:
                    return evaluateAddOpNode(node);
                case parser::NodeType::SubOpNode:
                    return evaluateSubOpNode(node);
                case parser::NodeType::MulOpNode:
                    return evaluateMulOpNode(node);
                case parser::NodeType::DivOpNode:
                    return evaluateDivOpNode(node);
                case parser::NodeType::EqualsOpNode:
                    return evaluateEqualsOpNode(node);
                default:
                    throw std::runtime_error("not implemented (yet)");
            }
        }

    private:
        std::unordered_map<std::string, std::shared_ptr<Value>> variables;

        std::shared_ptr<Value> evaluateNumberNode(const std::shared_ptr<parser::Node>& node) {
            const auto& n = parser::node_cast<parser::NumberNode>(node);
            return std::make_shared<NumberValue>(n->value);
        }

        std::shared_ptr<Value> evaluateNameNode(const std::shared_ptr<parser::Node>& node) {
            const auto& n = parser::node_cast<parser::NameNode>(node);
            if (!variables.contains(n->value))
                throw std::runtime_error("unknown name: " + n->value);
            return variables[n->value];
        }

        std::shared_ptr<Value> evaluateAddOpNode(const std::shared_ptr<parser::Node>& node) {
            const auto& n = parser::node_cast<parser::AddOpNode>(node);
            const auto left = value_cast<NumberValue>(evaluate(n->left));
            const auto right = value_cast<NumberValue>(evaluate(n->right));
            return std::make_shared<NumberValue>(left->value + right->value);
        }

        std::shared_ptr<Value> evaluateSubOpNode(const std::shared_ptr<parser::Node>& node) {
            const auto& n = parser::node_cast<parser::SubOpNode>(node);
            const auto left = value_cast<NumberValue>(evaluate(n->left));
            const auto right = value_cast<NumberValue>(evaluate(n->right));
            return std::make_shared<NumberValue>(left->value - right->value);
        }

        std::shared_ptr<Value> evaluateMulOpNode(const std::shared_ptr<parser::Node>& node) {
            const auto& n = parser::node_cast<parser::DivOpNode>(node);
            const auto left = value_cast<NumberValue>(evaluate(n->left));
            const auto right = value_cast<NumberValue>(evaluate(n->right));
            return std::make_shared<NumberValue>(left->value * right->value);
        }

        std::shared_ptr<Value> evaluateDivOpNode(const std::shared_ptr<parser::Node>& node) {
            const auto& n = parser::node_cast<parser::DivOpNode>(node);
            const auto left = value_cast<NumberValue>(evaluate(n->left));
            const auto right = value_cast<NumberValue>(evaluate(n->right));
            return std::make_shared<NumberValue>(left->value / right->value);
        }

        std::shared_ptr<Value> evaluateEqualsOpNode(const std::shared_ptr<parser::Node>& node) {
            const auto& n = parser::node_cast<parser::EqualsOpNode>(node);
            const auto name = parser::node_cast<parser::NameNode>(n->left);
            const auto value = value_cast<NumberValue>(evaluate(n->right));
            variables[std::move(name->value)] = value;
            return value;
        }
    };
}

#endif //SOVIET_EVALUATOR_HPP
