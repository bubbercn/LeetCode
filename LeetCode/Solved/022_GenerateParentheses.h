#pragma once
#include "Common.h"

class Solution
{
public:
	vector<string> generateParenthesis(int n)
	{
		mResult.clear();
		mNumOfLeft = mNumOfRight = 0;
		mQueue.empty();
		mN = n;
		hGenerateParaenthesis();
		return mResult;
	}
	
private:
	void hGenerateParaenthesis()
	{
		if (mNumOfRight == mN)
		{
			string lTemp(mQueue.begin(), mQueue.end());
			mResult.push_back(lTemp);
		}
		
		if (mNumOfLeft < mN)
		{
			mQueue.push_back('(');
			mNumOfLeft++;
			hGenerateParaenthesis();
			mQueue.pop_back();
			mNumOfLeft--;
		}
		
		if (mNumOfRight < mNumOfLeft && mNumOfRight < mN)
		{
			mQueue.push_back(')');
			mNumOfRight++;
			hGenerateParaenthesis();
			mQueue.pop_back();
			mNumOfRight--;
		}
	}
	
	int mN;
	int mNumOfLeft;
	int mNumOfRight;
	vector<string> mResult;
	deque<char> mQueue;
};

void Test()
{
	Solution lSolution;
	vector<string> lResult = lSolution.generateParenthesis(3);
	for (auto& i : lResult)
	{
		cout << i << endl;
	}
	return;
}