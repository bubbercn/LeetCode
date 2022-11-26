#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string_view s)
    {
        vector<vector<int>> result;
        int n = s.length();
        int begin = -1;
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || s[i] != s[i - 1])
            {
                if (begin != string::npos && i - begin >= 3)
                {
                    result.push_back({begin, i - 1});
                }
                begin = i;
            }
        }
        if (begin != -1 && n - begin >= 3)
        {
            result.push_back({begin, n - 1});
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
    vector<vector<int>> output = {
        {3, 6},
    };
    EXPECT_EQ(solution.largeGroupPositions("abbxxxxzzy"), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> output = {};
    EXPECT_EQ(solution.largeGroupPositions("abc"), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> output = {
        {3, 5},
        {6, 9},
        {12, 14},
    };
    EXPECT_EQ(solution.largeGroupPositions("abcdddeeeeaabbbcd"), output);
}