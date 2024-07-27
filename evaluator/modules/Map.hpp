#pragma once
#include "../values/values.hpp"

namespace rhayader {
	class MapModule : public ModuleValue {
	public:
		MapModule(Evaluator& evaluator);

	private:
		static std::shared_ptr<Value> newmap(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> set(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> remove(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> at(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> entries(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> keys(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> values(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> size(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> is_map(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
	};
}