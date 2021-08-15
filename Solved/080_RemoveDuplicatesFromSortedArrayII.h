#pragma once
#include "Common.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int source = 0;
        int curNumber = 0;
        int count = 0;
        for (size_t target = 0; target < nums.size(); target++)
        {
            if (target == 0)
            {
                curNumber = nums[target];
                count++;
                source++;
            }
            else
            {
                if (nums[target] ==  curNumber)
                {
                    count++;
                }
                else
                {
                    curNumber = nums[target];
                    count = 1;
                }
                if (count <= 2)
                {
                    nums[source++] = nums[target];
                }
            }
        }
        return source;
    }
};

void Test()
{
    vector<int> input = {0,0,1,1,1,1,2,3,3};
    Solution solution;
    assert(solution.removeDuplicates(input) == 7);
}
