#pragma once
#include "Common.h"

class RecentCounter
{
public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        while (!data.empty() and data.front() < t - 3000)
        {
            data.pop();
        }
        data.emplace(t);
        return data.size();
    }

private:
    queue<int> data;
};

class LeetCodeTest : public testing::Test
{
};

TEST_F(LeetCodeTest, Example1)
{
    RecentCounter recentCounter;
    EXPECT_EQ(recentCounter.ping(1), 1);    // requests = [1], range is [-2999,1], return 1
    EXPECT_EQ(recentCounter.ping(100), 2);  // requests = [1, 100], range is [-2900,100], return 2
    EXPECT_EQ(recentCounter.ping(3001), 3); // requests = [1, 100, 3001], range is [1,3001], return 3
    EXPECT_EQ(recentCounter.ping(3002), 3); // requests = [1, 100, 3001, 3002], range is [2,3002], return 3
}