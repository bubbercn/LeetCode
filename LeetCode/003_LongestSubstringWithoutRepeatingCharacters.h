#pragma once
#include "Common.h"

class Solution 
{
public:
	int lengthOfLongestSubstring(string s) 
	{
		int output = 0;
		int hash[256];
		int max = 0;
		memset(hash, -1, sizeof(hash));
		for (int i = 0; i < s.length(); i++)
		{
			if (hash[s.at(i)] == -1)
			{
				hash[s.at(i)] = i;
				max++;
			}
			else
			{
				if (max > output)
				{
					output = max;
				}

				i = hash[s.at(i)];
				memset(hash, -1, sizeof(hash));
				max = 0;
			}
		}

		if (max > output)
		{
			output = max;
		}

		return output;
	}
};

void Test()
{
	Solution lSolution;

	string s1;
	assert(lSolution.lengthOfLongestSubstring(s1) == 0);

	string s2 = "abcabcbb";
	assert(lSolution.lengthOfLongestSubstring(s2) == 3);

	string s3 = "bbbb";
	assert(lSolution.lengthOfLongestSubstring(s3) == 1);

	string s4 = "aab";
	assert(lSolution.lengthOfLongestSubstring(s4) == 2);
}