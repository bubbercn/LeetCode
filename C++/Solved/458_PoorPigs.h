#pragma once
#include "Common.h"

class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int times = minutesToTest / minutesToDie;
        int result = ceil(log2(buckets) / log2(times + 1));
        return result;
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