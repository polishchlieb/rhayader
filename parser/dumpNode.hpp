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
        if (node->type == NodeType::AddOpNode) {
            const auto& n = node_cast<AddOpNode>(node);

            std::cout << times(" ", 2 * spacing)
                << "add operator +:" << std::endl;
            dump(n->left, spacing + 2);
            dump(n->right,  spacing + 2);
        } else if (node->type == NodeType::NumberNode) {
            const auto& n = node_cast<NumberNode>(node);
            std::cout << times(" ",  2 * spacing) << "number: " << n->value << std::endl;
        }
    }
}

#endif //SOVIET_DUMPNODE_HPP
