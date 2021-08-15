#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result(nums.size() - k + 1);
        deque<int> window;
        for (int i = 0; i < k; i++)
        {
            enqueue(window, nums, i);
        }

        result[0] = nums[window.front()];

        for (int i = 1; i < result.size(); i++)
        {
            while (!window.empty() && window.front() < i)
            {
                window.pop_front();
            }
            enqueue(window, nums, i + k - 1);
            result[i] = nums[window.front()];
        }

        return result;
    }

private:
    void enqueue(deque<int> &window, const vector<int> &nums, int index)
    {
        while (!window.empty() && nums[window.back()] <= nums[index])
        {
            window.pop_back();
        }
        window.emplace_back(index);
    }
};

void Test()
{
    Solution solution;

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> output = {3,3,5,5,6,7};
    assert(solution.maxSlidingWindow(nums, 3) == output);
}