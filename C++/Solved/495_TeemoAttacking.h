#pragma once
#include "Common.h"

class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int limit = timeSeries.size() - 1;
        int i = 0;
        int result = 0;
        while (i < limit)
        {
            result += min(timeSeries[i + 1] - timeSeries[i], duration); 
            i++;
        }
        return result + duration;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> timeSeries = {1, 4};
    EXPECT_EQ(solution.findPoisonedDuration(timeSeries, 2), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> timeSeries = {1, 2};
    EXPECT_EQ(solution.findPoisonedDuration(timeSeries, 2), 3);
}