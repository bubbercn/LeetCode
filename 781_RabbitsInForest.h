#pragma once
#include "Common.h"

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> answers = {1, 1, 2};
    EXPECT_EQ(solution.numRabbits(answers), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> answers = {10, 10, 10};
    EXPECT_EQ(solution.numRabbits(answers), 11);
}