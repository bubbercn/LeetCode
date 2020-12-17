#pragma once
#include "Common.h"

//  Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		vector<ListNode*> lHeads;
		lHeads.reserve(lists.size());
		for (auto i = lists.begin(); i != lists.end(); i++)
		{
			if (*i)
			{
				lHeads.push_back(*i);
			}
		}
		
		for (int i = (lHeads.size() >> 1) - 1; i >= 0; i--)
		{
			Heapify(lHeads, i);
		}
		
		ListNode* lMergedList = nullptr, * lCurrentNode = nullptr;
		
		while (!lHeads.empty())
		{
			if (lMergedList)
			{
				lCurrentNode = lCurrentNode->next = lHeads[0];
			}
			else
			{
				lMergedList = lCurrentNode = lHeads[0];
			}
			lHeads[0] = lHeads[0]->next;
			
			if (!lHeads[0])
			{
				lHeads[0] = *(lHeads.end() - 1);
				lHeads.erase(lHeads.end() - 1);
			}
			
			Heapify(lHeads, 0);
		}
		
		return lMergedList;
	}
	
private:
	void Heapify(vector<ListNode*>& ioHeads, int iParentIndex)
	{
		if ((iParentIndex << 1) + 1 >= ioHeads.size())
		{
			return;
		}
		else
		{
			int lSmallerChildIndex = 0;
			if ((iParentIndex + 1) << 1 >= ioHeads.size())
			{
				lSmallerChildIndex = (iParentIndex << 1) + 1;
			}
			else
			{
				lSmallerChildIndex = ioHeads[(iParentIndex << 1) + 1]->val < ioHeads[(iParentIndex + 1) << 1]->val ? (iParentIndex << 1) + 1 : (iParentIndex + 1) << 1;
			}
			
			if (ioHeads[iParentIndex]->val > ioHeads[lSmallerChildIndex]->val)
			{
				ListNode* lpSmallerChild = ioHeads[lSmallerChildIndex];
				ioHeads[lSmallerChildIndex] = ioHeads[iParentIndex];
				ioHeads[iParentIndex] =  lpSmallerChild;
				Heapify(ioHeads, lSmallerChildIndex);
			}
			else
			{
				return;
			}
		}
	}
};

void Test()
{
	for (int i = 0; i < 3; i++)
	{
		vector<ListNode*> lHeads;
		for (int j = 0; j <= i; j++)
		{
			ListNode* lpHead = new ListNode(j);
			lHeads.push_back(lpHead);
			ListNode* lpCurrentNode = lpHead;
			for (int k = 0; k < j; k++)
			{
				ListNode* lpNode = new ListNode(j + k + 1);
				lpCurrentNode = lpCurrentNode->next = lpNode;
			}
		}
		
		Solution lSolution;
		lSolution.mergeKLists(lHeads);
	}
	return;
}
