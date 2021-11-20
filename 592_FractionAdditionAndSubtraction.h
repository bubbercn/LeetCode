#pragma once
#include "Common.h"

class Solution
{
public:
    string fractionAddition(string_view expression)
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
    EXPECT_EQ(solution.fractionAddition("-1/2+1/2"), "0/1");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.fractionAddition("-1/2+1/2+1/3"), "1/3");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.fractionAddition("1/3-1/2"), "-1/6");
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.fractionAddition("5/3+1/3"), "2/1");
}