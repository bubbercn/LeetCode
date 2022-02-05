#pragma once
#include "Common.h"

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        vector<int> scores;
        for (auto &op : ops)
        {
            if (op == "+")
            {
                scores.emplace_back(*scores.rbegin() + *(++scores.rbegin()));
            }
            else if (op == "D")
            {
                scores.emplace_back(*scores.rbegin() * 2);
            }
            else if (op == "C")
            {
                scores.resize(scores.size() - 1);
            }
            else
            {
                scores.emplace_back(stoi(op));
            }
        }
        return accumulate(scores.begin(), scores.end(), 0);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> ops = {"5", "2", "C", "D", "+"};
    EXPECT_EQ(solution.calPoints(ops), 30);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> ops = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    EXPECT_EQ(solution.calPoints(ops), 27);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> ops = {"1"};
    EXPECT_EQ(solution.calPoints(ops), 1);
}
