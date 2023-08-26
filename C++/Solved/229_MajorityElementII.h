#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        set<int> result;
        unordered_map<int, int> lookup;
        int threshold = nums.size() / 3;
        for (auto i : nums)
        {
            lookup[i]++;
            if (lookup[i] > threshold)
            {
                result.emplace(i);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};

void Test()
{
    Solution solution;
    vector<int> input, output;

    input = {3, 2, 3};
    output = {3};
    assert(solution.majorityElement(input) == output);

    input = {1, 1, 1, 3, 3, 2, 2, 2};
    output = {1, 2};
    assert(solution.majorityElement(input) == output);
}