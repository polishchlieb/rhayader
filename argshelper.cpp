#include "argshelper.hpp"
#include <iostream>

namespace soviet {
	bool array::has(flag f) {
		return std::find(this->begin(), this->end(), f) != this->end();
	}

	ArgumentData parseArgs(int argc, const char** argv) {
		if (argc == 0) {
			error("Error", "no input file specified");
		}

		ArgumentData data{ argv[0] };

		for (int i = 1; i < argc; ++i) {
			const std::string argument = argv[i];
			if (argument == "--debug-print") {
				data.flags.push_back(SOVIET_DEBUG_PRINT);
			}
		}

		return data;
	}
}