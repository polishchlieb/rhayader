cmake_minimum_required(VERSION 3.20)
project(rhayader)

set(CMAKE_CXX_STANDARD 20)

add_executable(
  rhayader
  main.cpp repl.cpp FileReader.cpp
  util/colors.cpp util/Error.cpp util/util.cpp
  tokenizer/FileReadError.cpp tokenizer/NoTokensError.cpp tokenizer/Token.cpp tokenizer/Tokenizer.cpp tokenizer/TokenList.cpp tokenizer/TokenType.cpp
  parser/dumpNode.cpp parser/nodes.cpp parser/ParseError.cpp parser/Parser.cpp
  evaluator/modules/Array.cpp evaluator/modules/IO.cpp evaluator/modules/Map.cpp evaluator/modules/Math.cpp evaluator/modules/String.cpp evaluator/modules/ThreadModule.cpp
  evaluator/values/ArrayValue.cpp evaluator/values/BooleanValue.cpp evaluator/values/ExplicitReturnValue.cpp evaluator/values/FunctionValue.cpp evaluator/values/MapValue.cpp evaluator/values/ModuleValue.cpp evaluator/values/NullValue.cpp evaluator/values/NumberValue.cpp evaluator/values/RangeValue.cpp evaluator/values/StringValue.cpp evaluator/values/UndefinedValue.cpp evaluator/values/ValueType.cpp
  evaluator/EvaluateError.cpp evaluator/evaluator.cpp evaluator/GlobalScope.cpp evaluator/Scope.cpp evaluator/Thread.cpp
)