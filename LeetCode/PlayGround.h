#pragma once
#include "Common.h"

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        double sum = 0;
        double delta2 = 0;
        priority_queue<double, vector<double>, greater<double>> delta1;
        for (auto& c : classes)
        {
            double temp = c[0] / c[1];
            delta2 = max(delta2, (c[0] + 2) / (c[1] + 2) - temp);
            double delta = (c[0] + 1) / (c[1] + 1) - temp;
            if (delta1.size() >= 2 && delta > delta1.top())
                delta1.pop();
            delta1.emplace(delta);
            sum += temp;
        }
        double delta = 0;
        while (!delta1.empty())
        {
            delta += delta1.top();
            delta1.pop();
        }
        delta = max(delta2, delta);
        sum += delta;
        return sum / classes.size();
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> classes = {{1,2},{3,5},{2,2}};
    EXPECT_EQ(solution.maxAverageRatio(classes, 2), true);
}

// TEST_F(LeetCodeTest, Example2)
// {
//     EXPECT_EQ(solution.areAlmostEqual("attack", "defend"), false);
// }

// TEST_F(LeetCodeTest, Example3)
// {
//     EXPECT_EQ(solution.areAlmostEqual("kelb", "kelb"), true);
// }

// TEST_F(LeetCodeTest, Example4)
// {
//     EXPECT_EQ(solution.areAlmostEqual("abcd", "dcba"), false);
// }

// TEST_F(LeetCodeTest, Faulre1)
// {
//     EXPECT_EQ(solution.areAlmostEqual("abc", "dbe"), false);
// }