#include "Parser.hpp"

void soviet::parse(Node& node) {
	if (node.type == op && node.value == "+") {
		auto result = soviet::util::reduce<int, Node>(node.children, [](int& acc, Node& curr) {
			return acc + std::stoi(curr.value);
		}, 0);

		std::cout << result;
	}
}