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
    void inc(const string& key)
    {
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(const string& key)
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
    obj->dec("key1");
    obj->inc("key2");
    EXPECT_EQ(obj->getMaxKey(), "key1");
    EXPECT_EQ(obj->getMinKey(), "key2");
}