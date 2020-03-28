#pragma once
#include "Common.h"

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (nums[middle] == target)
            {
                return true;
            }
            else
            {
                if (nums[left] == nums[middle])
                {
                    int mid_left = findLeft(nums, middle);
                    if (mid_left > left)
                    {
                        if (nums[left] < nums[mid_left])
                        {
                            if (nums[left] <= target && nums[mid_left] >= target)
                            {
                                right = mid_left;
                                continue;
                            }
                            else
                            {
                                left = middle + 1;
                                continue;
                            }
                            
                        }
                    }
                    else
                    {
                        left = middle + 1;
                        continue;
                    }
                    
                }
                else if (nums[left] < nums[middle])
                {
                    if (nums[left] <= target && nums[middle] >= target)
                    {
                        right = middle - 1;
                        continue;
                    }
                    else
                    {
                        left = middle + 1;
                        continue;
                    }
                }
                
                if (nums[right] == nums[middle])
                {
                    int mid_right = findRight(nums, middle);
                    if (mid_right < right)
                    {
                        if (nums[mid_right] < nums[right])
                        {
                            if (nums[mid_right] <= target && nums[right] >= target)
                            {
                                left = mid_right;
                                continue;
                            }
                            else
                            {
                                right = middle - 1;
                                continue;
                            }
                            
                        }
                    }
                    else
                    {
                        right = middle - 1;
                        continue;
                    }
                    
                }
                else if (nums[middle] < nums[right])
                {
                    if (nums[middle] <= target && nums[right] >= target)
                    {
                        left = middle + 1;
                        continue;
                    }
                    else
                    {
                        right = middle - 1;
                        continue;
                    }
                }

                return false;
            }
        }

        return false;
    }

private:
    int findLeft(const vector<int>& nums, int middle)
    {
        assert(middle >= 0 && middle < nums.size());
        for (int i = middle - 1; i >= 0; i--)
        {
            if (nums[i] != nums[middle])
            {
                return i;
            }
        }
        return -1;
    }

    int findRight(const vector<int>& nums, int middle)
    {
        assert(middle >= 0 && middle < nums.size());
        for (int i = middle + 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[middle])
            {
                return i;
            }
        }
        return nums.size();
    }
};

void Test()
{
    Solution solution;
    assert(!solution.search(vector<int>({1,3}), 0));
    assert(solution.search(vector<int>({2,5,6,0,0,1,2}), 0));
    assert(!solution.search(vector<int>({2,5,6,0,0,1,2}), 3));
}
