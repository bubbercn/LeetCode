#pragma once
#include "Common.h"

class MapSum
{
public:
    MapSum()
    {
    }

    void insert(const string &key, int val)
    {
        auto [it, inserted] = KVMap.emplace(key, val);
        if (!inserted)
        {
            it->second = val;
        }
        else
        {
            for (int i = 1; i <= key.size(); i++)
            {
                lookup[key.substr(0, i)].emplace_back(it);
            }
        }
    }

    int sum(const string &prefix)
    {
        if (auto i = lookup.find(prefix); i != lookup.end())
        {
            int sum = 0;
            for (auto &j : i->second)
            {
                sum += j->second;
            }
            return sum;
        }
        return 0;
    }

private:
    unordered_map<string, list<unordered_map<string, int>::const_iterator>> lookup;
    unordered_map<string, int> KVMap;
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
    MapSum mapSum;
    mapSum.insert("apple", 3);
    EXPECT_EQ(mapSum.sum("ap"), 3);
    mapSum.insert("app", 2);
    EXPECT_EQ(mapSum.sum("ap"), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    MapSum mapSum;
    mapSum.insert("apple", 3);
    EXPECT_EQ(mapSum.sum("ap"), 3);
    mapSum.insert("app", 2);
    mapSum.insert("apple", 2);
    EXPECT_EQ(mapSum.sum("ap"), 4);
}