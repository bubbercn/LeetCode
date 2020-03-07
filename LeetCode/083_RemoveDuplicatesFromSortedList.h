#pragma once
#include "Common.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* current = head;
        ListNode* previous = nullptr;
        int currentValue = 0;
        bool first = true;

        while (current)
        {
            if (first)
            {
                currentValue = current->val;
                previous = current;
                first = false;
            }
            else
            {
                if (current->val != currentValue)
                {
                    currentValue = current->val;
                    previous = current;
                }
                else
                {
                    previous->next = current->next;
                    current = previous;
                }
            }
            current = current->next;
        }

        return head;
    }
};

void Test()
{
    Solution solution;
    vector<int> values = {1,1,2};
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