#include <gtest/gtest.h>
#include "../tokenizer/Tokenizer.hpp"

class TokenizerTest : public ::testing::Test {
protected:
    tokenizer::Tokenizer t;
};

TEST_F(TokenizerTest, TokenizesAddOperation) {
    const auto value = t.tokenize("2 + 3");
    EXPECT_EQ(value.size(), 3);

    EXPECT_EQ(value[0].type, tokenizer::TokenType::number);
    EXPECT_EQ(value[0].value, "2");

    EXPECT_EQ(value[1].type, tokenizer::TokenType::add_op);
    EXPECT_EQ(value[1].value, "+");

    EXPECT_EQ(value[2].type, tokenizer::TokenType::number);
    EXPECT_EQ(value[2].value, "3");
}