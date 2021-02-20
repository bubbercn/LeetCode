#pragma once
#include "Common.h"

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Case1)
{
    EXPECT_EQ(solution.addStrings("100","21"), "121");
}