#pragma once
#include "Common.h"

class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
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
    vector<vector<int>> wall = {
        {1, 2, 2, 1},
        {3, 1, 2},
        {1, 3, 2},
        {2, 4},
        {3, 1, 2},
        {1, 3, 1, 1},
    };
    EXPECT_EQ(solution.leastBricks(wall), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> wall = {
        {1},
        {1},
        {1},
    };
    EXPECT_EQ(solution.leastBricks(wall), 3);
}
