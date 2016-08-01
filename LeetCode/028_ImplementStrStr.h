#pragma once
#include "Common.h"

class Solution
{
public:
	int strStr(string haystack, string needle)
	{
//		if (needle.empty())
//			return 0;
//		
//		int lPos = -1;
//		
//		for (auto i = haystack.begin(); i != haystack.end(); i++)
//		{
//			lPos++;
//			if (Match(i, haystack.end(), needle))
//			{
//				return lPos;
//			}
//		}
//		
//		return -1;
		return kmp_find(haystack, needle);
	}
	
private:
	bool Match(string::const_iterator iBegin, string::const_iterator iEnd, const string& iNeedle)
	{
		auto i = iNeedle.begin();
		for (; i != iNeedle.end() && iBegin != iEnd; i++)
		{
			if (*iBegin == *i)
			{
				iBegin++;
			}
			else
			{
				break;
			}
		}
		
		if (i == iNeedle.end())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	int kmp_find(const string& target,const string& pattern)
	{
		size_t target_length = target.size();
		size_t pattern_length = pattern.size();
		int * overlay_value = new int[pattern_length];
		overlay_value[0] = -1;
		int index = 0;
		for(int i=1;i<pattern_length;++i)
		{
			index = overlay_value[i-1];
			while(index>=0 && pattern[index+1]!=pattern[i])
			{
				index  = overlay_value[index];
			}
			if(pattern[index+1]==pattern[i])
			{
				overlay_value[i] = index +1;
			}
			else
			{
				overlay_value[i] = -1;
			}
		}
		//match algorithm start
		int pattern_index = 0;
		int target_index = 0;
		while(pattern_index<pattern_length&&target_index<target_length)
		{
			if(target[target_index]==pattern[pattern_index])
			{
				++target_index;
				++pattern_index;
			}
			else if(pattern_index==0)
			{
				++target_index;
			}
			else
			{
				pattern_index = overlay_value[pattern_index-1]+1;
			}
		}
		if(pattern_index==pattern_length)
		{
			return target_index-pattern_index;
		}
		else
		{
			return -1;
		}
		delete [] overlay_value;
	}
};

void Test()
{
	return;
}