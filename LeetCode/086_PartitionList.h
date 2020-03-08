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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *smallHead = nullptr, *smallTal = nullptr;
        ListNode *largeHead = nullptr, *largeTail = nullptr;
        ListNode *next = head;

        while (next)
        {
            if (next->val < x)
            {
                if (!smallHead)
                {
                    smallHead = next;
                    smallTal = next;
                }
                else
                {
                    smallTal->next = next;
                    smallTal = next;
                }
            }
            else
            {
                if (!largeHead)
                {
                    largeHead = next;
                    largeTail = next;
                }
                else
                {
                    largeTail->next = next;
                    largeTail = next;
                }
            }
            ListNode* temp = next->next;
            next->next = nullptr;
            next = temp;
        }

        if (smallTal)
        {
            smallTal->next = largeHead;
            return smallHead;
        }
        else
        {
            return largeHead;
        }
    }
};

void Test()
{
    Solution solution;
    vector<int> values = {1, 4, 3, 2, 5, 2};
    vector<unique_ptr<ListNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new ListNode(*i));
    }
    for (int i = 0; i < nodes.size() - 1; i++)
    {
        nodes[i]->next = nodes[i + 1].get();
    }
    solution.partition(nodes[0].get(), 3);
}