#pragma once
#include "Common.h"

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
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
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    EXPECT_EQ(solution.carFleet(12, position, speed), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> position = {3};
    vector<int> speed = {3};
    EXPECT_EQ(solution.carFleet(10, position, speed), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> position = {0, 2, 4};
    vector<int> speed = {4, 2, 1};
    EXPECT_EQ(solution.carFleet(100, position, speed), 1);
}