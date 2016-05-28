#pragma once
#include "Common.h"

class Solution
{
public:
	bool isValid(string s)
	{
		
		for (int i = 0; i < s.length(); i++)
		{
			switch (s[i])
			{
				case '(':
				case '[':
				case '{':
					mStack.push(s[i]);
					break;
					
				case ')':
				case ']':
				case '}':
					if(!popOut(s[i]))
					{
						return false;
					}
					break;
					
				default:
					break;
			}
		}
		
		if (mStack.empty())
		{
			return true;
		}
		
		return false;
	}
	
private:
	bool popOut(char c)
	{
		char target = 0;
		switch (c)
		{
			case ')':
				target = '(';
				break;
				
			case ']':
				target = '[';
				break;
				
			case '}':
				target = '{';
				break;
				
			default:
				break;
		}
		
		if (!mStack.empty() && mStack.top() == target)
		{
			mStack.pop();
			return true;
		}
		
		return false;
	}
	
	stack<char> mStack;
};

void Test()
{
	Solution lSolution;
	
	string s = "()";
	assert(lSolution.isValid(s) == true);
	
	s = "()[]{}";
	assert(lSolution.isValid(s) == true);
	
	s = "(]";
	assert(lSolution.isValid(s) == false);
	
	s = "([)]";
	assert(lSolution.isValid(s) == false);
	return;
}