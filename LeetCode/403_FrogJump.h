#pragma once
#include "Common.h"

class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    EXPECT_EQ(solution.canCross(stones), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> stones = {0, 1, 2, 3, 4, 8, 9, 11};
    EXPECT_EQ(solution.canCross(stones), false);
}
