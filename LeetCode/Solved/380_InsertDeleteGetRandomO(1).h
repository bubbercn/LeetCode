#pragma once
#include "Common.h"

class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        auto [it, succeeded] = index.emplace(val, values.size());
        if (!succeeded)
            return false;

        values.emplace_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
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

    /** Get a random element from the set. */
    int getRandom()
    {
        mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        uniform_int_distribution<> distrib(0, values.size() - 1);
        return values[distrib(gen)];
    }

private:
    unordered_map<int, int> index;
    vector<int> values;
    random_device rd;
};

class LeetCodeTest : public testing::Test
{
};

TEST_F(LeetCodeTest, Example1)
{
    RandomizedSet rSet;

    EXPECT_EQ(rSet.insert(1), true);

    EXPECT_EQ(rSet.remove(2), false);

    EXPECT_EQ(rSet.insert(2), true);

    EXPECT_PRED1([](int val) { return val == 1 || val == 2; }, rSet.getRandom());

    EXPECT_EQ(rSet.remove(1), true);

    EXPECT_EQ(rSet.insert(2), false);

    EXPECT_EQ(rSet.getRandom(), 2);
}
