#pragma once
#include "Common.h"

class Solution
{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		sort(nums.begin(), nums.end());
		return nSum(nums, nums.begin(), 4, target);
	}
	
private:
	vector<vector<int>> nSum(vector<int>&nums, vector<int>::iterator begin, int N, int target)
	{
		vector<vector<int>> lResult;
		if (N > 2)
		{
			int current = 0;
			for (auto i = begin; i != nums.end(); i++)
			{
				if (i == begin || *i != current)
				{
					current = *i;
				}
				else if (*i == current)
				{
					continue;
				}
				
				vector<vector<int>> lTemp = nSum(nums, i + 1, N - 1, target - *i);
				if (lTemp.size() != 0)
				{
					for (auto j = lTemp.begin(); j != lTemp.end(); j++)
					{
						(*j).insert((*j).begin(), *i);
						lResult.push_back((*j));
					}
				}
			}
		}
		else
		{
			auto i = begin, j = nums.end() - 1;
			while (i < j)
			{
				int lTemp = *i + *j;
				if (lTemp < target)
				{
					i++;
				}
				else if (lTemp > target)
				{
					j--;
				}
				else
				{
					vector<int> lTemp;
					lTemp.push_back(*i);
					lTemp.push_back(*j);
					lResult.push_back(lTemp);
					do
					{
						i++;
					}
					while (i != nums.end() && *i == *(i - 1));
				}
			}
		}
			
		return lResult;
	}
};

void Test()
{
	Solution lSolution;
	vector<int> lNums = {1, 0, -1, 0, -2, 2};
	vector<vector<int>> lResult = {{-2, -1, 1, 2}, {-2,  0, 0, 2}, {-1,  0, 0, 1}};
	assert(lSolution.fourSum(lNums, 0) == lResult);
	
	lNums = {};
	lResult = {};
	assert(lSolution.fourSum(lNums, 0) == lResult);
	return;
}