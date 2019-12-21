#pragma once
#include <vector>
#include <any>
#include <string>
#include <iostream>
#include <algorithm>
#include <any>
#include "Token.hpp"
#include "structures.hpp"
#include "util.hpp"

namespace soviet {
	struct Node {
		Token token;
		std::vector<Node> children;
	};

	class Parser {
		Node parse(std::vector<Token>&);
	};
}