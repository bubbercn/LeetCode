#pragma once
#include "Common.h"

class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        stack.emplace(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        queue<int> temp;
        while (stack.size() > 1)
        {
            temp.push(stack.front());
            stack.pop();
        }
        stack.swap(temp);
        return temp.front();
    }

    /** Get the top element. */
    int top()
    {
        return stack.back();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return stack.empty();
    }
    queue<int> stack;
};

void Test()
{
}
