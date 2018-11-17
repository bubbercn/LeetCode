#pragma once
#include "Common.h"

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.size() == 0)
			return 0;
		
		int lNum = nums[0];
		int lPos = 1;
		
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] != lNum)
			{
				nums[lPos++] = nums[i];
				lNum = nums[i];
			}
		}
		
		return lPos;
	}
};

void Test()
{
	return;
}