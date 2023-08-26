#pragma once
#include "Common.h"

// Definition for a Node.
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        helper(head);
        return head;
    }

private:
    Node *helper(Node *head)
    {
        Node* tail = nullptr;
        while (head != nullptr)
        {
            if (head->child != nullptr)
            {
                Node* childTail = helper(head->child);
                childTail->next = head->next;
                if (head->next != nullptr)
                    head->next->prev = childTail;
                head->next = head->child;
                head->child->prev = head;
                head->child = nullptr;
                head = childTail;
            }
            if (head->next == nullptr)
                tail = head;
            head = head->next;
        }
        return tail;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};
