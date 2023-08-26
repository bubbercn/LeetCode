#pragma once
#include "Common.h"

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int m = strs.size();
        int n = strs[0].length();
        int result = 0;
        vector<int> ok(m);
        for (int j = 0; j < n; j++)
        {
            bool stop = true;
            vector<int> bak = ok;
            for (int i = 1; i < m; i++)
            {
                if (ok[i])
                    continue;
                if (strs[i][j] < strs[i - 1][j])
                {
                    result++;
                    stop = false;
                    ok.swap(bak);
                    break;
                }
                else if (strs[i][j] > strs[i - 1][j])
                {
                    ok[i] = true;
                }
                else
                {
                    stop = false;
                }
            }
            if (stop)
                return result;
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
    vector<string> strs = {"ca", "bb", "ac"};
    EXPECT_EQ(solution.minDeletionSize(strs), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> strs = {"xc", "yb", "za"};
    EXPECT_EQ(solution.minDeletionSize(strs), 0);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> strs = {"zyx", "wvu", "tsr"};
    EXPECT_EQ(solution.minDeletionSize(strs), 3);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<string> strs = {"xga", "xfb", "yfa"};
    EXPECT_EQ(solution.minDeletionSize(strs), 1);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<string> strs = {"vdy", "vei", "zvc", "zld"};
    EXPECT_EQ(solution.minDeletionSize(strs), 2);
}