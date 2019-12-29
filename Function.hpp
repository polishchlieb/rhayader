#pragma once
#include <functional>
#include <any>
#include "Node.hpp"

namespace soviet {
	typedef std::function<void* (std::vector<std::any>&)> function;

	struct Function {
		function call;
		int argCount = 0;
	};
}
