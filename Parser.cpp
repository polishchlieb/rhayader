#include "Parser.hpp"

namespace soviet {
	namespace parser {
		Node Parser::parse(std::vector<soviet::lexer::Token>& tokens) {
			if (tokens[0].value == "print") {
				std::vector<Node> children;
				children.push_back(Node{ tokens[2] });
				return Node{ tokens[0], children };
			}

			return Node();
		}
	}
}