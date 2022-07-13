#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        vector<pair<int, int>> fractions;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                fractions.emplace_back(arr[i], arr[j]);
            }
        }
        nth_element(fractions.begin(), fractions.begin() + k - 1, fractions.end(), [](const pair<int, int> &a, const pair<int, int> &b)
                    { return a.first * b.second < a.second * b.first; });
        return {fractions[k - 1].first, fractions[k - 1].second};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> arr = {1, 2, 3, 5};
    vector<int> output = {2, 5};
    EXPECT_EQ(solution.kthSmallestPrimeFraction(arr, 3), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {1, 7};
    vector<int> output = {1, 7};
    EXPECT_EQ(solution.kthSmallestPrimeFraction(arr, 1), output);
}