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

    int value;
    vector<NestedInteger> valueList;
};

class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        const vector<NestedInteger> *temp = &nestedList;
        _next.emplace(*temp, -1);
        dfs();
    }

    int next()
    {
        int result = _next.top().first[_next.top().second].getInteger();
        dfs();
        return result;
    }

    bool hasNext()
    {
        return !_next.empty();
    }

private:
    void dfs()
    {
        while(!_next.empty())
        {
            const vector<NestedInteger>& temp = _next.top().first;
            size_t& pos = _next.top().second;
            pos++;
            if (pos == temp.size())
            {
                _next.pop();
            }
            else if (!temp[pos].isInteger())
            {
                _next.emplace(temp[pos].getList(), -1);
            }
            else
            {
                break;
            }
        }
    }
    stack<pair<const vector<NestedInteger> &, size_t>> _next;
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
    NestedInteger L1;

    NestedInteger L11;
    NestedInteger L111;
    L111.value = 1;
    NestedInteger L112;
    L112.value = 1;
    L11.valueList.emplace_back(L111);
    L11.valueList.emplace_back(L112);

    NestedInteger L12;
    L12.value = 2;

    NestedInteger L13;
    NestedInteger L131;
    L131.value = 1;
    NestedInteger L132;
    L132.value = 1;
    L13.valueList.emplace_back(L131);
    L13.valueList.emplace_back(L132);

    L1.valueList.emplace_back(L11);
    L1.valueList.emplace_back(L12);
    L1.valueList.emplace_back(L13);

    NestedIterator i(L1.valueList);
    while (i.hasNext())
        cout << i.next() << ', ';
}