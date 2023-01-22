#pragma once
#include "Common.h"

class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        vector<int> persons;
        for (int i = 0; i < seats.size(); i++)
        {
            if (seats[i])
                persons.emplace_back(i);
        }
        int result = persons[0];
        int n = seats.size();
        for (int i = 1; i < persons.size(); i++)
        {
            result = max((persons[i] - persons[i - 1]) / 2, result);
        }
        result = max(result, n - 1 - *persons.rbegin());
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
    vector<int> seats = {1, 0, 0, 0, 1, 0, 1};
    EXPECT_EQ(solution.maxDistToClosest(seats), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> seats = {1, 0, 0, 0};
    EXPECT_EQ(solution.maxDistToClosest(seats), 3);
}