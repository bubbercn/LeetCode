#pragma once
#include "Common.h"

class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		return longestCommonPrefixInner(strs, 0, strs.size() - 1);
	}
	
private:
	string longestCommonPrefixInner(const vector<string>& strs, size_t begin, size_t end)
	{
		if (begin == end)
		{
			return strs[begin];
		}
		else if (begin + 1 == end)
		{
			return longestCommonFor2(strs[begin], strs[end]);
		}
		else if (begin + 2 < end + 1)
		{
			size_t mid = (begin + end) >> 1;
			return longestCommonFor2(longestCommonPrefixInner(strs, begin, mid), longestCommonPrefixInner(strs, mid, end));
		}
		else
		{
			return "";
		}
	}
	
	string longestCommonFor2(string s1, string s2)
	{
		size_t i = 0;
		while (i < s1.length() && i < s2.length())
		{
			if (s1[i] == s2[i])
			{
				i++;
			}
			else
			{
				break;
			}
		}
		
		return s1.substr(0, i);
	}
};

void Test()
{
	Solution lSolution;
	
	vector<string> strs = {"a", "b", "c"};
	assert(lSolution.longestCommonPrefix(strs) == "");
	
	strs = {"abc", "abcd", "abcde"};
	assert(lSolution.longestCommonPrefix(strs) == "abc");
	
	strs.clear();
	assert(lSolution.longestCommonPrefix(strs) == "");
}