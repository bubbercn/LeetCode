#pragma once
#include "Common.h"

class Solution
{
public:
    int superEggDrop(int k, int n)
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
    EXPECT_EQ(solution.superEggDrop(1, 2), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.superEggDrop(2, 6), 3);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.superEggDrop(3, 14), 4);
}
