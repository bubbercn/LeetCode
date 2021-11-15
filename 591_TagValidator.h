#pragma once
#include "Common.h"

class Solution
{
public:
    bool isValid(string_view code)
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
    EXPECT_EQ(solution.isValid("<DIV>This is the first line <![CDATA[<div>]]></DIV>"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.isValid("<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>"), true);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.isValid("<A>  <B> </A>   </B>"), false);
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.isValid("<DIV>  div tag is not closed  <DIV>"), false);
}