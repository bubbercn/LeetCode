#pragma once
#include "Common.h"

class Solution
{
public:
    bool checkRecord(string_view s)
    {
        int A = 0;
        int L = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A') 
            {
                L = 0;
                if (++A >= 2)
                    return false;
            }
            if (s[i] == 'L' && (L == 0 || s[i - 1] == 'L') && ++L >= 3)
            {
                return false;
            }
            if (s[i] == 'P')
                L = 0;
        }
        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.checkRecord("PPALLP"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.checkRecord("PPALLL"), false);
}