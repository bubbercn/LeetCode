#pragma once
#include "Common.h"

class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int nodeCount = getCount(head);
        int avg = nodeCount / k;
        int res = nodeCount % k;
        vector<ListNode *> result;
        for (int i = 0; i < k; i++)
        {
            result.emplace_back(head);
            if (head == nullptr)
                continue;
            int length = avg + (res > 0 ? 1 : 0);
            for (int i = 1; i < length; i++)
            {
                head = head->next;
            }
            ListNode *next = head->next;
            head->next = nullptr;
            head = next;
            res--;
        }
        return result;
    }

private:
    int getCount(ListNode *head)
    {
        int result = 0;
        while (head)
        {
            result++;
            head = head->next;
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};