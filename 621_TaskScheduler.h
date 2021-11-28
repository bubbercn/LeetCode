#pragma once
#include "Common.h"

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
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
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    EXPECT_EQ(solution.leastInterval(tasks, 2), 8);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    EXPECT_EQ(solution.leastInterval(tasks, 0), 6);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<char> tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    EXPECT_EQ(solution.leastInterval(tasks, 2), 16);
}