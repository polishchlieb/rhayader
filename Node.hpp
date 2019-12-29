#pragma once
#include "Lexer.hpp"

namespace soviet {
	enum class NodeType {
		 functionCall,
		 primitive,
		 op // operator
	};

	struct Node {
		NodeType type;
		lexer::Token value;
		std::vector<Node> children;
	};
}