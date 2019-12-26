#include "file_reader.hpp"

namespace soviet {
	void readLines(std::vector<std::string>& result, const std::string& filename) {
		std::ifstream file(filename);
		std::string current;

		while (std::getline(file, current)) {
			result.push_back(current);
		}
	}
}