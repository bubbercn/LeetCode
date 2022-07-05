#pragma once
#include "Common.h"

class Solution
{
public:
    bool canTransform(string_view start, string_view end)
    {
        int n = start.length();
        string s, t;
        vector<int> s_pos, t_pos;
        for (int i = 0; i < n; i++)
        {
            if (start[i] != 'X')
            {
                s.push_back(start[i]);
                s_pos.push_back(i);
            }
            if (end[i] != 'X')
            {
                t.push_back(end[i]);
                t_pos.push_back(i);
            }
        }
        if (s != t)
            return false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'L' && s_pos[i] < t_pos[i])
                return false;
            if (s[i] == 'R' && s_pos[i] > t_pos[i])
                return false;
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
    EXPECT_EQ(solution.canTransform("RXXLRXRXL", "XRLXXRRLX"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.canTransform("X", "L"), false);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.canTransform("LLR", "RRL"), false);
}

TEST_F(LeetCodeTest, Failure2)
{
    EXPECT_EQ(solution.canTransform("LXXLXRLXXL", "XLLXRXLXLX"), false);
}

TEST_F(LeetCodeTest, Failure3)
{
    EXPECT_EQ(solution.canTransform("XXXXXLXXXX", "LXXXXXXXXX"), true);
}

TEST_F(LeetCodeTest, Failure4)
{
    EXPECT_EQ(solution.canTransform("XLXRRXXRXX", "LXXXXXXRRR"), true);
}