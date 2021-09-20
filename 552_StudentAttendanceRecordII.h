#pragma once
#include "Common.h"

class Solution
{
public:
    int checkRecord(int n)
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
    EXPECT_EQ(solution.checkRecord(2), 9);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.checkRecord(1), 3);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.checkRecord(10101), 183236316);
}