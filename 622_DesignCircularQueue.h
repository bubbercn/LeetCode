#pragma once
#include "Common.h"

class MyCircularQueue
{
public:
    MyCircularQueue(int k)
    {
        values.resize(k);
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;

        values[end++] = value;
        end %= values.size();
        empty = false;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        begin++;
        begin %= values.size();
        if (begin == end)
            empty = true;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return values[begin];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return values[(end - 1 + values.size()) % values.size()];
    }

    bool isEmpty()
    {
        return empty;
    }

    bool isFull()
    {
        return (begin == end) && (!empty);
    }

private:
    vector<int> values;
    int begin = 0;
    int end = 0;
    bool empty = true;
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
    EXPECT_TRUE(myCircularQueue.enQueue(1));  // return True
    EXPECT_TRUE(myCircularQueue.enQueue(2));  // return True
    EXPECT_TRUE(myCircularQueue.enQueue(3));  // return True
    EXPECT_FALSE(myCircularQueue.enQueue(4)); // return False
    EXPECT_EQ(myCircularQueue.Rear(), 3);     // return 3
    EXPECT_TRUE(myCircularQueue.isFull());    // return True
    EXPECT_TRUE(myCircularQueue.deQueue());   // return True
    EXPECT_TRUE(myCircularQueue.enQueue(4));  // return True
    EXPECT_EQ(myCircularQueue.Rear(), 4);     // return 4
}
