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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        
        ListNode* fast = head, * slow = head;
        int diff = 0;
        
        while (true)
        {
            if (travel(fast))
                return nullptr;
            
            if (travel(fast))
                return nullptr;
            
            if (travel(slow))
                return nullptr;
            
            diff++;
            
            if (fast == slow)
            {
                fast = slow = head;
                for (int i = 0; i < diff; i++)
                {
                    travel(fast);
                }
                while (fast != slow)
                {
                    travel(fast);
                    travel(slow);
                }
                return fast;
            }
        }
    }
private:
    inline bool travel(ListNode*& node)
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
