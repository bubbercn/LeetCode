#pragma once
#include "Common.h"
class Solution 
{
public:
	string longestPalindrome(string s) 
	{
		int max = 0;
		int start = 0;
		for (int i = 0; i < s.length(); i++)
		{
			int r = 1;
			while (i - r >= 0 && i + r < s.length() && s.at(i - r) == s.at(i + r))
			{
				r++;
			}
			r--;
			if ((r << 1) + 1 > max)
			{
				max = (r << 1) + 1;
				start = i - r;
			}
			if (i + 1 < s.length() && s.at(i) == s.at(i + 1))
			{
				r = 1;
				while (i - r >= 0 && i + r + 1 < s.length() && s.at(i - r) == s.at(i + r + 1))
				{
					r++;
				}
				r--;
				if ((r + 1 << 1) > max)
				{
					max = r + 1 << 1;
					start = i - r;
				}
			}
		}
		return s.substr(start, max);
	}
};

void Test()
{
	Solution lSolution;
	string s1("^abcba$");
	assert(lSolution.longestPalindrome(s1) == "abcba");
	string s2("^abccba$");
	assert(lSolution.longestPalindrome(s2) == "abccba");
}