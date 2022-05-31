#pragma once
#include "Common.h"

class Solution
{
public:
    int reachNumber(int target)
    {
        target = abs(target);
        int result = -1;
        int m = 0;
        do
        {
            result++;
            m = (result + 1) * result / 2;
        } while (m < target || (target & 1) != (m & 1));

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
    EXPECT_EQ(solution.reachNumber(2), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.reachNumber(3), 2);
}

TEST_F(LeetCodeTest, Case1)
{
    EXPECT_EQ(solution.reachNumber(1000000000), 44723);
}