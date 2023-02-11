#pragma once
#include "Common.h"

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
            if (fast->next)
                fast = fast->next;
        }
        return slow;
    }
};