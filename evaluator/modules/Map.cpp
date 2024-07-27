#include "Map.hpp"
#include "../EvaluateError.hpp"

namespace rhayader {
	MapModule::MapModule(Evaluator& evaluator) : ModuleValue{evaluator, "Map"} {
		variables["new"] = std::make_shared<FunctionValue>(&newmap);
		variables["set"] = std::make_shared<FunctionValue>(&set);
		variables["remove"] = std::make_shared<FunctionValue>(&remove);
		variables["at"] = std::make_shared<FunctionValue>(&at);
		variables["entries"] = std::make_shared<FunctionValue>(&entries);
		variables["keys"] = std::make_shared<FunctionValue>(&keys);
		variables["values"] = std::make_shared<FunctionValue>(&values);
		variables["size"] = std::make_shared<FunctionValue>(&size);
		variables["is_map"] = std::make_shared<FunctionValue>(&is_map);
	}

	std::shared_ptr<Value> MapModule::newmap(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args) {
		if (args.size() == 0)
			return std::make_shared<MapValue>();

		auto result = std::make_shared<MapValue>();
		for (const auto& arg : args) {
			if (arg->type != ValueType::ArrayValue)
				throw EvaluateError("map constructor is kaput");
			const auto entry = valueCast<ArrayValue>(arg);
			if (entry->size() != 2)
				throw EvaluateError("map constructor is kaput");

			result->set(entry->at(0)->dump(), entry->at(1));
		}
		return result;
	}

	std::shared_ptr<Value> MapModule::set(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args) {
		const auto map = valueCast<MapValue>(args[0]->clone());
		map->set(args[1]->dump(), args[2]);
		return map;
	}

	std::shared_ptr<Value> MapModule::remove(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args) {
		const auto map = valueCast<MapValue>(args[0]->clone());
		map->remove(args[1]->dump());
		return map;
	}

	std::shared_ptr<Value> MapModule::at(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args) {
		return valueCast<MapValue>(args[0])->get(args[1]->dump());
	}

	std::shared_ptr<Value> MapModule::entries(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args) {
		const auto map = valueCast<MapValue>(args[0]);
		const auto result = std::make_shared<ArrayValue>();

		for (const auto& [key, value] : map->entries())
			result->add(std::make_shared<ArrayValue>(std::vector{key, value}));

		return result;
	}

	std::shared_ptr<Value> MapModule::keys(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args) {
		const auto map = valueCast<MapValue>(args[0]);
		return std::make_shared<ArrayValue>(map->keys());
	}

	std::shared_ptr<Value> MapModule::values(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args) {
		const auto map = valueCast<MapValue>(args[0]);
		return std::make_shared<ArrayValue>(map->values());
	}

	std::shared_ptr<Value> MapModule::size(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args) {
		const auto map = valueCast<MapValue>(args[0]);
		return std::make_shared<NumberValue>((float) map->size());
	}

	std::shared_ptr<Value> MapModule::is_map(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args) {
		return std::make_shared<BooleanValue>(
			args[0]->type == ValueType::MapValue
		);
	}

}