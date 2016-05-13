#pragma once
#include "Common.h"

class Solution
{
public:
	Solution()
	{
		vector<char> N2 = {'a', 'b', 'c'};
		vector<char> N3 = {'d', 'e', 'f'};
		vector<char> N4 = {'g', 'h', 'i'};
		vector<char> N5 = {'j', 'k', 'l'};
		vector<char> N6 = {'m', 'n', 'o'};
		vector<char> N7 = {'p', 'q', 'r', 's'};
		vector<char> N8 = {'t', 'u', 'v'};
		vector<char> N9 = {'w', 'x', 'y', 'z'};

		mBuckets.push_back(vector<char>());
		mBuckets.push_back(vector<char>());
		mBuckets.push_back(N2);
		mBuckets.push_back(N3);
		mBuckets.push_back(N4);
		mBuckets.push_back(N5);
		mBuckets.push_back(N6);
		mBuckets.push_back(N7);
		mBuckets.push_back(N8);
		mBuckets.push_back(N9);
	}
	
	vector<string> letterCombinations(string digits)
	{
		vector<int> lDigits;
		
		if (digits.empty())
		{
			return {};
		}
		
		for (auto i = 0; i < digits.length(); i++)
		{
			int lNum = digits[i] - '0';
			
			if (lNum < 2 || lNum > 9)
			{
				return {};
			}
			else
			{
				lDigits.push_back(lNum);
			}
		}
		
		vector<int> lIterator;
		for (auto i = lDigits.begin(); i != lDigits.end(); i++)
		{
			lIterator.push_back(0);
		}
		
		vector<string> lResult;
		
		while (lIterator[0] < mBuckets[lDigits[0]].size())
		{
			string lTemp;
			lTemp.reserve(lIterator.size());
			for (auto i = 0; i < lIterator.size(); i++)
			{
				lTemp += mBuckets[lDigits[i]][lIterator[i]];
			}
			
			lResult.push_back(lTemp);
			
			(*lIterator.rbegin())++;
			for (auto i = lIterator.size() - 1; i > 0; i--)
			{
				if (lIterator[i] == mBuckets[lDigits[i]].size())
				{
					lIterator[i] = 0;
					lIterator[i - 1]++;
				}
			}
		}
		
		return lResult;
	}
	
private:
	
	vector<vector<char>> mBuckets;
};

void Test()
{
	Solution lSolution;
	assert(lSolution.letterCombinations("23") == vector<string>({"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}));
	return;
}