#pragma once
#include "Common.h"

class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        for (int i = m - 1; i >= 0; i--)
        {
            nums1[n + i] = nums1[i];
        }

        int i = n;
        int j = 0;
        int k = 0;
        while (i < m + n && j < n)
        {
            int min = 0;
            if (nums1[i] < nums2[j])
            {
                nums1[k++] = nums1[i++];
            }
            else
            {
                nums1[k++] = nums2[j++];
            }
        }

        while (j < n)
        {
            nums1[k++] = nums2[j++];
        }
    }
};

void Test()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    Solution solution;
    solution.merge(nums1, 3, nums2, 3);
}