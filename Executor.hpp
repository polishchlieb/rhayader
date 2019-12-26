#pragma once
#include "Node.hpp"
#include "output.hpp"

namespace soviet {
	namespace executor {
		class Executor {
		public:
			void execute(Node&, unsigned int);
		};
	}
}