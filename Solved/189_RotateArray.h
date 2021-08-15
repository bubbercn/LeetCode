#pragma once
#include "Common.h"

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int N = nums.size();
        if (N == 0)
            return;

        k = k % N;
        reverse(nums, 0, N - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, N - 1);
    }

private:
    void reverse(vector<int> &nums, int begin, int end)
    {
        while (begin < end)
        {
            swap(nums[begin], nums[end]);
            begin++;
            end--;
        }
    }
};

void Test()
{
    Solution solution;
    vector<int> nums;
    vector<int> output;
    int k;

    nums = {1, 2, 3, 4, 5, 6, 7};
    k = 3;
    output = {5, 6, 7, 1, 2, 3, 4};
    solution.rotate(nums, k);
    assert(nums == output);

    nums = {-1, -100, 3, 99};
    k = 2;
    output = {3, 99, -1, -100};
    solution.rotate(nums, k);
    assert(nums == output);
}