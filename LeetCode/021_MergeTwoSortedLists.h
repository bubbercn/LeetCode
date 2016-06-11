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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (!l1)
		{
			return l2;
		}
		else if (!l2)
		{
			return l1;
		}
		
		ListNode* lHead = new ListNode(-1);
		ListNode* lTemp = lHead;
		
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				lTemp->next = l1;
				lTemp = l1;
				l1 = l1->next;
			}
			else
			{
				lTemp->next = l2;
				lTemp = l2;
				l2 = l2->next;
			}
		}
		
		while (l1)
		{
			lTemp->next = l1;
			lTemp = l1;
			l1 = l1->next;
		}
		
		while (l2)
		{
			lTemp->next = l2;
			lTemp = l2;
			l2 = l2->next;
		}
		
		lTemp = lHead->next;
		delete lHead;
		return lTemp;
	}
};

void Test()
{
	
}