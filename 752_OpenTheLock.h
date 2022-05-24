#pragma once
#include "Common.h"

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
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
    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    EXPECT_EQ(solution.openLock(deadends, "0202"), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> deadends = {"8888"};
    EXPECT_EQ(solution.openLock(deadends, "0009"), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> deadends = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    EXPECT_EQ(solution.openLock(deadends, "8888"), -1);
}