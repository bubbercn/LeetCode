#pragma once
#include "Common.h"

class Solution
{
public:
	string convert(string s, int numRows) 
	{
		int length = s.length();
		string result;
		result.reserve(length);
		int x = (numRows - 1) << 1;

		if (numRows == 1)
		{
			return s;
		}

		for (int i = 0; i < numRows; i++)
		{
			int j = i;
			while (j < length)
			{
				if (i == 0 || i == numRows - 1)
				{
					result += s.at(j);
				}
				else
				{
					result += s.at(j);
					if (j - i + x - i < length)
					{
						result += s.at(j - i + x - i);
					}
					else
					{
						break;
					}
				}
				
				j += x;
			}
		}

		return result;
	}
};

void Test()
{
	Solution lSolution;
	assert(lSolution.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
	assert(lSolution.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
}