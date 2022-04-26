#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
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