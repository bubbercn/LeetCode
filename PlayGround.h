#pragma once
#include "Common.h"

class Solution
{
public:
    int XXX()
    {
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.XXX(), 0);
}
