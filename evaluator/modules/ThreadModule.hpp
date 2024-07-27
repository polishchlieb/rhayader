#pragma once
#include "../values/values.hpp"

namespace rhayader {
	class ThreadModule : public ModuleValue {
	public:
		ThreadModule(Evaluator& evaluator);

	private:
		static std::shared_ptr<Value> newthread(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> sleep(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
	};
}