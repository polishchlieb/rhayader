#pragma once
#include "Node.hpp"
#include <iostream>

static inline std::string times(const std::string& str, unsigned int num) {
	std::string result;
	for (unsigned int i = 0; i < num; ++i) {
		result += str;
	}
	return result;
}

static inline void printTree(const soviet::Node& node, unsigned int spacing = 0) {
	const std::string type = node.type == soviet::NodeType::primitive ? "primitive" : "funcCall";
	std::cout
		<< times(" ", 2 * spacing)
		<< node.value.value
		<< ": " << type << ", " << node.children.size()
		<< std::endl;

	for (const auto& childNode : node.children) {
		printTree(childNode, spacing + 1);
	}
}