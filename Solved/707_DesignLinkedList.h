#pragma once
#include "Common.h"

class MyLinkedList
{
public:
    MyLinkedList()
    {
    }

    int get(int index)
    {
        ListNode *node = head;
        while (node && index-- > 0)
        {
            node = node->next;
        }
        if (node)
            return node->val;
        return -1;
    }

    void addAtHead(int val)
    {
        ListNode *newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val)
    {
        if (!head)
        {
            addAtHead(val);
        }
        if (!head)
        {
            head = new ListNode(val);
            return;
        }
        ListNode *node = head;
        while (node->next)
        {
            node = node->next;
        }
        node->next = new ListNode(val);
    }

    void addAtIndex(int index, int val)
    {
        ListNode *node = head;
        ListNode *preNode = nullptr;
        while (index-- > 0)
        {
            if (node)
            {
                preNode = node;
                node = node->next;
            }
            else
            {
                return;
            }
        }
        if (preNode)
        {
            preNode->next = new ListNode(val);
            preNode->next->next = node;
        }
        else
        {
            addAtHead(val);
        }
    }

    void deleteAtIndex(int index)
    {
        ListNode *node = head;
        ListNode *preNode = nullptr;
        while (index-- > 0)
        {
            if (node)
            {
                preNode = node;
                node = node->next;
            }
            else
            {
                return;
            }
        }
        if (preNode)
        {
            preNode->next = node->next;
        }
        else
        {
            head = node->next;
        }
    }

private:
    //  Definition for singly-linked list.
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode *head = nullptr;
};

class Solution
{
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);
    EXPECT_EQ(myLinkedList.get(1), 2);
    myLinkedList.deleteAtIndex(1);
    EXPECT_EQ(myLinkedList.get(1), 3);
}

TEST_F(LeetCodeTest, Failure1)
{
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(7);
    myLinkedList.addAtHead(2);
    myLinkedList.addAtHead(1);
    myLinkedList.addAtIndex(3, 0);
    myLinkedList.deleteAtIndex(2);
    myLinkedList.addAtHead(6);
    myLinkedList.addAtTail(4);
    EXPECT_EQ(myLinkedList.get(4), 4);
    myLinkedList.addAtHead(4);
    myLinkedList.addAtIndex(5, 0);
    myLinkedList.addAtHead(6);
}