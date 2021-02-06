#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](const vector<int> &left, const vector<int> &right) {
            return left[0] == right[0] ? left[1] < right[1] : left[0] < right[0];
        });
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
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> output = {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};
    EXPECT_EQ(solution.reconstructQueue(people), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> people = {{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}};
    vector<vector<int>> output = {{4, 0}, {5, 0}, {2, 2}, {3, 2}, {1, 4}, {6, 0}};
    EXPECT_EQ(solution.reconstructQueue(people), output);
}