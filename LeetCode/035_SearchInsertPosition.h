#pragma once
#include "Common.h"

class Solution
{
public:
	int searchInsert(vector<int>& nums, int target)
	{
		auto i = binary_search(nums.begin(), nums.end(), target);
		
		int result = i - nums.begin();
		
		if (target > *i && i != nums.end())
			result ++;
		return result;
	}
	
private:
	vector<int>::const_iterator binary_search(vector<int>::const_iterator begin, vector<int>::const_iterator end, int target)
	{
		auto middle = begin + (end - begin) / 2;
		if (*middle == target)
		{
			return middle;
		}
		else
		{
			if (end - begin <= 1)
			{
				return begin;
			}
			else
			{
				if (target < *middle)
				{
					return binary_search(begin, middle, target);
				}
				else
				{
					return binary_search(middle + 1, end, target);
				}
			}
		}
	}
	
};

void Test()
{
	Solution lSolution;
	
	vector<int> nums = {1, 3};
	assert(lSolution.searchInsert(nums, 4) == 2);
}