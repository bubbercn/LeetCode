#pragma once
#include "Common.h"

class Solution
{
public:
	bool isMatch(string s, string p)
	{
		if (p == "")
		{
			return s == "" ? true : false;
		}

		for (size_t i = 0; i < p.length(); i++)
		{
			size_t j = string::npos;
			if (p[i] != '*' && (i + 1 == p.length() || p[i + 1] != '*'))
			{
				while ((j = findcharacter(s, p[i], j + 1)) != string::npos)
				{
					if (isMatch(s.substr(0, j), p.substr(0, i)) && isMatch(s.substr(j + 1), p.substr(i + 1)))
					{
						return true;
					}
				}
				return false;
			}
		}
		
		if (s == "")
			return true;

		if (p.find('.') != string::npos)
			return true;

		size_t i = 0, j = 0;
		while (i < s.length() && j < p.length())
		{
			if (s[i] == p[j])
			{
				i = s.find_first_not_of(s[i], i);
				if (i == string::npos)
				{
					i = s.length();
				}
				do
				{
					j += 2;
				} while (j < p.length() && p[j] == p[j - 2]);
			}
			else
			{
				j += 2;
			}
		}

		if (i < s.length())
		{
			return false;
		}
		else
		{
			return true;
		}
	}

private:
	size_t findcharacter(const string& s, char p, size_t begin)
	{
		if (p == '.')
		{
			return begin < s.length() ? begin : string::npos;
		}
		else
		{
			return s.find(p, begin);
		}
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
	assert(lSolution.isMatch("aab", "c*a*a*b") == true);
	assert(lSolution.isMatch("aab", "b*a*") == false);
	assert(lSolution.isMatch("aaa", "ab*a*c*a") == true);
}
