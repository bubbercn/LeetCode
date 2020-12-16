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
        return false;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        return false;
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        return 0;
    }
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
