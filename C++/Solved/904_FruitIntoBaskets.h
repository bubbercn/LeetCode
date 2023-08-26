#pragma once
#include "Common.h"

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> lookup;
        lookup[fruits[0]]++;
        int result = 0;
        int left = 0;
        int right = 0;
        while (true)
        {
            if (lookup.size() <= 2)
            {
                result = max(result, right - left + 1);
                right++;
                if (right == fruits.size())
                    return result;               
                lookup[fruits[right]]++;
            }
            else
            {
                auto it = lookup.find(fruits[left]);
                it->second--;
                if (it->second == 0)
                    lookup.erase(it);
                left++;
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