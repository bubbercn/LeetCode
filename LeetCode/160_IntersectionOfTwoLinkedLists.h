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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        
        auto a = helper(headA);
        auto b = helper(headB);
        
        if (a.first != b.first)
            return nullptr;
    
        int diff = abs(a.second - b.second);
        if (a.second < b.second)
        {
            swap(headA, headB);
        }
        
        ListNode* pA = headA;
        for (int i = 0; i < diff; i++)
        {
            pA = pA->next;
        }
        
        ListNode* pB = headB;
        for (; pA != pB; pA = pA->next, pB = pB->next)
        {
            
        }
        return pA;
    }
private:
    pair<ListNode*, int> helper(ListNode* head)
    {
        int length = 0;
        while (true)
        {
            length++;
            if (head->next == nullptr)
                break;
            head = head->next;
        }
        return {head, length};
    }
};

void Test()
{
    
}
