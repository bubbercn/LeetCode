#pragma once
#include "Common.h"

class Solution
{
public:
    string countOfAtoms(string_view formula)
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
    EXPECT_EQ(solution.countOfAtoms("H20"), "H20");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.countOfAtoms("Mg(OH)2"), "H2MgO2");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.countOfAtoms("K4(ON(SO3)2)2"), "K4N2O14S4");
}