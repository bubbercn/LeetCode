#pragma once
#include "Common.h"

class FreqStack
{
public:
    FreqStack()
    {
    }

    void push(int val)
    {
    }

    int pop()
    {
        return 0;
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
    FreqStack freqStack = FreqStack();
    freqStack.push(5);             // The stack is [5]
    freqStack.push(7);             // The stack is [5,7]
    freqStack.push(5);             // The stack is [5,7,5]
    freqStack.push(7);             // The stack is [5,7,5,7]
    freqStack.push(4);             // The stack is [5,7,5,7,4]
    freqStack.push(5);             // The stack is [5,7,5,7,4,5]
    EXPECT_EQ(freqStack.pop(), 5); // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
    EXPECT_EQ(freqStack.pop(), 7); // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
    EXPECT_EQ(freqStack.pop(), 5); // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
    EXPECT_EQ(freqStack.pop(), 4); // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
}