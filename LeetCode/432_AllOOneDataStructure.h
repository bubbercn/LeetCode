#pragma once
#include "Common.h"

class AllOne
{
public:
    /** Initialize your data structure here. */
    AllOne()
    {
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(const string &key)
    {
        auto it = key2ValueOrderMap.find(key);
        if (it == key2ValueOrderMap.end())
        {
            if (valueOrderList.empty() || valueOrderList.back().first != 1)
            {
                valueOrderList.emplace_back(1, unordered_set<string>({key}));
            }
            else
            {
                valueOrderList.back().second.insert(key);
            }
            key2ValueOrderMap[key] = --valueOrderList.end();
        }
        else
        {
            int value = it->second->first;
            it->second->second.erase(key);
            if (it->second->second.empty())
            {
                it->second = valueOrderList.erase(it->second);
            }
            if (it->second == valueOrderList.end())
            {
                valueOrderList.emplace_back(value + 1, unordered_set<string>({key}));
                it->second == --valueOrderList.end();
            }
            else if (it->second == valueOrderList.begin())
            {

            }
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(const string &key)
    {

    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey()
    {
        return {};
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey()
    {
        return {};
    }

private:
    unordered_map<string, list<pair<int, unordered_set<string>>>::iterator> key2ValueOrderMap;
    list<pair<int, unordered_set<string>>> valueOrderList;
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
    unique_ptr<AllOne> obj(new AllOne());
    obj->inc("key1");
    obj->inc("key1");
    obj->inc("key1");
    obj->dec("key1");
    obj->inc("key2");
    EXPECT_EQ(obj->getMaxKey(), "key1");
    EXPECT_EQ(obj->getMinKey(), "key2");
}

TEST_F(LeetCodeTest, Failure1)
{
    unique_ptr<AllOne> obj(new AllOne());
    obj->inc("a");
    obj->inc("b");
    obj->inc("b");
    obj->inc("c");
    obj->inc("c");
    obj->inc("c");
    obj->dec("b");
    obj->dec("b");
    EXPECT_EQ(obj->getMinKey(), "a");
    obj->dec("a");
    EXPECT_EQ(obj->getMaxKey(), "c");
    EXPECT_EQ(obj->getMinKey(), "c");
}