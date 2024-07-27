#include "util.hpp"

namespace rhayader {
	std::string times(const std::string& str, unsigned int num) {
		std::string result;
		for (unsigned int i = 0; i < num; i++)
			result += str;
		return result;
	}
}