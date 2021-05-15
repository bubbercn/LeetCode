#pragma once
#include "Common.h"

class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
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
    EXPECT_EQ(solution.poorPigs(1000, 15, 60), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.poorPigs(4, 15, 15), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.poorPigs(4, 15, 30), 2);
}