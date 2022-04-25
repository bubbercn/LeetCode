#pragma once
#include "Common.h"

class Solution
{
public:
    int monotoneIncreasingDigits(int n)
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
    EXPECT_EQ(solution.monotoneIncreasingDigits(10), 9);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.monotoneIncreasingDigits(1234), 1234);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.monotoneIncreasingDigits(332), 299);
}