#include "Executor.hpp"

namespace soviet {
	namespace executor {
		Executor::Executor() {
			shittyFunctions["print"] = [](std::vector<Node>& args) {
				print(args[0].value.value);
				return nullptr;
			};
		}

		void Executor::execute(Node& node, unsigned int line) {
			if (node.type == NodeType::functionCall) {
				if (shittyFunctions.find(node.value.value) != shittyFunctions.end()) {
					shittyFunctions[node.value.value](node.children);
				}
			}
		}
	}
}


