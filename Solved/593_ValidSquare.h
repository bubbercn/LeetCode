#pragma once
#include "Common.h"

class Solution
{
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        set<vector<int>> p = {p1, p2, p3, p4};
        if (p.size() != 4)
            return false;

        vector<int> distances;
        distances.emplace_back(distance(p1, p2));
        distances.emplace_back(distance(p1, p3));
        distances.emplace_back(distance(p1, p4));
        distances.emplace_back(distance(p2, p3));
        distances.emplace_back(distance(p2, p4));
        distances.emplace_back(distance(p3, p4));
        sort(distances.begin(), distances.end());
        if (distances[0] != distances[1] || distances[0] != distances[2] || distances[0] != distances[3])
            return false;

        if (distances[0] * 2 != distances[4] || distances[4] != distances[5])
            return false;

        return true;
    }

private:
    int distance(vector<int> &p1, vector<int> &p2)
    {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> p1 = {0, 0}, p2 = {1, 1}, p3 = {1, 0}, p4 = {0, 1};
    EXPECT_EQ(solution.validSquare(p1, p2, p3, p4), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> p1 = {0, 0}, p2 = {1, 1}, p3 = {1, 0}, p4 = {0, 12};
    EXPECT_EQ(solution.validSquare(p1, p2, p3, p4), false);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> p1 = {1, 0}, p2 = {-1, 0}, p3 = {0, 1}, p4 = {0, -1};
    EXPECT_EQ(solution.validSquare(p1, p2, p3, p4), true);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> p1 = {0, 0}, p2 = {0, 0}, p3 = {0, 0}, p4 = {0, 0};
    EXPECT_EQ(solution.validSquare(p1, p2, p3, p4), false);
}