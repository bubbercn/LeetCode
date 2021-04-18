#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        auto cmp = [](const vector<int> &v1, const vector<int> &v2) {
            return v1[0] < v2[0];
        };
        map<vector<int>, int, decltype(cmp)> lookup(cmp);
        for (int i = 0; i < intervals.size(); i++)
        {
            lookup.emplace(intervals[i], i);
        }
        vector<int> result;
        for (int i = 0; i < intervals.size(); i++)
        {
            auto it = lookup.lower_bound(vector<int>{intervals[i][1], -1});
            if (it != lookup.end())
            {
                result.emplace_back(it->second);
            }
            else
            {
                result.emplace_back(-1);
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
    vector<vector<int>> intervals = {
        {1, 2},
    };
    vector<int> output = {-1};
    EXPECT_EQ(solution.findRightInterval(intervals), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> intervals = {
        {3, 4},
        {2, 3},
        {1, 2},
    };
    vector<int> output = {-1, 0, 1};
    EXPECT_EQ(solution.findRightInterval(intervals), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> intervals = {
        {1, 4},
        {2, 3},
        {3, 4},
    };
    vector<int> output = {-1, 2, -1};
    EXPECT_EQ(solution.findRightInterval(intervals), output);
}