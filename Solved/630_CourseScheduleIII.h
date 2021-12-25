#pragma once
#include "Common.h"

class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {

        sort(courses.begin(), courses.end(), [](const vector<int> &v1, const vector<int> &v2)
             { return v1[1] < v2[1]; });

        priority_queue<int, vector<int>> maxHeap;

        int timeSpent = 0;
        for (int i = 0; i < courses.size(); ++i)
        {
            if (timeSpent + courses[i][0] <= courses[i][1])
            {
                maxHeap.emplace(courses[i][0]);
                timeSpent += courses[i][0];
            }
            else if (!maxHeap.empty() && maxHeap.top() > courses[i][0])
            {
                // 修正时间： 缩短
                timeSpent += courses[i][0] - maxHeap.top();
                maxHeap.pop();
                maxHeap.emplace(courses[i][0]);
            }
        }

        return maxHeap.size();
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

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> courses = {
        {2, 5},
        {2, 19},
        {1, 8},
        {1, 3},
    };
    EXPECT_EQ(solution.scheduleCourse(courses), 4);
}