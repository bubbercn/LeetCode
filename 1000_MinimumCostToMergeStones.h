#pragma once
#include "Common.h"

class Solution
{
public:
    int mergeStones(vector<int> &stones, int k)
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
    vector<int> stones = {3, 2, 4, 1};
    EXPECT_EQ(solution.mergeStones(stones, 2), 20);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> stones = {3, 2, 4, 1};
    EXPECT_EQ(solution.mergeStones(stones, 3), -1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> stones = {3, 5, 1, 2, 6};
    EXPECT_EQ(solution.mergeStones(stones, 3), 25);
}