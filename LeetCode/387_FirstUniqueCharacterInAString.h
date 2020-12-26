#pragma once
#include "Common.h"

class Solution
{
public:
    int firstUniqChar(const string &s)
    {
        vector<int> lookup(26, -1);
        for (int i = 0; i < s.length(); i++)
        {
            int index = s[i] - 'a';
            if (lookup[index] == -1)
            {
                lookup[index] = i;
            }
            else
            {
                lookup[index] = INT_MAX;
            }
        }
        int result = INT_MAX;
        for (auto i : lookup)
        {
            if (i == -1)
                continue;
            result = min(result, i);
        }
        return result == INT_MAX ? -1 : result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.firstUniqChar("leetcode"), 0);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.firstUniqChar("loveleetcode"), 2);
}