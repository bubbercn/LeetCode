#pragma once
#include "Common.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> lookup;
        int threshold = nums.size() / 2;
        for (auto i : nums)
        {
            lookup[i]++;
            if (lookup[i] > threshold)
                return i;
        }
        return INT_MIN;
    }
};

void Test()
{

}