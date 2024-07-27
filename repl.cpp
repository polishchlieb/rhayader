#include "repl.hpp"

static rhayader::Thread mainThread;

std::string previousLine = "";

void getline() {
	std::cout << ">>> ";

	std::string line;
	std::getline(std::cin, line);
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
			previousLine = line;
		} else {
			error.print();
		}
		return;
	}

	previousLine = "";

	try {
		const auto value = mainThread.evaluator->evaluate(tree);
		std::cout << value->dump() << std::endl;
	} catch (const rhayader::Error& error) {
		error.print();
	}
}
