#pragma once
#include "Common.h"

class Solution
{
public:
    bool checkValidString(string_view s)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.checkValidString("()"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.checkValidString("(*)"), true);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.checkValidString("())"), true);
}
