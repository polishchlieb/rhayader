#include "TokenList.hpp"

namespace rhayader {
	TokenList::TokenList(std::queue<Token> tokens)
		: tokens(std::move(tokens))
	{}

	void TokenList::dump() {
		while (!tokens.empty()) {
			Token token = tokens.front();
			tokens.pop();
			std::cout << token.line << ": (" << dumpTokenType(token.type) << ") "
				<< token.value << std::endl;
		}
	}

	Token& TokenList::peekNextToken() {
		if (tokens.empty())
			throw NoTokensError{};
		return tokens.front();
	}

	Token TokenList::getNextToken() {
		if (tokens.empty())
			throw NoTokensError{};
		Token token = std::move(tokens.front());
		tokens.pop();
		return token;
	}

	bool TokenList::hasNextToken() {
		return !tokens.empty();
	}
}