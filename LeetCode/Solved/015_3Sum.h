#pragma once
#include "Common.h"

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> lResult;
		sort(nums.begin(), nums.end());
		
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
			
			vector<pair<vector<int>::iterator, vector<int>::iterator>> lPairs;
			findSum(nums, i, -*i, lPairs);
			
			if (lPairs.size() != 0)
			{
				for (auto j = lPairs.begin(); j != lPairs.end(); j++)
				{
					vector<int> lTemp;
					lTemp.push_back(*i);
					lTemp.push_back(*(*j).first);
					lTemp.push_back(*(*j).second);
					lResult.push_back(lTemp);
				}
			}
		}
		
		return lResult;
	}
	
private:
	void findSum(vector<int>& nums, vector<int>::iterator current, int sum, vector<pair<vector<int>::iterator, vector<int>::iterator>>& result)
	{
		auto i = current + 1, j = nums.end() - 1;
		while (i < j)
		{
			int lTemp = *i + *j;
			if (lTemp < sum)
			{
				i++;
			}
			else if (lTemp > sum)
			{
				j--;
			}
			else
			{
				result.push_back(make_pair(i, j));
				do
				{
					i++;
				}
				while (i != nums.end() && *i == *(i - 1));
			}
		}
	}
};

void Test()
{
	Solution lSolution;
	vector<int> lNums = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> lResult = {{-1, -1, 2}, {-1, 0 , 1}};
	assert(lSolution.threeSum(lNums) == lResult);
}
