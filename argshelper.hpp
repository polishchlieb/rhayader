#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "output.hpp"

namespace soviet {
	enum flag {
		SOVIET_DEBUG_PRINT
	};

	class array : public std::vector<flag> {
	public:
		bool has(flag flag);
	};

	struct ArgumentData {
		std::string filename;
		array flags;
	};

	ArgumentData parseArgs(int argc, const char** argv);
}