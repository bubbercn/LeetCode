#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
    {
        for (auto &row : image)
        {
            reverse(row.begin(), row.end());
            transform(row.begin(), row.end(), row.begin(), [](int i)
                      { return i == 0 ? 1 : 0; });
        }
        return image;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> image = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 0, 0},
    };
    vector<vector<int>> output = {
        {1, 0, 0},
        {0, 1, 0},
        {1, 1, 1},
    };
    EXPECT_EQ(solution.flipAndInvertImage(image), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> image = {
        {1, 1, 0, 0},
        {1, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 0, 1, 0},
    };
    vector<vector<int>> output = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 1, 0},
    };
    EXPECT_EQ(solution.flipAndInvertImage(image), output);
}