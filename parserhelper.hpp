#pragma once
#include "Node.hpp"
#include <iostream>

namespace soviet {
	namespace parser {
		namespace helper {
			static inline std::string times(const std::string& str, unsigned int num) {
				std::string result;
				for (unsigned int i = 0; i < num; ++i) {
					result += str;
				}
				return result;
			}

			static inline std::string toString(NodeType type) {
				switch (type) {
					case NodeType::functionCall: return "functionCall";
					case NodeType::op: return "operator";
					case NodeType::primitive: return "primitive";
					case NodeType::assignment: return "assignment";
					case NodeType::none: return "none";
				}
				return "none";
			}

			static inline void printTree(const soviet::Node& node, unsigned int spacing = 0) {
				std::cout
					<< times(" ", 2 * spacing)
					<< node.value.value
					<< ": " << toString(node.type) << ", " << node.children.size()
					<< std::endl;

				for (const auto& childNode : node.children) {
					printTree(childNode, spacing + 1);
				}
			}
		}
	}
}