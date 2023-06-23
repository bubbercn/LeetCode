#pragma once
#include "Common.h"

class TimeMap
{
public:
    TimeMap()
    {
    }

    void set(string_view key, string_view value, int timestamp)
    {
        lookup[string(key)][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        auto &lookup = this->lookup[key];
        auto it = lookup.upper_bound(timestamp);
        if (it != lookup.end())
        {
            if (it != lookup.begin())
            {
                return prev(it)->second;
            }
            else
            {
                return {};
            }
        }
        else if (!lookup.empty())
        {
            return lookup.rbegin()->second;
        }
        else
        {
            return {};
        }
    }

private:
    unordered_map<string, map<int, string>> lookup;
};

class LeetCodeTest : public testing::Test
{
};

TEST_F(LeetCodeTest, Example1)
{
    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);             // store the key "foo" and value "bar" along with timestamp = 1.
    EXPECT_EQ(timeMap.get("foo", 1), "bar");  // return "bar"
    EXPECT_EQ(timeMap.get("foo", 3), "bar");  // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
    timeMap.set("foo", "bar2", 4);            // store the key "foo" and value "bar2" along with timestamp = 4.
    EXPECT_EQ(timeMap.get("foo", 4), "bar2"); // return "bar2"
    EXPECT_EQ(timeMap.get("foo", 5), "bar2"); // return "bar2"
}