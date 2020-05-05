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
    ListNode* insertionSortList(ListNode* head)
    {
        if (head == nullptr)
            return nullptr;
        
        ListNode fakeHead(0);
        fakeHead.next = head;
        ListNode* tail = &fakeHead;
        
        for (ListNode* i = head; i != nullptr; i = tail->next)
        {
            ListNode* j = &fakeHead;
            for (; j != tail; j = j->next)
            {
                if (i->val < j->next->val)
                {
                    tail->next = i->next;
                    i->next = j->next;
                    j->next = i;
                    break;
                }
            }
            if (j == tail)
            {
                tail = i;
            }
        }
        
        return fakeHead.next;
    }
};

void Test()
{
    Solution solution;
    
    vector<int> values = {1, 2, 3, 4};
    vector<unique_ptr<ListNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new ListNode(*i));
    }
    nodes[3]->next = nodes[1].get();
    nodes[1]->next = nodes[0].get();
    nodes[0]->next = nodes[2].get();
    
    solution.insertionSortList(nodes[3].get());
}


