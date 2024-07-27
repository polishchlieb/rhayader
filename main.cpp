#ifdef RUN_TESTS
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#else
#include "repl.hpp"
#include "FileReader.hpp"
#endif

int main(int argc, char** argv) {
#ifdef RUN_TESTS
	Catch::Session().run(1, argv);
#else
	if (argc == 1) { // REPL
		std::cout << "welcome to Rhayader REPL (Really Epic Program Launcher)" << std::endl
			<< std::endl;

		while (true) {
			getline();
		}
	} else {
		rhayader::Thread thread;

		std::string fileName = argv[1];
		FileReader reader{fileName, *thread.evaluator};

		if (!reader.ok()) {
			std::cerr << "couldn't open the file" << std::endl;
			return 1;
		}

		reader.execute();
	}
#endif
}
