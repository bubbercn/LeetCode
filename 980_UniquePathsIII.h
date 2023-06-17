#pragma once
#include "Common.h"

class Solution
{
public:
    int uniquePathsIII(vector<vector<int>> &grid)
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
    vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
    EXPECT_EQ(solution.uniquePathsIII(grid), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}};
    EXPECT_EQ(solution.uniquePathsIII(grid), 4);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> grid = {{0, 1}, {2, 0}};
    EXPECT_EQ(solution.uniquePathsIII(grid), 0);
}