#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> movesToStamp(string_view stamp, string_view target)
    {
        int n = stamp.length();
        int m = target.length();
        vector<int> match(m - n + 1);
        vector<list<int>> lookup(m);
        queue<int> q;
        vector<int> result;
        for (int i = 0; i <= m - n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (stamp[j] == target[i + j])
                {
                    match[i]++;
                    if (match[i] == n)
                        q.emplace(i);
                }
                else
                {
                    lookup[i + j].emplace_back(i);
                }
            }
        }
        unordered_set<int> matched;
        while (!q.empty() and matched.size() < m)
        {
            int begin = q.front();
            q.pop();
            result.emplace_back(begin);
            for (int i = 0; i < n; i++)
            {
                int temp = begin + i;
                if (matched.emplace(temp).second)
                {
                    for (auto j : lookup[temp])
                    {
                        match[j]++;
                        if (match[j] == n)
                        {
                            q.emplace(j);
                        }
                    }
                }
            }
        }
        if (matched.size() < m)
            return {};
        reverse(result.begin(), result.end());
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
    vector<int> output = {0, 2};
    EXPECT_EQ(solution.movesToStamp("abc", "ababc"), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {3, 0, 1};
    EXPECT_EQ(solution.movesToStamp("abca", "aabcaca"), output);
}