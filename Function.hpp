#pragma once
#include <functional>
#include <any>
#include "Node.hpp"

namespace soviet {
	typedef std::function<std::any(std::vector<std::any>&)> fn;

	struct Function {
		fn call;
		int argCount = 0;
	};
}
