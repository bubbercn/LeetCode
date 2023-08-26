#pragma once
#include "Common.h"

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), [](const auto &a, const auto &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        int maxLength = 0;
        set<int> increasingSequence;

        for (const auto& envelope : envelopes)
        {
            auto it = increasingSequence.lower_bound(envelope[1]);
            if (it != increasingSequence.end())
            {
                it = increasingSequence.erase(it);
            }
            increasingSequence.emplace_hint(it, envelope[1]);
            maxLength = max(maxLength, static_cast<int>(increasingSequence.size()));
        }
        return maxLength;
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

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> input = {{30, 50}, {12, 2}, {3, 4}, {12, 15}};
    EXPECT_EQ(solution.maxEnvelopes(input), 3);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<vector<int>> input = {{46, 89}, {50, 53}, {52, 68}, {72, 45}, {77, 81}};
    EXPECT_EQ(solution.maxEnvelopes(input), 3);
}