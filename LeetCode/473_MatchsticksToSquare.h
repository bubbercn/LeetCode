#pragma once
#include "Common.h"

class Solution
{
public:
    bool makesquare(vector<int> &matchsticks)
    {
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        long totalSum = accumulate(matchsticks.begin(), matchsticks.end(), 0l);
        if (totalSum % 4 != 0)
            return false;

        long targetSum = totalSum / 4;
        selectedIndex.assign(matchsticks.size(), false);
        for (int i = 0; i < 4; i++)
        {
            if (!dfs(matchsticks, targetSum))
                return false;
        }
        return true;
    }

private:
    vector<bool> selectedIndex;
    bool dfs(vector<int> &matchsticks, long targetSum)
    {
        for (int i = 0; i < matchsticks.size(); i++)
        {
            if (selectedIndex[i] || matchsticks[i] > targetSum)
                continue;

            selectedIndex[i] = true;

            if (matchsticks[i] == targetSum)
            {
                return true;
            }

            if (dfs(matchsticks, targetSum - matchsticks[i]))
            {
                return true;
            }
            else
            {
                selectedIndex[i] = false;
            }
        }
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> matchsticks = {1, 1, 2, 2, 2};
    EXPECT_EQ(solution.makesquare(matchsticks), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> matchsticks = {3, 3, 3, 3, 4};
    EXPECT_EQ(solution.makesquare(matchsticks), false);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> matchsticks = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 5, 4, 3, 2, 1};
    EXPECT_EQ(solution.makesquare(matchsticks), false);
}