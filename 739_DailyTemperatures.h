#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> lookup;
        size_t n = temperatures.size();
        vector<int> result(n, 0);
        for (size_t i = 0; i < n; i++)
        {
            while (!lookup.empty() && temperatures[i] > temperatures[lookup.top()])
            {
                result[lookup.top()] = i - lookup.top();
                lookup.pop();
            }
            lookup.emplace(i);
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
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> output = {1, 1, 4, 2, 1, 1, 0, 0};
    EXPECT_EQ(solution.dailyTemperatures(temperatures), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> temperatures = {30, 40, 50, 60};
    vector<int> output = {1, 1, 1, 0};
    EXPECT_EQ(solution.dailyTemperatures(temperatures), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> temperatures = {30, 60, 90};
    vector<int> output = {1, 1, 0};
    EXPECT_EQ(solution.dailyTemperatures(temperatures), output);
}