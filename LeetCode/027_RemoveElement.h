#pragma once
#include "Common.h"

class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		if (nums.empty())
			return 0;
		
		int* lpHead = &(*nums.begin());
		int* lpTail = &(*nums.rbegin());
		
		while (true)
		{
			while (lpHead <= lpTail && *lpHead != val)
			{
				lpHead++;
			}
			
			while (lpHead < lpTail && *lpTail == val)
			{
				lpTail--;
			}
			
			if (lpHead >= lpTail)
			{
				break;
			}
			else
			{
				int lTemp = *lpTail;
				*lpTail = *lpHead;
				*lpHead = lTemp;
				lpHead++;
				lpTail--;
			}
		}
		
		return static_cast<int>(lpHead - &(*nums.begin()));
	}
};

void Test()
{
	Solution lSolution;
	vector<int> lNums = {3, 2, 2, 3};
	assert(lSolution.removeElement(lNums, 3) == 2);
	
	lNums = {3, 2, 2, 2, 3};
	assert(lSolution.removeElement(lNums, 3) == 3);
	
	lNums = {};
	assert(lSolution.removeElement(lNums, 3) == 0);
	
	lNums = {2};
	assert(lSolution.removeElement(lNums, 2) == 0);
	return;
}