#pragma once
#include "Common.h"

class Solution 
{
public:
	int reverse(int x) 
	{
		bool minus = false;
		if (x < 0)
		{
			x = 0 - x;
			minus = true;
			if (x < 0)
				return 0;
		}
		int result = 0;
		
		queue<int> lDigits;
		while (x > 0)
		{
			lDigits.push(x % 10);
			x /= 10;
		}

		while (!lDigits.empty())
		{
			int temp = result * 10;
			if (temp / 10 != result)
				return 0;
			result = temp;
			if (result < 0)
				return 0;
			temp = result + lDigits.front();
			if (temp - lDigits.front() != result)
				return 0;
			result = temp;
			if (result < 0)
				return 0;
			lDigits.pop();
		}

		if (minus)
			return -result;

		return result;
	}
};

void Test()
{
	Solution lSolution;
	assert(lSolution.reverse(123) == 321);
	assert(lSolution.reverse(-123) == -321);
	assert(lSolution.reverse(10) == 1);
	assert(lSolution.reverse(1000000003) == 0);
	assert(lSolution.reverse(1534236469) == 0);
}
