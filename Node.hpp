#pragma once
#include "Lexer.hpp"

namespace soviet {
	enum class NodeType {
		functionCall,
		primitive,
		op, // operator
		assignment,
		none
	};

	// TODO: remove lexer::Token from here probably
	struct Node {
		NodeType type;
		lexer::Token value;
		std::vector<Node> children;
	};
}