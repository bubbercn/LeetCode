#pragma once
#include "Common.h"

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
    // Constructor initializes an empty nested list.
    NestedInteger()
    {
    }

    // Constructor initializes a single integer.
    NestedInteger(int value) : value(value)
    {
        _isInteger = true;
    }

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const
    {
        return _isInteger;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const
    {
        return value;
    }

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value)
    {
        this->value = value;
        _isInteger = true;
    }

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni)

    {
        list.emplace_back(ni);
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const
    {
        return list;
    }

private:
    int value = 0;
    vector<NestedInteger> list;
    bool _isInteger = false;
};

class Solution
{
public:
    NestedInteger deserialize(const string &s)
    {
        int begin = -1;
        int end = -1;
        NestedInteger result;
        stack<NestedInteger> resultStack;
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '[':
            {
                resultStack.emplace();
            }
            break;
            case ']':
            {
                if (begin != -1)
                {
                    resultStack.top().add(NestedInteger(stoi(s.substr(begin, i - begin))));
                    begin = -1;
                }
                result = resultStack.top();
                resultStack.pop();
                if (!resultStack.empty())
                {
                    resultStack.top().add(result);
                }
            }
            break;
            case ',':
            {
                if (begin != -1)
                {
                    resultStack.top().add(NestedInteger(stoi(s.substr(begin, i - begin))));
                    begin = -1;
                }
            }
            break;
            default:
            {
                if (begin == -1)
                {
                    begin = i;
                }
            }
            break;
            }
        }
        if (begin != -1)
        {
            result.setInteger(stoi(s.substr(begin)));
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    NestedInteger result = solution.deserialize("[123,[456,[789]]]");
    EXPECT_EQ(result.getList().size(), 2);
    EXPECT_EQ(result.getList().at(0).isInteger(), true);
    EXPECT_EQ(result.getList().at(0).getInteger(), 123);
}

TEST_F(LeetCodeTest, Case1)
{
    NestedInteger result = solution.deserialize("123");
    EXPECT_EQ(result.getInteger(), 123);
}

TEST_F(LeetCodeTest, Failure1)
{
    NestedInteger result = solution.deserialize("[[]]");
    EXPECT_EQ(result.getList().size(), 1);
    EXPECT_EQ(result.getList().at(0).isInteger(), false);
    EXPECT_EQ(result.getList().at(0).getList().size(), 0);
}

TEST_F(LeetCodeTest, Failure2)
{
    NestedInteger result = solution.deserialize("[[0]]");
    EXPECT_EQ(result.getList().size(), 1);
    EXPECT_EQ(result.getList().at(0).isInteger(), false);
    EXPECT_EQ(result.getList().at(0).getList().size(), 1);
}

TEST_F(LeetCodeTest, Failure3)
{
    NestedInteger result = solution.deserialize("[123,456,[788,799,833],[[]],10,[]]");
}
