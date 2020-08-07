#ifndef SOVIET_DUMPNODE_HPP
#define SOVIET_DUMPNODE_HPP

#include "nodes/nodes.hpp"
#include <memory>
#include <string>
#include <iostream>
#include "node_cast.hpp"

namespace parser {
    static std::string times(const std::string& str, unsigned int num) {
        std::string result;
        for (unsigned int i = 0; i < num; i++)
            result += str;
        return result;
    }

    static void dump(const std::shared_ptr<Node>& node, unsigned int spacing = 0) {
        switch (node->type) {
            case NodeType::AddOpNode:
            case NodeType::SubOpNode:
            case NodeType::MulOpNode:
            case NodeType::DivOpNode: {
                // all these node types have the same properties
                // so we can cast any of them to another one
                // AddOpNode here can be replaced with SubOpNode, etc.
                const auto& operatorNode = node_cast<AddOpNode>(node);

                std::cout << times(" ", 2 * spacing)
                          << dumpNodeType(node->type) << ":" << std::endl;
                dump(operatorNode->left, spacing + 2);
                dump(operatorNode->right, spacing + 2);
                break;
            }
            case NodeType::NumberNode: {
                const auto& numberNode = node_cast<NumberNode>(node);
                std::cout << times(" ", 2 * spacing)
                    << dumpNodeType(node->type) << ": " << numberNode->value << std::endl;
                break;
            }
        }
    }
}

#endif //SOVIET_DUMPNODE_HPP
