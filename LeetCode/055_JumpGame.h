#pragma once
#include "Common.h"

class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        N = nums.size();
        mLookup = vector<int>(N + 1, -1);
        
        return Process(nums, N);
    }
private:
    size_t N;
    vector<int> mLookup;
    bool Process(vector<int>& nums, size_t n)
    {
        if (mLookup[n] == 1)
            return true;
        else if (mLookup[n] == 0)
            return false;
        
        if (n < 2)
        {
            mLookup[n] = 1;
            return true;
        }
        
        for (int i = static_cast<int>(n - 2); i >= 0; i--)
        {
            if (nums[i] >= n - 1 - i)
            {
                if (Process(nums, i + 1))
                {
                    mLookup[n] = 1;
                    return true;
                }
            }
        }
        
        mLookup[n] = 0;
        return false;
    }
};

void Test()
{
    Solution solution;
    vector<int> input1 = {2,3,1,1,4};
    assert(solution.canJump(input1));

    vector<int> input2 = {3,2,1,0,4};
    assert(!solution.canJump(input2));
}
