#include "Scope.hpp"

namespace rhayader {
	void Scope::merge(Scope* other) {
		for (const auto& [name, value] : other->variables)
			variables.insert({ name, value });
	}

	void Scope::merge(Scope& other) {
		this->merge(&other);
	}
}