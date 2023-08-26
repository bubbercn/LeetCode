#pragma once
#include "Common.h"

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        vector<int> sortedArr(arr);
        sort(sortedArr.begin(), sortedArr.end());
        long sum1 = 0;
        long sum2 = 0;
        int result = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum1 += arr[i];
            sum2 += sortedArr[i];
            if (sum1 == sum2)
            {
                result++;
                sum1 = 0;
                sum2 = 0;
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
    vector<int> arr = {5, 4, 3, 2, 1};
    EXPECT_EQ(solution.maxChunksToSorted(arr), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {2, 1, 3, 4, 4};
    EXPECT_EQ(solution.maxChunksToSorted(arr), 4);
}