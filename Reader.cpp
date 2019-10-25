#include "Reader.hpp"

Reader::Reader(std::string filename) {
	file.open(filename);
	if (!file) {
		std::cerr << "Blyat Vadim" << std::endl;
		exit(0);
	}

	std::string line;
	while (std::getline(file, line)) {
		lines.push_back(line);
	}
}

void Reader::close() {
	file.close();
}