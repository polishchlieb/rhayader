#pragma once
#include "Node.hpp"
#include "Token.hpp"

namespace soviet {
	namespace parser {
		class Parser {
		public:
			Node parse(std::vector<soviet::lexer::Token>&);
		private:
			unsigned int line = 0;
		};
	}
}