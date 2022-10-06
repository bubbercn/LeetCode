#pragma once
#include "Common.h"

class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> ages = {16, 16};
    EXPECT_EQ(solution.numFriendRequests(ages), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> ages = {16, 17, 18};
    EXPECT_EQ(solution.numFriendRequests(ages), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> ages = {20, 30, 100, 110, 120};
    EXPECT_EQ(solution.numFriendRequests(ages), 3);
}