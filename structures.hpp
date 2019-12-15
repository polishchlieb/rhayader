#pragma once
#include <vector>
#include <optional>

namespace soviet {
	enum Type {
		number,
		op, // operator
		string
	};

	struct PrimitiveNode {
		const char* value;
		Type type;
	};

	struct Node : PrimitiveNode {
		std::vector<Node> children;
	};
}