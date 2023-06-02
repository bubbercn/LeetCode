#pragma once
#include "Common.h"

class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {
        multiset<int> nonNegative;
        multiset<int, greater<int>> negative;
        for (auto num : arr)
        {
            if (num >= 0)
            {
                nonNegative.emplace(num);
            }
            else
            {
                negative.emplace(num);
            }
        }
        while (!nonNegative.empty())
        {
            int temp = *nonNegative.begin();
            nonNegative.erase(nonNegative.begin());
            if (auto it = nonNegative.find(temp * 2); it != nonNegative.end())
            {
                nonNegative.erase(it);
            }
            else
            {
                return false;
            }
        }
        while (!negative.empty())
        {
            int temp = *negative.begin();
            negative.erase(negative.begin());
            if (auto it = negative.find(temp * 2); it != negative.end())
            {
                negative.erase(it);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> arr = {3, 1, 3, 6};
    EXPECT_EQ(solution.canReorderDoubled(arr), false);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {2, 1, 2, 6};
    EXPECT_EQ(solution.canReorderDoubled(arr), false);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> arr = {4, -2, 2, -4};
    EXPECT_EQ(solution.canReorderDoubled(arr), true);
}