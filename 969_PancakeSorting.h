#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        auto end = arr.end();
        vector<int> result;
        while (distance(arr.begin(), end) > 1)
        {
            auto max = max_element(arr.begin(), end);
            if (*max != *(end - 1))
            {
                reverse(arr.begin(), max + 1);
                result.emplace_back(distance(arr.begin(), max + 1));
                reverse(arr.begin(), end);
                result.emplace_back(distance(arr.begin(), end));
            }
            end--;
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
    vector<int> arr = {3, 2, 4, 1};
    vector<int> output = {3, 4, 2, 3, 1, 2};
    EXPECT_EQ(solution.pancakeSort(arr), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {1, 2, 3};
    vector<int> output = {};
    EXPECT_EQ(solution.pancakeSort(arr), output);
}