#pragma once
#include "../values/values.hpp"

namespace rhayader {
	class StringModule : public ModuleValue {
	public:
		StringModule(Evaluator& evaluator);

	private:
		static std::shared_ptr<Value> split(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> at(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> slice(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> length(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> starts_with(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> ends_with(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> contains(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> replace_all(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> from_int(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> index_of(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> to_upper(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> to_lower(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> characters(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> to_string(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> reverse(Evaluator&, std::vector<std::shared_ptr<Value>>& args);
	};
}