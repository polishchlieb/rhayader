#pragma once
#include "Lexer.hpp"

namespace soviet {
	struct Node {
		lexer::Token value;
		std::vector<Node> children;
	};
}