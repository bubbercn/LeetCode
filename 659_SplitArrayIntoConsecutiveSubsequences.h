#pragma once
#include "Common.h"

class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> tails;
        int shortCount = 0;
        for (auto num : nums)
        {
            if (tails.empty())
            {
                tails[num].emplace(1);
                shortCount++;
            }
            else if (auto it = tails.find(num - 1); it != tails.end())
            {
                auto& lengths = it->second;
                int length = lengths.top();
                lengths.pop();
                if (lengths.empty())
                    tails.erase(num - 1);
                tails[num].emplace(++length);
                if (length == 3)
                    shortCount--;
            }
            else
            {
                tails[num].emplace(1);
                shortCount++;
            }
        }
        return shortCount == 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 2, 3, 3, 4, 5};
    EXPECT_EQ(solution.isPossible(nums), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3, 3, 4, 4, 5, 5};
    EXPECT_EQ(solution.isPossible(nums), true);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1, 2, 3, 4, 4, 5};
    EXPECT_EQ(solution.isPossible(nums), false);
}

TEST_F(LeetCodeTest, Case1)
{
    vector<int> nums = {1, 2, 2, 3, 3, 4, 5};
    EXPECT_EQ(solution.isPossible(nums), true);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {1, 2, 3, 4, 5, 5, 6, 7};
    EXPECT_EQ(solution.isPossible(nums), true);
}