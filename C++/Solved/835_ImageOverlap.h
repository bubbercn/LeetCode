#pragma once
#include "Common.h"

class Solution
{
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        int n = img1.size();
        int result = 0;
        for (int dx = -n; dx <= n; dx++)
        {
            for (int dy = -n; dy <= n; dy++)
            {
                int count = 0;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (img1[i][j] == 0)
                            continue;
                        int x = i + dx;
                        int y = j + dy;
                        if (x < 0 || x >= n || y < 0 || y >= n)
                            continue;
                        if (img2[x][y] == 1)
                            count++;
                    }
                }
                result = max(result, count);
            }
        }
        return result;
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