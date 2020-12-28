#pragma once
#include "Common.h"

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        auto si = s.begin();
        auto ti = t.begin();

        while (si != s.end() && ti != t.end())
        {
            if (*si == *ti)
            {
                si++;
            }
            ti++;
        }

        return si == s.end();
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.isSubsequence("abc", "ahbgdc"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.isSubsequence("axc", "ahbgdc"), false);
}
