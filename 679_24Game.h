#pragma once
#include "Common.h"

class Solution
{
public:
    bool judgePoint24(vector<int> &cards)
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
    vector<int> cards = {4, 1, 8, 7};
    EXPECT_EQ(solution.judgePoint24(cards), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> cards = {1, 2, 1, 2};
    EXPECT_EQ(solution.judgePoint24(cards), false);
}