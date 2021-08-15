#pragma once
#include "Common.h"

class Solution
{
public:
	int longestValidParentheses(string s)
	{
		int max1 = 0;
		int max2 = 0;
		mValidLength.clear();
		mValidLength.resize(s.length());
		
		for (size_t i = 0; i < s.length(); i++)
		{
			max1 =  max2;
			if (s[i] == '(')
			{
				max2 = max1;
				mValidLength[i] = 0;
			}
			else
			{
				CalculateValidLength(s, static_cast<int>(i));
				max2 = max(max1, mValidLength[i]);
			}
		}
		
		return max2;
	}
	
private:
	void CalculateValidLength(const string& s, int i)
	{
		mValidLength[i] = 0;
		if (i - 1 >= 0)
		{
			if (i - 1 - mValidLength[i - 1] >= 0)
			{
				if (s[i - 1 - mValidLength[i - 1]] == '(')
				{
					mValidLength[i] = mValidLength[i - 1] + 2;
					
					if (i - 1 - mValidLength[i - 1] - 1 >= 0)
					{
						mValidLength[i] += mValidLength[i - 1 - mValidLength[i - 1] - 1];
					}
				}
			}
		}
	}
	
	vector<int> mValidLength;
};

void Test()
{
	Solution lSolution;
	
	string s = "(";
	assert(lSolution.longestValidParentheses(s) == 0);
	
	s = ")";
	assert(lSolution.longestValidParentheses(s) == 0);
	
	s = "()";
	assert(lSolution.longestValidParentheses(s) == 2);
	
	s = "()(";
	assert(lSolution.longestValidParentheses(s) == 2);
	
	s = "())";
	assert(lSolution.longestValidParentheses(s) == 2);
	
	s = "(()";
	assert(lSolution.longestValidParentheses(s) == 2);
	
	s = ")()";
	assert(lSolution.longestValidParentheses(s) == 2);
	
	s = ")()())";
	assert(lSolution.longestValidParentheses(s) == 4);
	
	s = ")(())(";
	assert(lSolution.longestValidParentheses(s) == 4);
	
	s = "()(())";
	assert(lSolution.longestValidParentheses(s) == 6);
}