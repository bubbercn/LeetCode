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
    bool hasCycle(ListNode* head)
    {
        if (head == nullptr)
            return false;
        
        ListNode* fast = head, * slow = head;
        
        while (true)
        {
            if (travel(fast))
                return false;
            
            if (travel(fast))
                return false;
            
            if (travel(slow))
                return false;
            
            if (fast == slow)
                return true;
        }
    }
private:
    bool travel(ListNode*& node)
    {
        node = node->next;
        if (node == nullptr)
            return true;
        
        return false;
    }
};

void Test()
{
    
}
