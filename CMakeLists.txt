cmake_minimum_required(VERSION 3.17)
project(soviet)

set(CMAKE_CXX_STANDARD 20)

add_executable(soviet main.cpp tokenizer/Token.hpp tokenizer/TokenType.hpp tokenizer/tokenizer.hpp tokenizer/PendingToken.hpp tokenizer/PendingTokenType.hpp)