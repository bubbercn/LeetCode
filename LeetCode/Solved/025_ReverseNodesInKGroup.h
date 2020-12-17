#pragma once
#include "Common.h"

//  Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x = 0) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		int lCount = 0;
		ListNode* lpTemp = head;
		
		while (lpTemp)
		{
			lCount++;
			if (lCount == k)
				break;
			
			lpTemp = lpTemp->next;
		}
		
		if (lCount == k)
		{
			ListNode* lpSubHead = reverseKGroup(lpTemp->next, k);
			ReverseList(head, lpTemp)->next = lpSubHead;
			return lpTemp;
		}
		else
		{
			return head;
		}
	}
	
private:
	ListNode* ReverseList(ListNode* iHead, ListNode* iEnd)
	{
		if (iHead == iEnd)
		{
			return iHead;
		}
		else
		{
			ListNode* lSubEnd = ReverseList(iHead->next, iEnd);
			lSubEnd->next = iHead;
			return iHead;
		}
	}
};

void Test()
{
	ListNode* lNodes[5];
	
	for (int i = 0; i < 5; i++)
	{
		lNodes[i] = new ListNode(i + 1);
	}

	for (int i = 0; i < 4; i++)
	{
		lNodes[i]->next = lNodes[i + 1];
	}
	
	Solution lSolution;
	ListNode* lpHead = lSolution.reverseKGroup(lNodes[0], 2);
	
	return;
}