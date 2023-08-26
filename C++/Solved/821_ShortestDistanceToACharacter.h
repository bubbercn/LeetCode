#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> shortestToChar(string_view s, char c)
    {
        int n = s.length();
        vector<int> result(n, numeric_limits<int>::max());
        int dis = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == c)
            {
                dis = 0;
                result[i] = 0;
            }
            else if (dis != -1)
            {
                result[i] = ++dis;
            }
        }
        dis = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == c)
            {
                dis = 0;
            }
            else if (dis != -1)
            {
                result[i] = min(result[i], ++dis);
            }
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
    vector<int> output = {3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0};
    EXPECT_EQ(solution.shortestToChar("loveleetcode", 'e'), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {3, 2, 1, 0};
    EXPECT_EQ(solution.shortestToChar("aaab", 'b'), output);
}