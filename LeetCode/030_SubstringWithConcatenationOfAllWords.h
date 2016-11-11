#pragma once
#include "Common.h"

class Solution
{
public:
	vector<int> findSubstring(string s, vector<string>& words)
	{
		size_t lStringLength = 0;
		if (!words.empty())
		{
			lStringLength = words[0].length();
		}
		
		map<string, int> lTemplate;
		for (auto i = words.begin(); i != words.end(); i++)
		{
			lTemplate[*i]++;
		}
		
		vector<int> lResult;
		
		for (size_t i = 0; i + lStringLength * words.size() <= s.length(); i++)
		{
			map<string, int> lOccurenceState(lTemplate);
			size_t lPos = i;
			
			size_t lToMatch = words.size();
			while (lPos < s.length())
			{
				string lSubstring = s.substr(lPos, lStringLength);
				auto j = lOccurenceState.find(lSubstring);
				if (j != lOccurenceState.end())
				{
					j->second--;
					if (j->second < 0)
					{
						break;
					}
					else
					{
						lPos += lStringLength;
						lToMatch--;
					}
				}
				else
				{
					break;
				}
			}
			
			if (!lToMatch)
				lResult.push_back(static_cast<int>(i));
		}
		
		return lResult;
	}
};

void Test()
{
	string s = "a";
	vector<string> words = {"a","a"};
	
	Solution lSolution;
	vector<int> lTemp = lSolution.findSubstring(s, words);
	
	return;
}