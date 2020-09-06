#pragma once
#include "Common.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> prices = {1, 2, 3, 0, 2};
    EXPECT_EQ(solution.maxProfit(prices), 3);
}