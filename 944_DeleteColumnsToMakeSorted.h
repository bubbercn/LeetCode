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
        for (int j = 0; j < n; j++)
        {
            for (int i = 1; i < m; i++)
            {
                if (strs[i][j] < strs[i - 1][j])
                {
                    result++;
                    break;
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
    vector<string> strs = {"cba", "daf", "ghi"};
    EXPECT_EQ(solution.minDeletionSize(strs), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> strs = {"a", "b"};
    EXPECT_EQ(solution.minDeletionSize(strs), 0);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> strs = {"zyx", "wvu", "tsr"};
    EXPECT_EQ(solution.minDeletionSize(strs), 3);
}
