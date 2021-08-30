#pragma once
#include "Common.h"

class Solution
{
public:
    int countArrangement(int n)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.countArrangement(2), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {0, 1, 0};
    EXPECT_EQ(solution.countArrangement(1), 1);
}