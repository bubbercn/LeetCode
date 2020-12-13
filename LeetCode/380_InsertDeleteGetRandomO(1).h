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
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        return false;
    }

    /** Get a random element from the set. */
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
    RandomizedSet rSet;

    EXPECT_EQ(rSet.insert(1), true);

    EXPECT_EQ(rSet.remove(2), false);

    EXPECT_EQ(rSet.insert(2), true);

    EXPECT_PRED1([](int val) {return val == 1 || val == 2;}, rSet.getRandom());

    EXPECT_EQ(rSet.remove(1), true);

    EXPECT_EQ(rSet.insert(2), false);

    EXPECT_EQ(rSet.getRandom(), 2);
}
