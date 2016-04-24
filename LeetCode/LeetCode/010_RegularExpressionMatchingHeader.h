#pragma once
#include "Common.h"

class Solution
{
public:
	bool isMatch(string s, string p)
	{
		return false;
	}
};

void Test()
{
	Solution lSolution;
	assert(lSolution.isMatch("aa", "a") == false);
	assert(lSolution.isMatch("aa", "aa") == true);
	assert(lSolution.isMatch("aaa", "aa") == false);
	assert(lSolution.isMatch("aa", "a*") == true);
	assert(lSolution.isMatch("aa", ".*") == true);
	assert(lSolution.isMatch("ab", ".*") == true);
	assert(lSolution.isMatch("aab", "c*a*b") == true);
}
