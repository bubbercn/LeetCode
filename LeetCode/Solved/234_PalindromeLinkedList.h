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
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;

        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next)
        {
            fast = fast->next;
            if (!fast->next)
            {
                break;
            }
            else
            {
                fast = fast->next;
            }
            slow = slow->next;
        }

        ListNode* tempHead = reverseList(slow->next);
        bool result = true;
        for (fast = head, slow = tempHead; slow != nullptr; slow = slow->next, fast = fast->next)
        {
            if (fast->val != slow->val)
            {
                result = false;
                break;
            }
        }

        reverseList(tempHead);

        return result;
    }

    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        stack<ListNode *> nodeStack;
        while (head->next != nullptr)
        {
            nodeStack.emplace(head);
            head = head->next;
        }

        ListNode *curNode = head;
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
    vector<int> values = {1,2,2,1};
    vector<unique_ptr<ListNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new ListNode(*i));
    }
    for (int i = 0; i < nodes.size() - 1; i++)
    {
        nodes[i]->next = nodes[i+1].get();
    }
    solution.isPalindrome(nodes[0].get());
}