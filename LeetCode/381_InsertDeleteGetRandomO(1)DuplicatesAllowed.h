#pragma once
#include "Common.h"

class RandomizedCollection
{
public:
    /** Initialize your data structure here. */
    RandomizedCollection()
    {
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        bool notExist = index.find(val) == index.end()
        index.emplace(val, values.size());
        values.emplace_back(val);
        return notExist;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        auto it = index.find(val);
        if (it == index.end())
            return false;
        
        values[it->second] = values.back();
        index[values.back()] = it->second;
        index.erase(it);
        values.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        return 0;
    }

private:
    unordered_multimap<int, int> index;
    vector<int> values;
};

class LeetCodeTest : public testing::Test
{
};

TEST_F(LeetCodeTest, Example1)
{
    RandomizedCollection rCollection;

    EXPECT_EQ(rCollection.insert(1), true);

    EXPECT_EQ(rCollection.insert(1), false);

    EXPECT_EQ(rCollection.insert(2), true);

    EXPECT_PRED1([](int val) { return val == 1 || val == 2; }, rCollection.getRandom());

    EXPECT_EQ(rCollection.remove(1), true);

    EXPECT_PRED1([](int val) { return val == 1 || val == 2; }, rCollection.getRandom());
}
