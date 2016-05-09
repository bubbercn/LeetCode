#pragma once
#include "Common.h"

class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		sort(nums.begin(), nums.end());
		int lResult = target;
		
		int current = 0;
		for (auto i = nums.begin(); i != nums.end(); i++)
		{
			if (i == nums.begin() || *i != current)
			{
				current = *i;
			}
			else if (*i == current)
			{
				continue;
			}
			
			int lTemp = findSumClosest(nums, i, target - *i);
			if (lTemp == INT_MAX)
			{
				continue;
			}
			else if (lTemp + *i == target)
			{
				return target;
			}
			else if (lResult == target || abs(lTemp + *i - target) < abs(lResult - target))
			{
				lResult = lTemp + *i;
			}
		}
		
		return lResult;
	}
	
private:
	int findSumClosest(vector<int>& nums, vector<int>::iterator current, int sum)
	{
		auto i = current + 1, j = nums.end() - 1;
		int lResult = INT_MAX;
		while (i < j)
		{
			int lTemp = *i + *j;
			if (lTemp < sum)
			{
				i++;
				if (lResult == INT_MAX || abs(lTemp - sum) < abs(lResult - sum))
				{
					lResult = lTemp;
				}
			}
			else if (lTemp > sum)
			{
				j--;
				if (lResult == INT_MAX || abs(lTemp - sum) < abs(lResult - sum))
				{
					lResult = lTemp;
				}
			}
			else
			{
				return sum;
			}
		}
		
		return lResult;
	}
};

void Test()
{
	Solution lSolution;
	vector<int> lNums = {-1, 2, 1, -4};
//	assert(lSolution.threeSumClosest(lNums, 1) == 2);
	
	lNums = {1, 1, 1, 1};
	assert(lSolution.threeSumClosest(lNums, 0) == 3);
	return;
}