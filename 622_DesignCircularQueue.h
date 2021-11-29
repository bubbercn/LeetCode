#pragma once
#include "Common.h"

class MyCircularQueue
{
public:
    MyCircularQueue(int k)
    {
    }

    bool enQueue(int value)
    {
        return false;
    }

    bool deQueue()
    {
        return false;
    }

    int Front()
    {
        return 0;
    }

    int Rear()
    {
        return 0;
    }

    bool isEmpty()
    {
        return false;
    }

    bool isFull()
    {
        return false;
    }
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
    MyCircularQueue myCircularQueue(3);
    myCircularQueue.enQueue(1); // return True
    myCircularQueue.enQueue(2); // return True
    myCircularQueue.enQueue(3); // return True
    myCircularQueue.enQueue(4); // return False
    myCircularQueue.Rear();     // return 3
    myCircularQueue.isFull();   // return True
    myCircularQueue.deQueue();  // return True
    myCircularQueue.enQueue(4); // return True
    myCircularQueue.Rear();     // return 4
}
