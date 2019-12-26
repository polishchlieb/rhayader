#include "Executor.hpp"

void soviet::executor::Executor::execute(Node& node, unsigned int line) {
	if (node.value.value == "print")
		print(node.children[0].value.value);
}
