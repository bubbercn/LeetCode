#pragma once
#include "Common.h"

class Solution
{
public:
    string shortestSuperstring(vector<string> &words)
    {
        int n = words.size();
        vector<vector<int>> overlap(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                overlap[i][j] = getOverlap(words[i], words[j]);
            }
        }
        int m = (1 << n);
        vector<vector<int>> select(m, vector<int>(n, -1));
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    int curMask = i;
                    curMask ^= (1 << j);
                    auto max = 0;
                    for (int k = n - 1; k >= 0; k--)
                    {
                        if (curMask & (1 << k))
                        {
                            int temp = dp[curMask][k] + overlap[k][j];
                            if (temp == max)
                            {
                                if (select[i][j] == -1)
                                    select[i][j] = k;
                            }
                            else if (temp > max)
                            {
                                max = temp;
                                select[i][j] = k;
                            }
                        }
                    }
                    dp[i][j] = max;
                }
            }
        }

        int mask = m - 1;
        int max = 0;
        int last = -1;
        vector<bool> visited(n, false);
        deque<int> order;
        for (int i = n - 1; i >= 0; i--)
        {
            if (dp[mask][i] == max)
            {
                if (last == -1)
                {
                    last = i;
                }
            }
            else if (dp[mask][i] > max)
            {
                max = dp[mask][i];
                last = i;
            }
        }
        order.emplace_front(last);
        visited[last] = true;
        while (mask > 0)
        {
            int lastlast = last;
            last = select[mask][last];
            if (last == -1)
                break;
            order.emplace_front(last);
            visited[last] = true;
            mask ^= (1 << lastlast);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (!visited[i])
                order.emplace_front(i);
        }
        string result = words[order[0]];
        for (int i = 1; i < order.size(); i++)
        {
            string &word = words[order[i]];
            int temp = overlap[order[i - 1]][order[i]];
            result += word.substr(temp, word.length() - temp);
        }
        return result;
    }

private:
    int getOverlap(string_view s1, string_view s2)
    {
        int overlap = min(s1.length(), s2.length());
        while (overlap > 0)
        {
            if (s1.substr(s1.length() - overlap) == s2.substr(0, overlap))
                return overlap;
            overlap--;
        }
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> words = {"alex", "loves", "leetcode"};
    EXPECT_EQ(solution.shortestSuperstring(words), "alexlovesleetcode");
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"catg", "ctaagt", "gcta", "ttca", "atgcatc"};
    EXPECT_EQ(solution.shortestSuperstring(words), "gctaagttcatgcatc");
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<string> words = {"xas", "nxv", "ownx", "xvf", "vfv"};
    EXPECT_EQ(solution.shortestSuperstring(words), "xasownxvfv");
}