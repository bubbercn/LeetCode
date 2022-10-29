#pragma once
#include "Common.h"

class Solution
{
public:
    string maskPII(string_view s)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.maskPII("LeetCode@LeetCode.com"), "l*****e@leetcode.com");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.maskPII("AB@qq.com"), "a*****b@qq.com");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.maskPII("1(234)567-890"), "***-***-7890");
}