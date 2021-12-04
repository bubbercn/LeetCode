#pragma once
#include "Common.h"

class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
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
    vector<vector<int>> courses = {
        {100, 200},
        {200, 1300},
        {1000, 1250},
        {2000, 3200},
    };
    EXPECT_EQ(solution.scheduleCourse(courses), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> courses = {
        {1, 2},
    };
    EXPECT_EQ(solution.scheduleCourse(courses), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> courses = {
        {3, 2},
        {4, 3},
    };
    EXPECT_EQ(solution.scheduleCourse(courses), 0);
}