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
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		if (!head)
		{
			return nullptr;
		}
			
		ListNode* lpNode1 = head;
		ListNode* lpNode2 = head;
		
		for (int i = 0; i < n; i++)
		{
			lpNode1 = lpNode1->next;
			if (!lpNode1)
			{
				lpNode1 = head->next;
				delete head;
				return lpNode1;
			}
		}
		
		while (lpNode1->next)
		{
			lpNode1 = lpNode1->next;
			lpNode2 = lpNode2->next;
		}
		
		ListNode* lpTemp = lpNode2->next->next;
		delete lpNode2->next;
		lpNode2->next = lpTemp;
		
		return head;
	}
};

void Test()
{
	ListNode* lpHead = new ListNode(1);
	ListNode* lpTemp = lpHead;
	for (int i = 2 ; i <= 5; i++)
	{
		lpTemp->next = new ListNode(i);
		lpTemp = lpTemp->next;
	}
	
	Solution lSolution;
	assert((*lSolution.removeNthFromEnd(lpHead, 2)).val == 1);
	
	return;
}