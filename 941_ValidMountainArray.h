#pragma once
#include "Common.h"

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int i = 0;
        for (i = 1; i < arr.size(); i++)
        {
            if (arr[i] == arr[i - 1])
                return false;
            
            if (arr[i] < arr[i - 1])
            {
                i--;
                break;
            }
        }
        if (i == arr.size())
            return false;
        int j = 0;
        for (j = arr.size() - 2; j >= 0; j--)
        {
            if (arr[j] == arr[j + 1])
                return false;
            
            if (arr[j] < arr[j + 1])
            {
                j++;
                break;
            }
        }
        if (j == -1)
            return false;

        return i == j;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> arr = {2, 1};
    EXPECT_EQ(solution.validMountainArray(arr), false);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {3, 5, 5};
    EXPECT_EQ(solution.validMountainArray(arr), false);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> arr = {0, 3, 2, 1};
    EXPECT_EQ(solution.validMountainArray(arr), true);
}