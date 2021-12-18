#pragma once
#include "Common.h"

class MyCircularDeque
{
public:
    MyCircularDeque(int k)
    {
        data.assign(k, 0);
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        front = decIndex(front);
        data[front] = value;
        empty = false;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        data[rear] = value;
        rear = incIndex(rear);
        empty = false;
        return true;
    }

    bool deleteFront()
    {
        if (empty)
            return false;
        front = incIndex(front);
        empty = (front == rear);
        return true;
    }

    bool deleteLast()
    {
        if (empty)
            return false;
        rear = decIndex(rear);
        empty = (front == rear);
        return true;
    }

    int getFront()
    {
        if (empty)
            return -1;
        return data[front];
    }

    int getRear()
    {
        if (empty)
            return -1;
        return data[decIndex(rear)];
    }

    bool isEmpty()
    {
        return empty;
    }

    bool isFull()
    {
        return front == rear && !empty;
    }

private:
    int incIndex(int index)
    {
        index++;
        if (index == data.size())
            return 0;
        return index;
    }
    int decIndex(int index)
    {
        index--;
        if (index == -1)
            return data.size() - 1;
        return index;
    }
    vector<int> data;
    bool empty = true;
    int front = 0;
    int rear = 0;
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
    MyCircularDeque myCircularDeque = MyCircularDeque(3);
    EXPECT_EQ(myCircularDeque.insertLast(1), true);
    EXPECT_EQ(myCircularDeque.insertLast(2), true);
    EXPECT_EQ(myCircularDeque.insertFront(3), true);
    EXPECT_EQ(myCircularDeque.insertFront(4), false);
    EXPECT_EQ(myCircularDeque.getRear(), 2);
    EXPECT_EQ(myCircularDeque.isFull(), true);
    EXPECT_EQ(myCircularDeque.deleteLast(), true);
    EXPECT_EQ(myCircularDeque.insertFront(4), true);
    EXPECT_EQ(myCircularDeque.getFront(), 4);
}

TEST_F(LeetCodeTest, Failure1)
{
    MyCircularDeque myCircularDeque = MyCircularDeque(3);
    EXPECT_EQ(myCircularDeque.insertFront(9), true);
    EXPECT_EQ(myCircularDeque.getRear(), 9);
    EXPECT_EQ(myCircularDeque.insertFront(9), true);
    EXPECT_EQ(myCircularDeque.getRear(), 9);
    EXPECT_EQ(myCircularDeque.insertLast(5), true);
    EXPECT_EQ(myCircularDeque.getFront(), 9);
    EXPECT_EQ(myCircularDeque.getRear(), 5);
    EXPECT_EQ(myCircularDeque.getFront(), 9);
    EXPECT_EQ(myCircularDeque.insertLast(8), false);
    EXPECT_EQ(myCircularDeque.deleteLast(), true);
    EXPECT_EQ(myCircularDeque.getFront(), 9);
}
