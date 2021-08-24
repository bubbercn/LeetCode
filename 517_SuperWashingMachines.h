#pragma once
#include "Common.h"

class Solution
{
public:
    int findMinMoves(vector<int> &machines)
    {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if (sum % machines.size())
            return -1;

        int avg = sum / machines.size();
        int leftSum = 0;
        int result = 0;
        for (int i = 0; i < machines.size(); i++)
        {
            result = max(result, machines[i] - avg);
            if (i != machines.size() - 1)
            {
                leftSum += machines[i];
                result = max(result, abs(leftSum - (i + 1) * avg));
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
    vector<int> machines = {1, 0, 5};
    EXPECT_EQ(solution.findMinMoves(machines), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> machines = {0, 3, 0};
    EXPECT_EQ(solution.findMinMoves(machines), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> machines = {0, 2, 0};
    EXPECT_EQ(solution.findMinMoves(machines), -1);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> machines = {9, 1, 8, 8, 9};
    EXPECT_EQ(solution.findMinMoves(machines), 4);
}
