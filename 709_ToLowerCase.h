#pragma once
#include "Common.h"

class Solution
{
public:
    string toLowerCase(string_view s)
    {
        string result(s);
        for (auto& c : result)
        {
            if (c >= 'A' && c <= 'Z')
                c = 'a' + c - 'A';
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.toLowerCase("Hello"), "hello");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.toLowerCase("here"), "here");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.toLowerCase("LOVELY"), "lovely");
}