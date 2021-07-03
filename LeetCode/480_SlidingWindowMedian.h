#pragma once
#include "Common.h"

class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        multiset<int> removedMax;
        multiset<int> removedMin;
        int k2 = k / 2;

        for (int i = 0; i < k; i++)
        {
            if (maxHeap.size() <= k2)
            {
                maxHeap.emplace(nums[i]);
            }
            else if (nums[i] >= maxHeap.top())
            {
                minHeap.emplace(nums[i]);
            }
            else
            {
                maxHeap.emplace(nums[i]);
                minHeap.emplace(maxHeap.top());
                maxHeap.pop();
            }
        }

        vector<double> result;
        result.reserve(nums.size() + 1 - k);
        bool flag = maxHeap.size() > minHeap.size();
        auto pushResult = [&]()
        {
            if (flag)
            {
                result.emplace_back(maxHeap.top());
            }
            else
            {
                result.emplace_back((maxHeap.top() + minHeap.top()) / 2.0);
            }
        };
        pushResult();

        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] >= maxHeap.top())
            {
                minHeap.emplace(nums[i]);
                removedMin.emplace(nums[i - k]);
            }
            else
            {
                maxHeap.emplace(nums[i]);
                removedMax.emplace(nums[i - k]);
            }
            for (auto it = removedMax.find(maxHeap.top()); it != removedMax.end(); it = removedMax.find(maxHeap.top()))
            {
                maxHeap.pop();
                removedMax.erase(it);
            }
            for (auto it = removedMin.find(minHeap.top()); it != removedMin.end(); it = removedMin.find(minHeap.top()))
            {
                minHeap.pop();
                removedMin.erase(it);
            }
            pushResult();
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
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<double> output = {1.00000, -1.00000, -1.00000, 3.00000, 5.00000, 6.00000};
    EXPECT_EQ(solution.medianSlidingWindow(nums, 3), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3, 4, 2, 3, 1, 4, 2};
    vector<double> output = {2.00000, 3.00000, 3.00000, 3.00000, 2.00000, 3.00000, 2.00000};
    EXPECT_EQ(solution.medianSlidingWindow(nums, 3), output);
}