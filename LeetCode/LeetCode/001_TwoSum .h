#pragma once
#include "Common.h"

class Solution 
{
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> output;
		vector<IndexedNumber> input;
		for (int i = 0; i < nums.size(); i++)
		{
			input.push_back(IndexedNumber(nums[i], i + 1));
		}

		sort(input.begin(), input.end(), UDLess);
		int i = 0;
		int j = input.size() - 1;
		while (i < j)
		{
			int sum = input[i].mValue + input[j].mValue;
			if (sum == target)
			{
				output.push_back(input[i].mIndex);
				output.push_back(input[j].mIndex);
				break;
			}
			else if (sum < target)
			{
				i++;
			}
			else
			{
				j--;
			}
		}

		sort(output.begin(), output.end());
		return output;
	}
private:
	class IndexedNumber
	{
	public:
		IndexedNumber(int value, int index) : mValue(value), mIndex(index) {}
		int mValue;
		int mIndex;
	};
	static bool UDLess(IndexedNumber arg1, IndexedNumber arg2)
	{
		return arg1.mValue < arg2.mValue;
	}
};

void Test()
{
	Solution lSolution;
	vector<int> lNumbers = { 2, 7, 11, 15 };
	vector<int> lOutput;
	lOutput = lSolution.twoSum(lNumbers, 9);
	assert(lOutput.size() == 2);
	assert(lOutput[0] == 1);
	assert(lOutput[1] == 2);
}