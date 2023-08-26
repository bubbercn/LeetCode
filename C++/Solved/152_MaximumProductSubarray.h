#pragma once
#include "Common.h"

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        int maxProduct = INT_MIN;
        int product1 = 1;
        int product2 = 1;
        for (auto num : nums)
        {
            if (num < 0)
            {
                swap(product1, product2);
            }
            
            product1 *= num;
            product2 *= num;
            
            product1 = max(product1, num);
            product2 = min(product2, num);
            maxProduct = max(product1, maxProduct);
        }
        return maxProduct;
    }
};

void Test()
{
    Solution solution;
    vector<int> nums;
    
    nums = {};
    assert(solution.maxProduct(nums) == 0);

    nums = {0};
    assert(solution.maxProduct(nums) == 0);

    nums = {1};
    assert(solution.maxProduct(nums) == 1);

    nums = {2,3,-2,4};
    assert(solution.maxProduct(nums) == 6);

    nums = {-2,0,-1};
    assert(solution.maxProduct(nums) == 0);

    nums = {3,-1,4};
    assert(solution.maxProduct(nums) == 4);
    
    nums = {2,-5,-2,-4,3};
    assert(solution.maxProduct(nums) == 24);
}
