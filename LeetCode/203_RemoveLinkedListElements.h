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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode fakeHead(0);
        fakeHead.next = head;
        
        ListNode* preNode = &fakeHead;
        while (head != nullptr)
        {
            if (head->val == val)
            {
                preNode->next = head->next;
            }
            else
            {
                preNode = head;
            }
            head = head->next;
        }
        
        return fakeHead.next;
    }
};

void Test()
{
    
}
