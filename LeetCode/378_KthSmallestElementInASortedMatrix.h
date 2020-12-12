#pragma once
#include "Common.h"

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
    inline static vector<vector<int>> matrix;
};

TEST_F(LeetCodeTest, Example1)
{
    matrix = {{1, 5, 9},
              {10, 11, 13},
              {12, 13, 15}};
    EXPECT_EQ(solution.kthSmallest(matrix, 8), 13);
}