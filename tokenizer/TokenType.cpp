#include "TokenType.hpp"

namespace rhayader {
	std::string dumpTokenType(const TokenType type) {
		switch (type) {
			case TokenType::undefined: return "undefined";
			case TokenType::unknown: return "unknown";
			case TokenType::none: return "none";
			case TokenType::name: return "name";
			case TokenType::number: return "number";
			case TokenType::string: return "string";
			case TokenType::add_op: return "add_operator";
			case TokenType::sub_op: return "subtract_operator";
			case TokenType::div_op: return "divide_operator";
			case TokenType::mul_op: return "multiply_operator";
			case TokenType::open_bracket: return "open_bracket";
			case TokenType::close_bracket: return "close_bracket";
			case TokenType::equals_op: return "equals_operator";
			case TokenType::double_equals_op: return "double_equals_operator";
			case TokenType::not_equals_op: return "not_equals_operator";
			case TokenType::comma: return "comma";
			case TokenType::arrow: return "arrow";
			case TokenType::greater_than: return "greater_than";
			case TokenType::open_curly_bracket: return "open_curly_bracket";
			case TokenType::close_curly_bracket: return "close_curly_bracket";
			case TokenType::dot: return "dot";
			case TokenType::comment: return "comment";
			case TokenType::negation: return "negation";
			case TokenType::less_than_op: return "less_than";
			case TokenType::greater_than_or_equal_op: return "greater_than_or_equal_op";
			case TokenType::less_than_or_equal_op: return "less_than_or_equal_op";
			case TokenType::open_square_bracket: return "open_square_bracket";
			case TokenType::close_square_bracket: return "close_square_bracket";
			case TokenType::colon: return "colon";
			case TokenType::or_op: return "or";
			case TokenType::and_op: return "and";
			case TokenType::pipe_op: return "pipe";
			default:
				throw ParseError("Unknown error");
		}
	}
}