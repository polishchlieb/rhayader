#pragma once
#include <string>

namespace soviet {
	enum flag {
		SOVIET_OPTIMIZE
	};

	struct ArgumentData {
		std::string filename;
		flag flags[];
	};

	ArgumentData parseArgs(int argc, char** argv) {}
}