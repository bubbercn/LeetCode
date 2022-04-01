#pragma once
#include "Common.h"

class MyHashMap
{
public:
    MyHashMap() : data(1000001, -1)
    {
    }

    void put(int key, int value)
    {
        data[key] = value;
    }

    int get(int key)
    {
        return data[key];
    }

    void remove(int key)
    {
        data[key] = -1;
    }

private:
    vector<int> data;
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
    MyHashMap myHashMap;
    myHashMap.put(1, 1);
    myHashMap.put(2, 2);
    EXPECT_EQ(myHashMap.get(1), 1);
    EXPECT_EQ(myHashMap.get(3), -1);
    myHashMap.put(2, 1);
    EXPECT_EQ(myHashMap.get(2), 1);
    myHashMap.remove(2);
    EXPECT_EQ(myHashMap.get(2), -1);
}