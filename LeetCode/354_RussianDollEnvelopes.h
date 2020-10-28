#pragma once
#include "Common.h"

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end());
        int max = 0;
        stack<vector<int>> increasingSequence;
        for (auto it = envelopes.begin(); it != envelopes.end();)
        {
            auto curIt = it;
            map<int, vector<vector<int>>::const_iterator> lookup;
            while (it != envelopes.end() && it->at(0) == curIt->at(0))
            {
                lookup.emplace(it->at(1), it);
                it++;
            }
            auto i = lookup.begin();
            while (!increasingSequence.empty() && (i = lookup.upper_bound(increasingSequence.top()[1])) == lookup.end())
            {
                increasingSequence.pop();
            }
            if (i != lookup.end())
            {
                increasingSequence.emplace(*(i->second));
            }
            else
            {
                increasingSequence.emplace(*curIt);
            }
            max = ::max(max, static_cast<int>(increasingSequence.size()));
        }
        return max;
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