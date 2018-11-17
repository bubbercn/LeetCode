#pragma once
#include "Common.h"

class Solution
{
public:
	int search(vector<int>& nums, int target)
	{
		if(nums.size() == 0)
			return -1;
		
		int result = search(nums.begin(), nums.end(), target);
		if (result == -1)
			return -1;
		
		return find(nums.begin(), nums.end(), result) - nums.begin();
	}
	
private:
	int search(vector<int>::const_iterator begin, vector<int>::const_iterator end, int target)
	{
		auto middle = begin + (end - begin) / 2;
		if (*middle == target)
		{
			return *middle;
		}
		else
		{
			if (end - begin <= 1)
			{
				return -1;
			}
			else
			{
				if (*begin < *middle)
				{
					if (target < *middle && target >= *begin)
					{
						return binary_search(begin, middle, target);
					}
					else if (middle + 1 < end)
					{
						return search(middle + 1, end, target);
					}
					return -1;
				}
				else
				{
					if (target > *middle && target <= *(end - 1))
					{
						if (middle + 1 < end)
						{
							return binary_search(middle + 1, end, target);
						}
						return -1;
					}
					else
					{
						return search(begin, middle, target);
					}
				}
			}
		}
	}
	
	int binary_search(vector<int>::const_iterator begin, vector<int>::const_iterator end, int target)
	{
		auto middle = begin + (end - begin) / 2;
		if (*middle == target)
		{
			return *middle;
		}
		else
		{
			if (end - begin <= 1)
			{
				return -1;
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
	vector<int> nums = {2,3,7,8,1};
	assert(lSolution.search(nums, 5) == -1);
	return;
}