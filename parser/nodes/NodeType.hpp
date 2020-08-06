#ifndef SOVIET_NODETYPE_HPP
#define SOVIET_NODETYPE_HPP

#include <string>

namespace parser {
    enum class NodeType {
        NumberNode,
        AddOpNode
    };

    std::string dumpNodeType(const NodeType type) {
        switch (type) {
            case NodeType::NumberNode: return "number_node";
            case NodeType::AddOpNode: return "add_operator_node";
        }
    }
}

#endif //SOVIET_NODETYPE_HPP
