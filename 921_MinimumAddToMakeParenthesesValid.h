#pragma once
#include "Common.h"

class Solution
{
public:
    int minAddToMakeValid(string_view s)
    {
        int result = 0;
        int left = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                left++;
            }
            else
            {
                if (left > 0)
                {
                    left--;
                }
                else
                {
                    result++;
                }
            }
        }
        return result + left;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.minAddToMakeValid("())"), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.minAddToMakeValid("((("), 3);
}