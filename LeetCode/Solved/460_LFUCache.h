#pragma once
#include "Common.h"

class LFUCache
{
public:
    LFUCache(int capacity) : capacity(capacity), minFrequency(0)
    {
    }

    int get(int key)
    {
        if (auto it = key2EntryMap.find(key); it == key2EntryMap.end())
        {
            return -1;
        }
        else
        {
            auto [key, frequency, value] = *(it->second);
            updateFrequency(it->second, false);
            return value;
        }
    }

    void put(int key, int value)
    {
        if (capacity == 0)
            return;

        if (auto it = key2EntryMap.find(key); it != key2EntryMap.end())
        {
            auto &[key, frequency, oldValue] = *(it->second);
            oldValue = value;
            updateFrequency(it->second, false);
        }
        else
        {
            if (key2EntryMap.size() == capacity)
            {
                auto [key, frequency, value] = *frequency2EntryListMap[minFrequency].begin();
                key2EntryMap.erase(key);
                updateFrequency(frequency2EntryListMap[minFrequency].begin(), true);
            }
            frequency2EntryListMap[1].emplace_back(key, 1, value);
            key2EntryMap[key] = --frequency2EntryListMap[1].end();
            minFrequency = 1;
        }
    }

private:
    using CacheEntry = tuple<int, int, int>;
    using CacheEntryList = list<CacheEntry>;
    int capacity, minFrequency;
    unordered_map<int, CacheEntryList::iterator> key2EntryMap;
    unordered_map<int, CacheEntryList> frequency2EntryListMap;
    void updateFrequency(CacheEntryList::iterator it, bool isDelete)
    {
        auto [key, frequency, value] = *it;
        auto &cacheEntryList = frequency2EntryListMap[frequency];
        cacheEntryList.erase(it);
        if (cacheEntryList.empty())
        {
            frequency2EntryListMap.erase(frequency);
            if (minFrequency == frequency)
            {
                minFrequency = isDelete ? 1 : minFrequency + 1;
            }
        }
        if (!isDelete)
        {
            frequency2EntryListMap[frequency + 1].emplace_back(key, frequency + 1, value);
            key2EntryMap[key] = --frequency2EntryListMap[frequency + 1].end();
        }
    }
};

class LeetCodeTest : public testing::Test
{
};

TEST_F(LeetCodeTest, Example1)
{
    LFUCache cache(2);
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