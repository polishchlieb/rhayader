cmake_minimum_required(VERSION 3.17)
project(soviet)

set(CMAKE_CXX_STANDARD 20)

add_executable(soviet main.cpp tokenizer/Token.hpp tokenizer/TokenType.hpp tokenizer/tokenizer.hpp tokenizer/PendingToken.hpp tokenizer/PendingTokenType.hpp parser/Parser.hpp parser/nodes/Node.hpp parser/nodes/NodeType.hpp parser/nodes/NumberNode.hpp parser/node_cast.hpp parser/nodes/AddOpNode.hpp parser/nodes/nodes.hpp parser/dumpNode.hpp parser/nodes/SubOpNode.hpp parser/nodes/MulOpNode.hpp parser/nodes/DivOpNode.hpp)