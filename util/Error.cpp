#include "Error.hpp"

namespace rhayader {
	Error::Error(ErrorType type) : type(type) {}

	void Error::print() const {
		std::cerr
			<< color(Color::RED)
			<< name() << ": " << message()
			<< color(Color::RESET) << std::endl;
	}
}