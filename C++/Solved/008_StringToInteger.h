#pragma once
#include "Common.h"

class Solution 
{
public:
	int myAtoi(string str) 
	{
		enum state
		{
			RemoveWhiteSpace = 0,
			MetMinus = 1,
			AddingUp = 2,
		};

		bool minus = false;
		int result = 0;
		state s = RemoveWhiteSpace;

		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ' || str[i] == '\t')
			{
				if (s == RemoveWhiteSpace)
				{
					continue;
				}
				else
				{
					return result;
				}
			}
			else if (str[i] == '+')
			{
				if (s == RemoveWhiteSpace)
				{
					s = MetMinus;
				}
				else
				{
					return result;
				}
			}
			else if (str[i] == '-')
			{
				if (s == RemoveWhiteSpace)
				{
					s = MetMinus;
					minus = true;
				}
				else
				{
					return result;
				}
			}
			else if (str[i] >= '0' && str[i] <= '9')
			{
				s = AddingUp;
				long long t1 = (long long)result * 10;
				result = t1;
				if (t1 != result)
				{
					return minus ? INT32_MIN : INT32_MAX;
				}
				if (minus)
				{
					t1 = (long long)result + '0' - str[i];
				}
				else
				{
					t1 = (long long)result + str[i] - '0';
				}
				result = t1;
				if (t1 != result)
				{
					return minus ? INT32_MIN : INT32_MAX;
				}
			}
			else
			{
				return result;
			}
		}

		return result;
	}
};

void Test()
{
	Solution lSolution;
	assert(lSolution.myAtoi("  ") == 0);
	assert(lSolution.myAtoi("  a") == 0);
	assert(lSolution.myAtoi("  1") == 1);
	assert(lSolution.myAtoi("  1aa") == 1);
	assert(lSolution.myAtoi("  -1") == -1);
	assert(lSolution.myAtoi("  -1aa") == -1);
	assert(lSolution.myAtoi("  +1") == 1);
	assert(lSolution.myAtoi("  +1aa") == 1);
	assert(lSolution.myAtoi("  ++1aa") == 0);
	assert(lSolution.myAtoi("  +-1aa") == 0);
	assert(lSolution.myAtoi("  --1aa") == 0);
	assert(lSolution.myAtoi("  -+1aa") == 0);
	assert(lSolution.myAtoi("  2147483646aa") == 2147483646);
	assert(lSolution.myAtoi("  2147483648aa") == INT32_MAX);
	assert(lSolution.myAtoi("  -2147483647aa") == -2147483647);
	assert(lSolution.myAtoi("  -2147483649aa") == INT32_MIN);
	assert(lSolution.myAtoi("      -11919730356x") == INT32_MIN);
}