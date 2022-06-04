#pragma once
#include "Common.h"

class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
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
    vector<vector<int>> intervals = {
        {1, 3},
        {1, 4},
        {2, 5},
        {3, 5},
    };
    EXPECT_EQ(solution.intersectionSizeTwo(intervals), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> intervals = {
        {1, 2},
        {2, 3},
        {2, 4},
        {4, 5},
    };
    EXPECT_EQ(solution.intersectionSizeTwo(intervals), 5);
}
