#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
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
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30},
    };
    vector<int> output = {20, 24};
    EXPECT_EQ(solution.smallestRange(nums), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> nums = {
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3},
    };
    vector<int> output = {1, 1};
    EXPECT_EQ(solution.smallestRange(nums), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> nums = {
        {10, 10},
        {11, 11},
    };
    vector<int> output = {10, 11};
    EXPECT_EQ(solution.smallestRange(nums), output);
}

TEST_F(LeetCodeTest, Example4)
{
    vector<vector<int>> nums = {
        {10},
        {11},
    };
    vector<int> output = {10, 11};
    EXPECT_EQ(solution.smallestRange(nums), output);
}

TEST_F(LeetCodeTest, Example5)
{
    vector<vector<int>> nums = {
        {1},
        {2},
        {3},
        {4},
        {5},
        {6},
        {7},
    };
    vector<int> output = {1, 7};
    EXPECT_EQ(solution.smallestRange(nums), output);
}