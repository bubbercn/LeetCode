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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode fakeHead(0);
        fakeHead.next = head;  
        ListNode* begin = &fakeHead;
        ListNode* current = head;
        ListNode* previous = nullptr;
        int currentValue = 0;
        bool first = true;
        bool toDelete = false;

        while (current)
        {
            if (first)
            {
                currentValue = current->val;
                first = false;
            }
            else
            {
                if (current->val != currentValue)
                {
                    currentValue = current->val;
                    if (toDelete)
                    {
                        begin->next = current;
                        toDelete = false;
                    }
                    else
                    {
                        begin = previous;
                    }
                }
                else
                {
                    toDelete = true;
                }
            }
            previous = current;
            current = current->next;
        }

        return fakeHead.next;
    }
};

void Test()
{
    Solution solution;
    vector<int> values = {1,2,3,3,4,4,5};
    vector<unique_ptr<ListNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new ListNode(*i));
    }
    for (int i = 0; i < nodes.size() - 1; i++)
    {
        nodes[i]->next = nodes[i+1].get();
    }
    solution.deleteDuplicates(nodes[0].get());
}