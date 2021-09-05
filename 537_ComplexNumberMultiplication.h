#pragma once
#include "Common.h"

class Solution
{
public:
    string complexNumberMultiply(string num1, string num2)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    string num1 = "1+1i";
    string num2 = "1+1i";
    EXPECT_EQ(solution.complexNumberMultiply(num1, num2), "0+2i");
}

TEST_F(LeetCodeTest, Example2)
{
    string num1 = "1+-1i";
    string num2 = "1+-1i";
    EXPECT_EQ(solution.complexNumberMultiply(num1, num2), "0+-2i");
}