#pragma once
#include "Common.h"

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
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
    vector<int> people = {1, 2};
    EXPECT_EQ(solution.numRescueBoats(people, 3), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> people = {3, 2, 2, 1};
    EXPECT_EQ(solution.numRescueBoats(people, 3), 3);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> people = {3, 5, 3, 4};
    EXPECT_EQ(solution.numRescueBoats(people, 5), 4);
}