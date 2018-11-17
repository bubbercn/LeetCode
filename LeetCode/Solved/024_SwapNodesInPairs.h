#pragma once
#include "Common.h"

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* swapPairs(ListNode* head)
	{
		if (head)
		{
			if (head->next)
			{
				ListNode* lSubHead = swapPairs(head->next->next);
				ListNode* lReturn = nullptr;
				lReturn = head->next;
				head->next->next = head;
				head->next = lSubHead;
				return lReturn;
			}
			else
			{
				return head;
			}
		}
		else
		{
			return nullptr;
		}
	}
};

void Test()
{
	return;
}