#include "IO.hpp"
#include <iostream>

namespace rhayader {
    IOModule::IOModule(Evaluator& evaluator) : ModuleValue{evaluator, "IO"} {
        std::ios_base::sync_with_stdio(false);

        variables["print"] = std::make_shared<FunctionValue>(&print);
        variables["input"] = std::make_shared<FunctionValue>(&input);
    }

    std::shared_ptr<Value> IOModule::print(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args) {
        for (const auto& arg : args)
            std::cout << arg->dump() << " ";
        std::cout << "\n";
        return std::make_shared<UndefinedValue>();
    }

    std::shared_ptr<Value> IOModule::input(Evaluator& evaluator, std::vector<std::shared_ptr<Value>>& args) {
        std::string result;
        std::getline(std::cin, result);
        return std::make_shared<StringValue>(result);
    }
}