#pragma once
#include "Common.h"

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
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
    vector<vector<int>> heightMap = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1},
    };
    EXPECT_EQ(solution.trapRainWater(heightMap), 4);
}