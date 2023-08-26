#pragma once
#include "Common.h"

class Solution 
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		vector<int> sorted(nums1.size() + nums2.size(), 0);
		int i = 0, j = 0, k = 0;
		while (i < nums1.size() && j < nums2.size())
		{
			if (nums1[i] < nums2[j])
			{
				sorted[k++] = nums1[i++];
			}
			else
			{
				sorted[k++] = nums2[j++];
			}
		}
		if (i == nums1.size())
		{
			for (int x = j; x < nums2.size(); x++)
			{
				sorted[k++] = nums2[x];
			}
		}
		else
		{
			for (int x = i; x < nums1.size(); x++)
			{
				sorted[k++] = nums1[x];
			}
		}
		if ((sorted.size() - 1) >> 1 == sorted.size() >> 1)
		{
			return sorted[sorted.size() >> 1];
		}
		else
		{
			return static_cast<double>(sorted[(sorted.size() - 1) >> 1] + sorted[sorted.size() >> 1]) / 2;
		}
	}
};

void Test()
{
	Solution lSolution;
	vector<int> nums1 = { 1, 2 };
	vector<int> nums2 = { 3, 4, 5, 6 };
	assert(lSolution.findMedianSortedArrays(nums1, nums2) == 3.5);
}