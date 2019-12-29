#pragma once
#include "Node.hpp"
#include "output.hpp"
#include <unordered_map>
#include <functional>
#include "Function.hpp"
#include <any>

namespace soviet {
	namespace executor {
		class Executor {
		public:
			Executor();
			void registerFunction(const std::string& name, function func, int argCount);

			void execute(const Node&, unsigned int line);
			std::any parse(const Node&, unsigned int line);
		private:
			std::unordered_map<std::string, Function> functions;
		};
	}
}