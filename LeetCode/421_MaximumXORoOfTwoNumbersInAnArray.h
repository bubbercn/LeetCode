#pragma once
#include "Common.h"

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
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
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    EXPECT_EQ(solution.findMaximumXOR(nums), 28);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {0};
    EXPECT_EQ(solution.findMaximumXOR(nums), 0);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {2, 4};
    EXPECT_EQ(solution.findMaximumXOR(nums), 6);
}

TEST_F(LeetCodeTest, Example4)
{
    vector<int> nums = {8, 10, 2};
    EXPECT_EQ(solution.findMaximumXOR(nums), 10);
}

TEST_F(LeetCodeTest, Example5)
{
    vector<int> nums = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    EXPECT_EQ(solution.findMaximumXOR(nums), 127);
}
