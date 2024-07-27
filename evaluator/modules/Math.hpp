#pragma once
#include "../values/values.hpp"

namespace rhayader {
	class MathModule : public ModuleValue {
	public:
		MathModule(Evaluator& evaluator);

	private:
		static std::shared_ptr<Value> sin(Evaluator&, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> cos(Evaluator&, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> sqrt(Evaluator&, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> pow(Evaluator&, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> max(Evaluator&, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> random(Evaluator&, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> mod(Evaluator&, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> round(Evaluator&, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> floor(Evaluator&, std::vector<std::shared_ptr<Value>>& args);
		static std::shared_ptr<Value> ceil(Evaluator&, std::vector<std::shared_ptr<Value>>& args);
	};
}