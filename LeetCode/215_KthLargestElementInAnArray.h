#pragma once
#include "Common.h"

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto i : nums)
        {
            if (minHeap.size() < k)
            {
                minHeap.emplace(i);
            }
            else if (i > minHeap.top())
            {
                minHeap.pop();
                minHeap.emplace(i);
            }
        }
        return minHeap.top();
    }
};

void Test()
{
    Solution solution;
    vector<int> nums;
    int k;

    nums = {3,2,1,5,6,4};
    k = 2;
    assert(solution.findKthLargest(nums, k) == 5);

    nums = {3,2,3,1,2,4,5,5,6};
    k = 4;
    assert(solution.findKthLargest(nums, k) == 4);
}