#pragma once
#include "Common.h"

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> lookup;
        for (int i = 0; i < answers.size(); i++)
        {
            lookup[answers[i]]++;
        }
        int result = 0;
        for (auto [otherCount, answerCount] : lookup)
        {
            int temp = otherCount + 1;
            result += answerCount % temp ? (answerCount / temp + 1) * temp : answerCount / temp * temp;
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
    vector<int> answers = {1, 1, 2};
    EXPECT_EQ(solution.numRabbits(answers), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> answers = {10, 10, 10};
    EXPECT_EQ(solution.numRabbits(answers), 11);
}