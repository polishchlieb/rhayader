#include "Executor.hpp"

#include "lexerhelper.hpp"

namespace soviet {
	namespace executor {
		Executor::Executor() {
			registerFunction("print", [](std::vector<std::any>& args) {
				print(std::any_cast<std::string>(args[0]) + '\n');
				return "dudu";
			}, 1);

			registerFunction("printArgs", [](std::vector<std::any>& args) {
				int i = 0;
				for (const auto& arg : args) {
					print(std::any_cast<std::string>(arg) + '\n');
					i++;
				}
				return "";
			}, -1);

			registerFunction("string", [](std::vector<std::any>& args) {
				return args[0];
			}, 1);
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
				} else {
					error("Error", "invalid function name");
				}
			}
			else if (node.type == NodeType::assignment) {
				const std::string name = node.children[0].value.value;
				variables[name] = { parse(node.children[1], line) };
			}
			else if (node.type == NodeType::primitive) {
				print(node.value.value + '\n');
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
						arguments.push_back(parse(childNode, line));
					}

					return function.call(arguments);
				} else {
					error("Error", "invalid function name");
				}
			} else if (node.type == NodeType::primitive) {
				if (node.value.type == lexer::TokenType::name) {
					if (variables.find(node.value.value) == variables.end())
						error("Error", "couldn't find name " + node.value.value);
					return variables[node.value.value].value;
				}

				return node.value.value;
			}

			return nullptr;
		}
		
		void Executor::registerFunction(const std::string& name, fn func, int argCount) {
			functions[name] = Function{ func, argCount };
		}
	}
}


