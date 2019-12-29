#include "Executor.hpp"

namespace soviet {
	namespace executor {
		Executor::Executor() {
			registerFunction("print", [](std::vector<std::any>& args) {
				print(std::any_cast<std::string>(args[0]) + '\n');
				return nullptr;
			}, 1);

			registerFunction("printArgs", [](std::vector<std::any>& args) {
				for (const auto& arg : args) {
					print(std::any_cast<std::string>(arg) + '\n');
				}
				return nullptr;
			}, -1);
		}

		void Executor::execute(const Node& node, unsigned int line) {
			if (node.type == NodeType::functionCall) {
				const std::string& name = node.value.value;
				if (functions.find(name) != functions.end()) {
					const auto& function = functions[name];
					// Naive args checking xD
					if (function.argCount != node.children.size() && function.argCount != -1)
						error("Error", "invalid arg count");
					
					std::vector<std::any> children;
					for (const auto& childNode : node.children) {
						children.push_back(parse(childNode, line));
					}
					function.call(children);
				}
			}
		}

		std::any Executor::parse(const Node& node, unsigned int line) {
			if (node.type == NodeType::functionCall) {
				const std::string& name = node.value.value;
				if (functions.find(name) != functions.end()) {
					const auto& function = functions[name];
					// Naive args checking xD
					if (function.argCount != node.children.size() && function.argCount != -1)
						error("Error", "invalid arg count: " + std::to_string(node.children.size()));

					std::vector<std::any> arguments;
					for (const auto& childNode : node.children) {
						if (childNode.type != NodeType::primitive)
							arguments.push_back(parse(childNode, line));
					}

					return function.call(arguments);
				}
			} else if (node.type == NodeType::primitive) {
				return node.value.value;
			}
		}

		void Executor::registerFunction(const std::string& name, function func, int argCount) {
			functions[name] = Function{ func, argCount };
		}
	}
}


