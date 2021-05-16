#pragma once
#include "Common.h"

class cacheCache
{
public:
    cacheCache(int capacity)
    {
    }

    int get(int key)
    {
        return 0;
    }

    void put(int key, int value)
    {
    }
};

class LeetCodeTest : public testing::Test
{
};

TEST_F(LeetCodeTest, Example1)
{
    cacheCache cache(2);
    cache.put(1, 1);             // cache=[1,_], cnt(1)=1
    cache.put(2, 2);             // cache=[2,1], cnt(2)=1, cnt(1)=1
    EXPECT_EQ(cache.get(1), 1);  // return 1
                                 // cache=[1,2], cnt(2)=1, cnt(1)=2
    cache.put(3, 3);             // 2 is the cache key because cnt(2)=1 is the smallest, invalidate 2.
                                 // cache=[3,1], cnt(3)=1, cnt(1)=2
    EXPECT_EQ(cache.get(2), -1); // return -1 (not found)
    EXPECT_EQ(cache.get(3), 3);  // return 3
                                 // cache=[3,1], cnt(3)=2, cnt(1)=2
    cache.put(4, 4);             // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                                 // cache=[4,3], cnt(4)=1, cnt(3)=2
    EXPECT_EQ(cache.get(1), -1); // return -1 (not found)
    EXPECT_EQ(cache.get(3), 3);  // return 3
                                 // cache=[3,4], cnt(4)=1, cnt(3)=3
    EXPECT_EQ(cache.get(4), 4);  // return 4
                                 // cache=[3,4], cnt(4)=2, cnt(3)=3
}