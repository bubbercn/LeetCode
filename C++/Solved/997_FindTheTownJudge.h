#pragma once
#include "Common.h"

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> trustCount(n + 1);
        vector<bool> isTuester(n + 1);
        for (auto &pair : trust)
        {
            isTuester[pair[0]] = true;
            trustCount[pair[1]]++;
        }
        int result = -1;
        for (int i = 1; i <= n; i++)
        {
            if (trustCount[i] == n - 1 and !isTuester[i])
            {
                if (result == -1)
                {
                    result = i;
                }
                else
                {
                    return -1;
                }
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
    vector<vector<int>> trust = {
        {1, 2},
    };
    EXPECT_EQ(solution.findJudge(2, trust), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> trust = {
        {1, 3},
        {2, 3},
    };
    EXPECT_EQ(solution.findJudge(3, trust), 3);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> trust = {
        {1, 3},
        {2, 3},
        {3, 1},
    };
    EXPECT_EQ(solution.findJudge(3, trust), -1);
}
