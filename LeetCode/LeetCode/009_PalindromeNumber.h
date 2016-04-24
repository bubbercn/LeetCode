#pragma once
#include "Common.h"

class Solution 
{
public:
	bool isPalindrome(int x, int i_digit = -1) 
	{
		if (x < 0)
			return false;

		int temp = x;
		int digit = 1;
		int tail = temp % 10;
		int temp2 = 0;

		while ((temp2 = temp / 10) != 0)
		{
			digit++;
			temp = temp2;
		}

		int head = temp;
		if (i_digit != -1 && i_digit != digit)
		{
			head = 0;
			digit = i_digit;
		}

		if (digit == 1)
			return true;

		if (head == tail)
		{
			if (digit == 2)
			{
				return true;
			}
			else
			{
				x /= 10;
				for (int i = 1; i < digit - 1; i++)
				{
					head *= 10;
				}
				x -= head;
				return isPalindrome(x, digit - 2);
			}
		}
		else
		{
			return false;
		}
	}
};

void Test()
{
	Solution lSolution;
	assert(!lSolution.isPalindrome(-1));
	assert(lSolution.isPalindrome(0));
	assert(lSolution.isPalindrome(1));
	assert(lSolution.isPalindrome(11));
	assert(lSolution.isPalindrome(121));
	assert(lSolution.isPalindrome(1221));
	assert(!lSolution.isPalindrome(1000021));
}