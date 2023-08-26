#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> fallingSquares(vector<vector<int>> &positions)
    {
        int n = positions.size();
        vector<int> base(n, 0);
        vector<int> result(n, 0);
        int maxHeight = 0;
        for (int i = 0; i < n; i++)
        {
            int newHeight = base[i] + positions[i][1];
            maxHeight = max(maxHeight, newHeight);
            result[i] = maxHeight;
            for (int j = i + 1; j < n; j++)
            {
                if ((positions[i][0] >= positions[j][0] && positions[i][0] < positions[j][0] + positions[j][1]) || (positions[j][0] >= positions[i][0] && positions[j][0] < positions[i][0] + positions[i][1]))
                    base[j] = max(base[j], newHeight);
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
    vector<vector<int>> positions = {
        {1, 2},
        {2, 3},
        {6, 1},
    };
    vector<int> output = {2, 5, 5};
    EXPECT_EQ(solution.fallingSquares(positions), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> positions = {
        {100, 100},
        {200, 100},
    };
    vector<int> output = {100, 100};
    EXPECT_EQ(solution.fallingSquares(positions), output);
}

TEST_F(LeetCodeTest, Case1)
{
    vector<vector<int>> positions = {
        {100000000, 1000000},
    };
    vector<int> output = {1000000};
    EXPECT_EQ(solution.fallingSquares(positions), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> positions = {
        {50, 47},
        {95, 48},
        {88, 77},
        {84, 3},
        {53, 87},
        {98, 79},
        {88, 28},
        {13, 22},
        {53, 73},
        {85, 55},
    };
    vector<int> output = {47, 95, 172, 172, 259, 338, 366, 366, 439, 494};
    EXPECT_EQ(solution.fallingSquares(positions), output);
}
