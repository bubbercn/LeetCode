#pragma once
#include "Common.h"

class Solution
{
public:
    int flipgame(vector<int> &fronts, vector<int> &backs)
    {
        vector<int> cards;
        unordered_set<int> ban;
        for (int i = 0; i < fronts.size(); i++)
        {
            if (fronts[i] == backs[i])
            {
                ban.emplace(fronts[i]);
            }
        }

        int result = numeric_limits<int>::max();
        for (int i = 0; i < fronts.size(); i++)
        {
            if (ban.count(fronts[i]) == 0)
            {
                result = min(result, fronts[i]);
            }
        }
        for (int i = 0; i < backs.size(); i++)
        {
            if (ban.count(backs[i]) == 0)
            {
                result = min(result, backs[i]);
            }
        }

        return result == numeric_limits<int>::max() ? 0 : result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> fronts = {1, 2, 4, 4, 7};
    vector<int> backs = {1, 3, 4, 1, 3};
    EXPECT_EQ(solution.flipgame(fronts, backs), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> fronts = {1};
    vector<int> backs = {1};
    EXPECT_EQ(solution.flipgame(fronts, backs), 0);
}