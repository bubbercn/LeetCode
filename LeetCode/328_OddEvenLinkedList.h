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

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
            return head;

        int numOfNodes = 0;
        ListNode *tail = nullptr;
        ListNode *node = head;
        while (node != nullptr)
        {
            numOfNodes++;
            if (node->next == nullptr)
                tail = node;
            node = node->next;
        }

        bool isOdd = false;
        ListNode *preNode = head;
        node = preNode->next;
        int count = 1;
        while (count++ < numOfNodes)
        {
            if (isOdd)
            {
                preNode = node;
                node = node->next;
            }
            else
            {
                if (node != tail)
                {
                    preNode->next = node->next;
                    tail->next = node;
                    node->next = nullptr;
                    tail = node;
                    node = preNode->next;
                }
            }
            isOdd = !isOdd;
        }

        return head;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> values = {1, 2, 3, 4, 5};
    vector<unique_ptr<ListNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new ListNode(*i));
    }
    for (int i = 0; i < nodes.size() - 1; i++)
    {
        nodes[i]->next = nodes[i + 1].get();
    }
    solution.oddEvenList(nodes[0].get());
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> values = {1, 2};
    vector<unique_ptr<ListNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new ListNode(*i));
    }
    for (int i = 0; i < nodes.size() - 1; i++)
    {
        nodes[i]->next = nodes[i + 1].get();
    }
    solution.oddEvenList(nodes[0].get());
}
