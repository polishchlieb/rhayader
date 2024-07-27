#pragma once
#include "../values/values.hpp"

namespace rhayader {
	class IOModule : public ModuleValue {
	public:
		IOModule(Evaluator& evaluator);

	private:
		static std::shared_ptr<Value> print(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> input(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
	};
}