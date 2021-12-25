#pragma once
#include "Common.h"

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& v1, const vector<int>& v2)
        {
            if (v1[1] == v2[1])
                return v1[0] > v2[0];
            return v1[1] < v2[1];
        });
        int result = 1;
        int last = pairs[0][1];
        for (int i = 1; i < pairs.size(); i++)
        {
            if (pairs[i][0] > last)
            {
                result++;
                last = pairs[i][1];
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
    vector<vector<int>> pairs = {
        {1, 2},
        {2, 3},
        {3, 4},
    };
    EXPECT_EQ(solution.findLongestChain(pairs), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> pairs = {
        {1, 2},
        {7, 8},
        {4, 5},
    };
    EXPECT_EQ(solution.findLongestChain(pairs), 3);
}