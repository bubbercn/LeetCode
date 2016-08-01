#pragma once
#include "Common.h"

class Solution
{
public:
	int divide(int dividend, int divisor)
	{
		if (divisor == 0)
			return 1/0;
		
		if (dividend == INT_MIN && divisor == -1)
			return INT_MAX;
		
		if (divisor < 0)
		{
			mDividend = static_cast<long long>(0) - dividend;
			mDivisor = static_cast<long long>(0) - divisor;
		}
		else
		{
			mDividend = dividend;
			mDivisor = divisor;
		}
		
		if (mDividend > 0)
		{
			return static_cast<int>(findresult(0, mDividend));
		}
		else
		{
			return static_cast<int>(findresult(mDividend, 0));
		}
	}
	
private:
	long long findresult(long long iMin, long long iMax)
	{
		if (iMin == iMax)
			return iMin;
		
		if (iMin + 1 == iMax)
		{
			if (abs(iMax) > abs(iMin))
			{
				if (abs(multiply(iMax)) <= abs(mDividend))
				{
					return iMax;
				}
				else
				{
					return iMin;
				}
			}
			else
			{
				if (abs(multiply(iMin)) <= abs(mDividend))
				{
					return iMin;
				}
				else
				{
					return iMax;
				}
			}
		}
		
		long long lMid = (iMin + iMax) >> 1;
		
		if (multiply(lMid) < mDividend)
		{
			return findresult(lMid, iMax);
		}
		else
		{
			return findresult(iMin, lMid);
		}
	}
	
	long long multiply(long long base)
	{
		long long result = 0;
		if (mDivisor < abs(base))
		{
			for (int i = 0; i < mDivisor; i++)
			{
				result += base;
				if (abs(result) > abs(mDividend))
					return result;
			}
		}
		else
		{
			if (base < 0)
			{
				mDivisor = 0 - mDivisor;
			}
			for (int i = 0; i < abs(base); i++)
			{
				result += mDivisor;
				if (abs(result) > abs(mDividend))
				{
					if (base < 0)
					{
						mDivisor = 0 - mDivisor;
					}
					return result;
				}
			}
			if (base < 0)
			{
				mDivisor = 0 - mDivisor;
			}
		}
		return result;
	}
	
	long long mDividend, mDivisor;
};

void Test()
{
	Solution lSolution;
//	cout << lSolution.divide(1004958205, -2137325331) << endl;
	assert(lSolution.divide(6, 3) == 2);
	assert(lSolution.divide(-6, 3) == -2);
	assert(lSolution.divide(6, -3) == -2);
	assert(lSolution.divide(INT_MAX, 5) == INT_MAX / 5);
	assert(lSolution.divide(INT_MIN, -1) == INT_MAX);
	assert(lSolution.divide(5, 2) == 2);
	return;
}