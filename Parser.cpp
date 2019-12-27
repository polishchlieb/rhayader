#include "Parser.hpp"

namespace soviet {
	namespace parser {
		Node Parser::parse(std::vector<soviet::lexer::Token>& tokens) {
			if (tokens.size() > 2 && tokens[1].value == "(") {
				auto functionName = tokens[0];
				// Remove the function's name to
				// easily iterate over other stuff

				tokens.erase(tokens.begin()); // func (

				// Arguments vector, we'll call another parse(s) on it
				std::vector<soviet::lexer::Token> current;
				std::vector<Node> arguments;

				// Bracket level
				int level = 0;
				for (const auto& token : tokens) {
					if (token.value == "(") {
						level++;
					} else if (token.value == ")") {
						level--;

						if (current.size() != 0)
							arguments.push_back(parse(current));

						// TODO: Handling stuff after function call
						if (level == 0) break;
					} else if (token.value == "," && level == 1) {
						arguments.push_back(parse(current));
						current.clear();
					} else {
						current.push_back(token);
					}
				}

				if (level != 0) {
					error("SyntaxError", "Couldn't match brackets");
				}

				return Node{
					NodeType::functionCall,
					functionName,
					arguments
				};
			}
			if (tokens.size() >= 2 && tokens[1].value == "()") {
				return Node{
					NodeType::functionCall,
					tokens[0],
					std::vector<Node>()
				};
			}
			if (tokens.size() == 1) {
				return Node{
					NodeType::primitive,
					tokens[0]
				};
			}
			return Node();
		}
	}
}