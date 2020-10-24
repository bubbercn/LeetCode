#pragma once
#include "Common.h"

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end());

        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> input = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    EXPECT_EQ(solution.maxEnvelopes(input), 3);
}