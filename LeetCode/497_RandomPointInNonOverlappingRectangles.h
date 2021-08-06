#pragma once
#include "Common.h"

class Solution
{
public:
    Solution()
    {
    }

    Solution(vector<vector<int>> &rects)
    {
    }

    vector<int> pick()
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> rects{{-2, -2, 1, 1}, {2, 2, 4, 6}};
    Solution temp(rects);
    temp.pick();
}