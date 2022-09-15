#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> ambiguousCoordinates(string_view s)
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
    vector<string> output = {"(1, 2.3)", "(1, 23)", "(1.2, 3)", "(12, 3)"};
    EXPECT_EQ(solution.ambiguousCoordinates("(123)"), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> output = {"(0, 1.23)", "(0, 12.3)", "(0, 123)", "(0.1, 2.3)", "(0.1, 23)", "(0.12, 3)"};
    EXPECT_EQ(solution.ambiguousCoordinates("(0123)"), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> output = {"(0, 0.011)", "(0.001, 1)"};
    EXPECT_EQ(solution.ambiguousCoordinates("(00011)"), output);
}