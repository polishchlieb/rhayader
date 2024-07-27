#pragma once
#include <queue>
#include "NoTokensError.hpp"
#include "Token.hpp"

namespace rhayader {
	class TokenList {
	public:
        explicit TokenList(std::queue<Token> tokens);

        Token& peekNextToken();
        Token getNextToken();
        bool hasNextToken();
        void dump();
    private:
        std::queue<Token> tokens;
	};
}