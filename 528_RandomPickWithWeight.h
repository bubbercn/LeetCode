#pragma once
#include "Common.h"

class Solution
{
public:
    Solution(vector<int> &w)
    {
        boundaries.assign(w.size(), 0);
        sum = 0;
        for (int i = 0; i < w.size(); i++)
        {
            sum += w[i];
            boundaries[i] = sum;
        }
    }

    int pickIndex()
    {
        int r = rand() % sum;
        auto it = upper_bound(boundaries.begin(), boundaries.end(), r);
        return distance(boundaries.begin(), it);
    }

private:
    int sum;
    vector<int> boundaries;
};

class LeetCodeTest : public testing::Test
{
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> w = {1};
    Solution solution(w);
    EXPECT_EQ(solution.pickIndex(), 0);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> w = {1, 3};
    Solution solution(w);
    solution.pickIndex();
    solution.pickIndex();
    solution.pickIndex();
    solution.pickIndex();
}