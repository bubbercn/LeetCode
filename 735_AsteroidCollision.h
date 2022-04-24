#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> result;
        for (auto value : asteroids)
        {
            if (value > 0)
            {
                result.emplace_back(value);
            }
            else
            {
                bool add = true;
                while (!result.empty() && result.back() > 0)
                {
                    if (-value > result.back())
                    {
                        result.pop_back();
                        add = true;
                    }
                    else if (-value == result.back())
                    {
                        result.pop_back();
                        add = false;
                        break;
                    }
                    else
                    {
                        add = false;
                        break;
                    }
                }
                if (add)
                    result.emplace_back(value);
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