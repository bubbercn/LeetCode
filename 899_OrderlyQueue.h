#pragma once
#include "Common.h"

class Solution
{
public:
    string orderlyQueue(string_view s, int k)
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
    EXPECT_EQ(solution.orderlyQueue("cba", 1), "acb");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.orderlyQueue("baaca", 3), "aaabc");
}