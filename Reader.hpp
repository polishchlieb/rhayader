#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Reader {
public:
	Reader(std::string filename);
	void close();
	
	std::vector<std::string> lines;
private:
	std::ifstream file;
};