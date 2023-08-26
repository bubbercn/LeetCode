#pragma once
#include "Common.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty())
            return {};
                
        vector<vector<int>> result;
        
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (result.empty())
            {
                result.emplace_back(1, nums[i]);
            }
            else
            {
                vector<vector<int>> tempResult;
                for (auto &j : result)
                {
                    for (int k = 0; k <= i; k++)
                    {
                        if (k != 0 && nums[i] == j[k - 1])
                            break;
                        vector<int> temp(j);
                        temp.insert(temp.begin() + k, nums[i]);
                        tempResult.emplace_back(temp);
                    }
                }
                result.swap(tempResult);
            }
        }
        
        return result;
    }
};

void Test()
{
    Solution solution;
    vector<int> nums = {1, 1, 2};
    solution.permuteUnique(nums);
}
