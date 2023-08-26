#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> frequcencyMap;
        for (auto num : nums)
        {
            frequcencyMap[num]++;
        }
        priority_queue<pair<int, int>, std::vector<pair<int, int>>, greater<pair<int, int>>> frequencyHeap;
        for (auto it = frequcencyMap.begin(); it != frequcencyMap.end(); it++)
        {
            if (static_cast<int>(frequencyHeap.size()) < k)
            {
                frequencyHeap.emplace(it->second, it->first);
            }
            else if (it->second > frequencyHeap.top().first)
            {
                frequencyHeap.pop();
                frequencyHeap.emplace(it->second, it->first);
            }
        }
        vector<int> result;
        while (!frequencyHeap.empty())
        {
            result.emplace_back(frequencyHeap.top().second);
            frequencyHeap.pop();
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> output = {2, 1};
    EXPECT_EQ(solution.topKFrequent(nums, 2), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1};
    vector<int> output = {1};
    EXPECT_EQ(solution.topKFrequent(nums, 1), output);
}