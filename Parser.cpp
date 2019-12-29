#include "Parser.hpp"

namespace soviet {
	namespace parser {
		Node Parser::parse(std::vector<soviet::lexer::Token>& tokens) {
			if (tokens.size() > 2 && tokens[1].value == "(") {
				auto functionName = tokens[0];

				// Remove the function's name to easily iterate over other stuff
				tokens.erase(tokens.begin());

				// Current argument tokens' vector, we'll call another parse(s) on it
				std::vector<soviet::lexer::Token> current;
				std::vector<Node> arguments;

				// Bracket level
				int level = 0;
				for (const auto& token : tokens) {
					if (token.value == "(") {
						level++;
						if (level != 1) {
							current.push_back(token);
							print("");
						}
					} else if (token.value == ")") {
						level--;

						if (level != 0) {
							current.push_back(token);
							print("");
						}

						if (current.size() != 0) {
							arguments.push_back(parse(current));
							current.clear();
						}

						// TODO: Handling stuff after function call
						if (level == 0) {
							print("");
							break;
						}
					} else if (token.value == "," && level == 1) {
						if (current.size() != 0) {
							arguments.push_back(parse(current));
							current.clear();
						}
					} else {
						current.push_back(token);
						print("");
					}
				}

				if (level != 0)
					error("SyntaxError", "Couldn't match brackets");

				Node node{
					NodeType::functionCall,
					functionName,
					arguments
				};

				return node;
			}
			else if (tokens.size() >= 2 && tokens[1].value == "()") {
				return Node{
					NodeType::functionCall,
					tokens[0],
					std::vector<Node>()
				};
			}
			else if (tokens.size() > 2 && tokens[1].value == ":=") {
				const auto equals = tokens[1];
				std::vector<Node> children;

				children.push_back(Node{
					NodeType::primitive,
					tokens[0]
				});
				tokens.erase(tokens.begin());
				tokens.erase(tokens.begin());
				children.push_back(parse(tokens));

				return Node{
					NodeType::assignment,
					equals,
					children
				};
			}
			else if (tokens.size() == 1) {
				// typedef soviet::lexer::TokenType TokenType;

				return Node{
					NodeType::primitive,
					tokens[0]
				};
			}

			return Node();
		}
	}
}