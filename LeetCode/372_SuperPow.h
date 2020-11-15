#pragma once
#include "Common.h"

class Solution
{
public:
    int superPow(int a, vector<int> &b)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.superPow(2, vector<int>{3}), 8);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.superPow(2, vector<int>{1, 0}), 1024);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.superPow(1, vector<int>{4, 3, 3, 8, 5, 2}), 1);
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.superPow(2147483647, vector<int>{2, 0, 0}), 1198);
}