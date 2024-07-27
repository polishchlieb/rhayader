#include "FileReader.hpp"
#include "evaluator/evaluator.hpp"

void getfileline(rhayader::Evaluator& evaluator, std::ifstream& file, std::string& previousLine) {
	std::string line;
	std::getline(file, line);
	line = previousLine + line;

	rhayader::Tokenizer tokenizer;
	try {
		tokenizer.tokenize(line);
	} catch (const rhayader::Error& error) {
		error.print();
		return;
	}

	rhayader::Parser parser{tokenizer.getTokens()};

	std::shared_ptr<rhayader::Node> tree;
	try {
		tree = parser.parse();
	} catch (const rhayader::Error& error) {
		if (error.type == rhayader::ErrorType::NoTokens) {
			if (file.eof()) {
				std::cout << "ParseError: parser needs a token, but file finished reading" << std::endl;
				exit(69);
			}

			previousLine = line;
		} else {
			error.print();
		}
		return;
	}

	previousLine = "";

	try {
		evaluator.evaluate(tree);
	} catch (const rhayader::Error& error) {
		error.print();
	}
}

FileReader::FileReader(std::string fileName, rhayader::Evaluator& evaluator)
	: evaluator(evaluator), file{fileName}
{}

void FileReader::execute() {
	while (!file.eof()) {
		readLine();
	}
}

bool FileReader::ok() {
	return file.is_open();
}

void FileReader::readLine() {
	std::string line;
	std::getline(file, line);
	line = previousLine + line;

	rhayader::Tokenizer tokenizer;
	try {
		tokenizer.tokenize(line);
	} catch (const rhayader::Error& error) {
		error.print();
		return;
	}

	rhayader::Parser parser{tokenizer.getTokens()};

	std::shared_ptr<rhayader::Node> tree;
	try {
		tree = parser.parse();
	} catch (const rhayader::Error& error) {
		if (error.type == rhayader::ErrorType::NoTokens) {
			if (file.eof()) {
				std::cout << "ParseError: parser needs a token, but file finished reading" << std::endl;
				exit(69);
			}

			previousLine = line;
		} else {
			error.print();
		}
		return;
	}

	previousLine = "";

	try {
		evaluator.evaluate(tree);
	} catch (const rhayader::Error& error) {
		error.print();
	}
}
