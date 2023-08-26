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
        bool notExist = (index.find(val) == index.end());
        index.emplace(val, unordered_set<int>()).first->second.emplace(values.size());
        values.emplace_back(val);
        return notExist;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        auto it = index.find(val);
        if (it == index.end())
            return false;

        int i = *it->second.begin();
        values[i] = values.back();
        auto it2 = index.find(values.back());
        if (it == it2)
        {
            it->second.erase(values.size() - 1);
        }
        else
        {
            it2->second.erase(values.size() - 1);
            it2->second.emplace(i);
            it->second.erase(i);
        }
        if (it->second.empty())
            index.erase(it);
        values.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        uniform_int_distribution<> distrib(0, values.size() - 1);
        return values[distrib(gen)];
    }

private:
    unordered_map<int, unordered_set<int>> index;
    vector<int> values;
    random_device rd;
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

TEST_F(LeetCodeTest, Failure1)
{
    RandomizedCollection rCollection;

    EXPECT_EQ(rCollection.insert(1), true);

    EXPECT_EQ(rCollection.insert(1), false);

    EXPECT_EQ(rCollection.insert(2), true);

    EXPECT_EQ(rCollection.insert(1), false);

    EXPECT_EQ(rCollection.insert(2), false);

    EXPECT_EQ(rCollection.insert(2), false);

    EXPECT_EQ(rCollection.remove(1), true);

    EXPECT_EQ(rCollection.remove(2), true);

    EXPECT_EQ(rCollection.remove(2), true);

    EXPECT_EQ(rCollection.remove(2), true);
}

TEST_F(LeetCodeTest, Failure2)
{
    RandomizedCollection rCollection;

    EXPECT_EQ(rCollection.insert(0), true);

    EXPECT_EQ(rCollection.remove(0), true);

    EXPECT_EQ(rCollection.insert(-1), true);

    EXPECT_EQ(rCollection.remove(0), false);

    EXPECT_EQ(rCollection.getRandom(), -1);
}