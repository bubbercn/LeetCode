#pragma once
#include "Common.h"

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int max = numeric_limits<int>::min();
        int result = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            max = ::max(max, arr[i]);
            if (max == i)
                result++;
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
    vector<int> arr = {4, 3, 2, 1, 0};
    EXPECT_EQ(solution.maxChunksToSorted(arr), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {1, 0, 2, 3, 4};
    EXPECT_EQ(solution.maxChunksToSorted(arr), 4);
}