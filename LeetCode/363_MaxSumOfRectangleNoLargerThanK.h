#pragma once
#include "Common.h"

class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
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
    vector<vector<int>> matrix = {{1, 0, 1}, {0, -2, 3}};
    EXPECT_EQ(solution.maxSumSubmatrix(matrix, 2), 2);
}