#pragma once
#include "Common.h"

class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        int n = arr.size();
        unordered_set<int> result;
        for (int i = 0; i < n; i++)
        {
            result.emplace(arr[i]);
            for (int j = i - 1; j >= 0; j--)
            {
                if ((arr[j] | arr[i]) == arr[j])
                    break;
                arr[j] |= arr[i];
                result.insert(arr[j]);
            }
        }
        return result.size();
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> arr = {0};
    EXPECT_EQ(solution.subarrayBitwiseORs(arr), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {1, 1, 2};
    EXPECT_EQ(solution.subarrayBitwiseORs(arr), 3);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> arr = {1, 2, 4};
    EXPECT_EQ(solution.subarrayBitwiseORs(arr), 6);
}