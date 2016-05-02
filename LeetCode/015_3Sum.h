#pragma once
#include "Common.h"

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		return {};
	}
};

void Test()
{
	Solution lSolution;
	vector<int> lNums = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> lResult = {{-1, 0 , 1}, {-1, -1, 2}};
	assert(lSolution.threeSum(lNums) == lResult);
}
