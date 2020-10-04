#pragma once
#include "Common.h"

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.isValidSerialization("1,#"), false);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.isValidSerialization("9,#,#,1"), false);
}