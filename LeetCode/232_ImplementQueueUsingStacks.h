#pragma once
#include "Common.h"

class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        in.emplace(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        populate();
        int front = out.top();
        out.pop();
        return front;
    }

    /** Get the front element. */
    int peek()
    {
        populate();
        return out.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return in.empty() && out.empty();
    }

private:
    stack<int> in;
    stack<int> out;
    void populate()
    {
        if (out.empty())
        {
            while (!in.empty())
            {
                out.emplace(in.top());
                in.pop();
            }
        }
    }
};

void Test()
{
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
}
