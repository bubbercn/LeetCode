#pragma once
#include "Common.h"

class Solution
{
public:
	int romanToInt(string s)
	{
		int dictionary[256] = {0};
		
		dictionary['I'] = 1;
		dictionary['V'] = 5;
		dictionary['X'] = 10;
		dictionary['L'] = 50;
		dictionary['C'] = 100;
		dictionary['D'] = 500;
		dictionary['M'] = 1000;
		
		int result = 0;
		
		for (size_t i = 0; i < s.length(); i++)
		{
			if ((i + 1) < s.length() && dictionary[s[i]] < dictionary[s[i + 1]])
			{
				result += dictionary[s[i + 1]] - dictionary[s[i]];
				i++;
			}
			else
			{
				result += dictionary[s[i]];
			}
		}
		
		return result;
	}
};

void Test()
{
	Solution lSolution;
	
	assert(lSolution.romanToInt("I") == 1);
	assert(lSolution.romanToInt("IV") == 4);
	assert(lSolution.romanToInt("V") == 5);
	assert(lSolution.romanToInt("IX") == 9);
	assert(lSolution.romanToInt("X") == 10);
	assert(lSolution.romanToInt("XL") == 40);
	assert(lSolution.romanToInt("L") == 50);
	assert(lSolution.romanToInt("XC") == 90);
	assert(lSolution.romanToInt("C") == 100);
	assert(lSolution.romanToInt("CD") == 400);
	assert(lSolution.romanToInt("D") == 500);
	assert(lSolution.romanToInt("CM") == 900);
	assert(lSolution.romanToInt("M") == 1000);
	assert(lSolution.romanToInt("MMMCMXCIX") == 3999);
}