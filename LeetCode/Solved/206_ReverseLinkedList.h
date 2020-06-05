#pragma once
#include "Common.h"

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// class Solution
// {
// public:
//     ListNode *reverseList(ListNode *head)
//     {
//         if (head == nullptr)
//             return nullptr;

//         helper(head);

//         return newHead;
//     }

// private:
//     ListNode *helper(ListNode *head)
//     {
//         if (head->next == nullptr)
//             return newHead = head;

//         ListNode *tail = helper(head->next);
//         tail->next = head;
//         head->next = nullptr;
//         return head;
//     }
//     ListNode *newHead;
// };

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        
        stack<ListNode*> nodeStack;
        while (head->next != nullptr)
        {
            nodeStack.emplace(head);
            head = head->next;
        }
        
        ListNode* curNode = head;
        while (!nodeStack.empty())
        {
            curNode->next = nodeStack.top();
            curNode = curNode->next;
            nodeStack.pop();
        }

        curNode->next = nullptr;

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
    solution.reverseList(nodes[0].get());
}