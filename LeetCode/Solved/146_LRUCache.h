#pragma once
#include "Common.h"

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }
    
    int get(int key)
    {
        auto it = cache.find(key);
        if (it == cache.end())
        {
            return -1;
        }
        else
        {
            prioritize(key);
            return it->second;
        }
    }
    
    void put(int key, int value)
    {
        auto it = cache.find(key);
        if (it == cache.end())
        {
            if (cache.size() == capacity)
            {
                remove(LRUList.front());
            }
            add(key, value);
        }
        else
        {
            it->second = value;
            prioritize(key);
        }
    };
    
private:
    unordered_map<int, int> cache;
    unordered_map<int, list<int>::iterator> lookUp;
    list<int> LRUList;
    int capacity;
    
    inline void remove(int key)
    {
        cache.erase(key);
        lookUp.erase(key);
        LRUList.pop_front();
    }
    
    inline void add(int key, int value)
    {
        LRUList.emplace_back(key);
        lookUp[key] = --LRUList.end();
        cache[key] = value;
    }
    
    void prioritize(int key)
    {
        auto it = lookUp.find(key);
        if (it != lookUp.end())
        {
            LRUList.erase(it->second);
        }
            
        LRUList.emplace_back(key);
        lookUp[key] = --LRUList.end();
    }
};

void Test()
{
    unique_ptr<LRUCache> cache(new LRUCache( 2 /* capacity */ ));

    cache->put(1, 1);
    cache->put(2, 2);
    assert(cache->get(1) == 1);     // returns 1
    cache->put(3, 3);               // evicts key 2
    assert(cache->get(2) == -1);    // returns -1 (not found)
    cache->put(4, 4);               // evicts key 1
    assert(cache->get(1) == -1);    // returns -1 (not found)
    assert(cache->get(3) == 3);     // returns 3
    assert(cache->get(4) == 4);     // returns 4
}
