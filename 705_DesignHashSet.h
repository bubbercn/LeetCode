#pragma once
#include "Common.h"

class MyHashSet
{
public:
    MyHashSet()
    {
    }

    void add(int key)
    {
        data.set(key);
    }

    void remove(int key)
    {
        data.reset(key);
    }

    bool contains(int key)
    {
        return data.test(key);
    }

private:
    bitset<1000001> data;
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
    MyHashSet myHashSet;
    myHashSet.add(1);
    myHashSet.add(2);
    EXPECT_TRUE(myHashSet.contains(1));
    EXPECT_FALSE(myHashSet.contains(3));
    myHashSet.add(2);
    EXPECT_TRUE(myHashSet.contains(2));
    myHashSet.remove(2);
    EXPECT_FALSE(myHashSet.contains(2));
}