#pragma once
#include "Common.h"

class Solution
{
public:
    int minimumDeleteSum(string_view s1, string_view s2)
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
    EXPECT_EQ(solution.minimumDeleteSum("sea", "eat"), 231);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.minimumDeleteSum("delete", "leet"), 403);
}
