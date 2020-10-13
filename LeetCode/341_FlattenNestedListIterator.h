#pragma once
#include "Common.h"

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const
    {
        return valueList.empty();
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const
    {
        return value;
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const
    {
        return valueList;
    }

private:
    int value;
    vector<NestedInteger> valueList;
};

class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
    }

    int next()
    {
    }

    bool hasNext()
    {
    }
};

class Solution
{
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{

}