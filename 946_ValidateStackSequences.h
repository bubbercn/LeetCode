#pragma once
#include "Common.h"

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};
    EXPECT_EQ(solution.validateStackSequences(pushed, popped), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 3, 5, 1, 2};
    EXPECT_EQ(solution.validateStackSequences(pushed, popped), false);
}