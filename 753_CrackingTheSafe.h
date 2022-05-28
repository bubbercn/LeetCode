#pragma once
#include "Common.h"

class Solution
{
public:
    string crackSafe(int n, int k)
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
    EXPECT_EQ(solution.crackSafe(1, 2), "10");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.crackSafe(2, 2), "01100");
}
