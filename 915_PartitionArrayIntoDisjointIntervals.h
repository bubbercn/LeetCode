#pragma once
#include "Common.h"

class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
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
    vector<int> nums = {5, 0, 3, 8, 6};
    EXPECT_EQ(solution.partitionDisjoint(nums), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1,1,1,0,6,12};
    EXPECT_EQ(solution.partitionDisjoint(nums), 4);
}