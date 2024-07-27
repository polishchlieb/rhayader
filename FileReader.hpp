#pragma once
#include <fstream>
#include <string>
#include "tokenizer/Tokenizer.hpp"
#include "parser/Parser.hpp"

namespace rhayader {
	class Evaluator;
}

class FileReader {
public:
	FileReader(std::string fileName, rhayader::Evaluator& evaluator);
	void execute();
	bool ok();

private:
	std::string previousLine = "";
	std::ifstream file;
	rhayader::Evaluator& evaluator;

	void readLine();
};