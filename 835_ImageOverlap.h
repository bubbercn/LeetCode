#pragma once
#include "Common.h"

class Solution
{
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
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
    vector<vector<int>> img1 = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 0},
    };
    vector<vector<int>> img2 = {
        {0, 0, 0},
        {0, 1, 1},
        {0, 0, 1},
    };
    EXPECT_EQ(solution.largestOverlap(img1, img2), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> img1 = {
        {1},
    };
    vector<vector<int>> img2 = {
        {1},
    };
    EXPECT_EQ(solution.largestOverlap(img1, img2), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> img1 = {
        {0},
    };
    vector<vector<int>> img2 = {
        {0},
    };
    EXPECT_EQ(solution.largestOverlap(img1, img2), 0);
}