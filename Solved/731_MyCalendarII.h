#pragma once
#include "Common.h"

class MyCalendarTwo
{
public:
    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        if (auto it2 = leftMap2.lower_bound(end); leftMap2.empty() || it2 == leftMap2.begin() || (--it2)->second <= start)
        {
            auto it1 = leftMap1.lower_bound(end);
            while (!(leftMap1.empty() || it1 == leftMap1.begin() || (--it1)->second <= start))
            {
                pair<int, int> setUnion = {min(it1->first, start), max(it1->second, end)};
                pair<int, int> setInter = {max(it1->first, start), min(it1->second, end)};
                leftMap1.erase(it1);
                start = setUnion.first;
                end = setUnion.second;
                it1 = leftMap1.lower_bound(end);
                leftMap2.insert(it2, setInter);
            }
            leftMap1.emplace_hint(it1, start, end);
            return true;
        }
        return false;
    }

private:
    map<int, int> leftMap1;
    map<int, int> leftMap2;
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
    MyCalendarTwo myCalendar;
    EXPECT_TRUE(myCalendar.book(10, 20));
    EXPECT_TRUE(myCalendar.book(50, 60));
    EXPECT_TRUE(myCalendar.book(10, 40));
    EXPECT_FALSE(myCalendar.book(5, 15));
    EXPECT_TRUE(myCalendar.book(5, 10));
    EXPECT_TRUE(myCalendar.book(25, 55));
}