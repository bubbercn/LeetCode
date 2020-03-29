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
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        ListNode fakeHead(0);
        fakeHead.next = head;
        ListNode* before = nullptr;
        ListNode* after = nullptr;
        ListNode* cur = &fakeHead;
        for (int i = 1; i <= m; i++)
        {
            before = cur;
            cur = cur->next;
        }
        for (int i = m + 1; i <= n; i++)
        {
            cur = cur->next;
        }
        after = cur->next;
        reverse(before->next, after);
        before->next = cur; 
        return fakeHead.next;
    }

private:
    ListNode* reverse(ListNode* head, ListNode* tail)
    {
        if (head->next == tail)
            return head;
        
        reverse(head->next, tail)->next = head;
        head->next = tail;
        return head;
    }
};

void Test()
{
    Solution solution;
    vector<int> values = {1,2,3,4,5};
    vector<unique_ptr<ListNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new ListNode(*i));
    }
    for (int i = 0; i < nodes.size() - 1; i++)
    {
        nodes[i]->next = nodes[i+1].get();
    }
    solution.reverseBetween(nodes[0].get(), 2, 4);
}