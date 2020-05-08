#pragma once
#include "Common.h"

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data.emplace(x);
        if (min.empty() || x <= min.top())
        {
            min.emplace(x);
        }
    }
    
    void pop() {
        if (data.top() == min.top())
        {
            min.pop();
        }
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();
    }
private:
    stack<int> data;
    stack<int> min;
};

void Test()
{
    
}
