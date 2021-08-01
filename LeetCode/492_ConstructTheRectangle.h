#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        for (int i = sqrt(area); i >= 1; i--)
        {
            if (area % i == 0)
            {
                return {area / i, i};
            }
        }
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
    vector<int> output = {2, 2};
    EXPECT_EQ(solution.constructRectangle(4), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {37, 1};
    EXPECT_EQ(solution.constructRectangle(37), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> output = {427, 286};
    EXPECT_EQ(solution.constructRectangle(122122), output);
}