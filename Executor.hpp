#pragma once
#include "Node.hpp"
#include "output.hpp"
#include <unordered_map>
#include <functional>
#include "Function.hpp"
#include <any>
#include "Variable.hpp"

namespace soviet {
	namespace executor {
		class Executor {
		public:
			Executor();
			void registerFunction(const std::string& name, fn func, int argCount);

			void execute(const Node&, unsigned int line);
			std::any parse(const Node&, unsigned int line);
		private:
			std::unordered_map<std::string, Function> functions;
			std::unordered_map<std::string, Variable> variables;
		};
	}
}