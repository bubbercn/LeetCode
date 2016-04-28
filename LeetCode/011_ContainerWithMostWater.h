#pragma once
#include "Common.h"

class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		int max = -1;
		int begin = 0;
		int end = static_cast<int>(height.size() - 1);
		
		while (begin < end)
		{
			int min = height[begin] < height[end] ? height[begin] : height[end];
			int water = static_cast<int>(end - begin) * min;
			if (water > max)
				max = water;
			if (min == height[begin])
			{
				while (min >= height[++begin])
				{
					
				}
			}
			else
			{
				while (min >= height[--end])
				{
					
				}
			}
		}
		
		return max;
	}
};

void Test()
{
	Solution lSolution;
	
	vector<int> lCase1 = {1, 2, 3};
	assert(lSolution.maxArea(lCase1) == 2);
	
	vector<int> lCase2 = {1, 99, 100, 1};
	assert(lSolution.maxArea(lCase2) == 99);
}