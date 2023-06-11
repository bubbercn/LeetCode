#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
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
    vector<int> output = {2, 3, 4, 5, 7, 9, 10};
    EXPECT_EQ(solution.powerfulIntegers(2, 3, 10), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {2, 4, 6, 8, 10, 14};
    EXPECT_EQ(solution.powerfulIntegers(3, 5, 15), output);
}