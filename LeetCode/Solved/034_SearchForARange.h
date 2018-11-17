#pragma once
#include "Common.h"

class Solution
{
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> result(2, -1);
		auto i = binary_search(nums.begin(), nums.end(), target);
		if (i == nums.end())
			return result;
		
		auto lower_bound = i;
		while (lower_bound - 1 >= nums.begin() && *(lower_bound - 1) ==  target)
		{
			lower_bound--;
		}
		auto upper_bound = i;
		while (upper_bound + 1 < nums.end() && *(upper_bound + 1) == target)
		{
			upper_bound++;
		}
		result[0] = lower_bound - nums.begin();
		result[1] = upper_bound - nums.begin();
		
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
				return end;
			}
			else
			{
				if (target < *middle)
				{
					auto i = binary_search(begin, middle, target);
					if (i == middle)
						return end;
					return i;
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
	return;
}