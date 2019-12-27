#pragma once
#include "Node.hpp"
#include "output.hpp"
#include <unordered_map>
#include <functional>

namespace soviet {
	namespace executor {
		class Executor {
		public:
			Executor();
			void execute(Node&, unsigned int);
		private:
			std::unordered_map<std::string, std::function<void*(std::vector<Node>&)>> shittyFunctions;
		};
	}
}