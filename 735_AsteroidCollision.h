#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> asteroids = {5, 10, -5};
    vector<int> output = {5, 10};
    EXPECT_EQ(solution.asteroidCollision(asteroids), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> asteroids = {8, -8};
    vector<int> output = {};
    EXPECT_EQ(solution.asteroidCollision(asteroids), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> asteroids = {10, 2, -5};
    vector<int> output = {10};
    EXPECT_EQ(solution.asteroidCollision(asteroids), output);
}