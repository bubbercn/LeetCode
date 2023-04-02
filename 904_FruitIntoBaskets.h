#pragma once
#include "Common.h"

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> lookup;
        queue<unordered_map<int, int>::const_iterator> q;
        int result = 0;
        int sum = 0;
        for (auto type : fruits)
        {
            sum++;
            if (auto it = lookup.find(type); it != lookup.end())
            {
                it->second++;
            }
            else
            {
                q.emplace(lookup.emplace(type, 1).first);
            }
            if (q.size() > 2)
            {
                sum -= q.front()->second;
                lookup.erase(q.front());
                q.pop();
            }
            result = max(result, sum);
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
    vector<int> fruits = {1, 2, 1};
    EXPECT_EQ(solution.totalFruit(fruits), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> fruits = {0, 1, 2, 2};
    EXPECT_EQ(solution.totalFruit(fruits), 3);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> fruits = {1, 2, 3, 2, 2};
    EXPECT_EQ(solution.totalFruit(fruits), 4);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    EXPECT_EQ(solution.totalFruit(fruits), 5);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<int> fruits = {1, 0, 1, 4, 1, 4, 1, 2, 3};
    EXPECT_EQ(solution.totalFruit(fruits), 5);
}