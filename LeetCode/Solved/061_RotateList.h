#pragma once
#include "Common.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        size_t length = getLength(head);
        if (length == 0)
            return nullptr;
        
        int offset = k % length;
        
        ListNode* p1;
        ListNode* p2;
        p1 = head;
        for (int i = 0; i < offset; i++)
        {
            p1 = p1->next;
        }
        p2 = head;
        while (p1->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = head;
        head = p2->next;
        p2->next = nullptr;
        
        return head;
    }
    
private:
    size_t getLength(ListNode* head)
    {
        size_t length = 0;
        while (head != nullptr)
        {
            length++;
            head = head->next;;
        }
        return length;
    }
};

void Test()
{
    ListNode* head = new ListNode(1);
    ListNode* tail = head;
    
    for (int i = 1; i <= 4; i++)
    {
        ListNode* p = new ListNode(i + 1);
        tail->next = p;
        tail = p;
    }
    
    Solution solution;
    solution.rotateRight(head, 2);
}
