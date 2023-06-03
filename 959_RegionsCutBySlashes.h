#pragma once
#include "Common.h"

class Solution
{
public:
    int regionsBySlashes(vector<string> &grid)
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
    vector<string> grid = {" /", "/ "};
    EXPECT_EQ(solution.regionsBySlashes(grid), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> grid = {" /","  "};
    EXPECT_EQ(solution.regionsBySlashes(grid), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> grid = {"/\\","\\/"};
    EXPECT_EQ(solution.regionsBySlashes(grid), 5);
}