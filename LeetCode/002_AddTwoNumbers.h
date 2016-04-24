#pragma once
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode* output = nullptr;
		ListNode* current = nullptr;
		bool addone = false;
		while (l1 || l2)
		{
			int lValue = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + (addone ? 1 : 0);
			if (lValue >= 10)
			{
				lValue -= 10;
				addone = true;
			}
			else
			{
				addone = false;
			}
			ListNode* temp = new ListNode(lValue);
			if (!output)
			{
				output = temp;
			}
			if (current)
			{
				current->next = temp;
			}
			current = temp;
			if (l1)
			{
				l1 = l1->next;
			}
			if (l2)
			{
				l2 = l2->next;
			}
		}
		if (addone)
		{
			ListNode* temp = new ListNode(1);
			current->next = temp;
		}
		return output;
	}
};

void Test()
{
	ListNode* l1 = nullptr;
	ListNode* temp = new ListNode(2);
	l1 = temp;
	temp->next = new ListNode(4);
	temp = temp->next;
	temp->next = new ListNode(3);

	ListNode* l2 = nullptr;
	temp = new ListNode(5);
	l2 = temp;
	temp->next = new ListNode(6);
	temp = temp->next;
	temp->next = new ListNode(4);

	ListNode* output;
	Solution lSolution;
	output = lSolution.addTwoNumbers(l1, nullptr);
	output = lSolution.addTwoNumbers(nullptr, l2);
	output = lSolution.addTwoNumbers(l1, l2);
}
