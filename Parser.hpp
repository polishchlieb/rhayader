#pragma once
#include "Node.hpp"
#include "Token.hpp"
#include "output.hpp"

#include <unordered_map>
#include <functional>
#include <iostream>

#include "lexerhelper.hpp"
#include "printTree.hpp"

namespace soviet {
	namespace parser {
		class Parser {
		public:
			Node parse(std::vector<soviet::lexer::Token>& tokens);
		private:
			unsigned int line = 0;
		};
	}
}