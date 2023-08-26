#pragma once
#include "Common.h"

class Solution
{
public:
	void nextPermutation(vector<int>& nums)
	{
		if (nums.size() <= 1)
			return;
		
		// fisrt find the drop pont from end
		auto i = nums.rbegin();
		
		while (i != nums.rend() - 1)
		{
			if (*(i + 1) < *i)
			{
				// if found, switch with the smallest one
				auto j = nums.rbegin();
				while (*j <= *(i + 1))
					j++;
				
				int lTemp = *(i + 1);
				*(i + 1) = *j;
				*j = lTemp;
				
				// then sort the rest
				std::sort(nums.begin() + (nums.rend() -1 - i), nums.end());
				return;
			}
			else
			{
				i++;
			}
		}
		
		// if not found, sort the whole vector
		std::sort(nums.begin(),nums.end());
	}
};

void Test()
{
	vector<int> lNums = {1, 2, 1};
	Solution lSolution;
	lSolution.nextPermutation(lNums);
	return;
}