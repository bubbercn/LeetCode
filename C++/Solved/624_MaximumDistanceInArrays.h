#pragma once
#include "Common.h"

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int result = 0;
        int min = arrays[0].front();
        int max = arrays[0].back();
        for (int i = 1; i < arrays.size(); i++)
        {
            vector<int> &array = arrays[i];
            result = ::max(result, abs(array.front() - max));
            result = ::max(result, abs(array.back() - min));
            min = ::min(min, array.front());
            max = ::max(max, array.back());
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
    vector<vector<int>> arrays = {{1, 2, 3}, {4, 5}, {1, 2, 3}};
    EXPECT_EQ(solution.maxDistance(arrays), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> arrays = {{1}, {1}};
    EXPECT_EQ(solution.maxDistance(arrays), 0);
}