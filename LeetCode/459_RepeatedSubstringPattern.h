#pragma once
#include "Common.h"

class Solution
{
public:
    bool repeatedSubstringPattern(const string& s)
    {
        for (size_t patterLength = 1; patterLength <= s.length() / 2; patterLength++)
        {
            if (s.length() % patterLength != 0)
                continue;
            string pattern = s.substr(0, patterLength);
            bool ok = true;
            for (size_t i = patterLength; i < s.length(); i += patterLength)
            {
                if (pattern != s.substr(i, patterLength))
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                return true;
        }
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
    EXPECT_EQ(solution.repeatedSubstringPattern("abab"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.repeatedSubstringPattern("aba"), false);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.repeatedSubstringPattern("abcabcabcabc"), true);
}
