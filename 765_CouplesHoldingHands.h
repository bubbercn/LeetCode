#pragma once
#include "Common.h"

class Solution
{
public:
    int minSwapsCouples(vector<int> &row)
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
    vector<int> row = {0, 2, 1, 3};
    EXPECT_EQ(solution.minSwapsCouples(row), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> row = {3, 2, 0, 1};
    EXPECT_EQ(solution.minSwapsCouples(row), 0);
}