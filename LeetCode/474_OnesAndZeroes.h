#pragma once
#include "Common.h"

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
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
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    EXPECT_EQ(solution.findMaxForm(strs, 5, 3), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> strs = {"10", "0", "1"};
    EXPECT_EQ(solution.findMaxForm(strs, 1, 1), 2);
}