#pragma once
#include "Common.h"

class MyCalendar
{
public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        if (auto it = leftMap.lower_bound(end); leftMap.empty() || it == leftMap.begin() || (--it)->second <= start)
        {
            leftMap.emplace_hint(it, start, end);
            return true;
        }
        return false;
    }

private:
    map<int, int> leftMap;
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
    MyCalendar myCalendar;
    EXPECT_TRUE(myCalendar.book(10, 20));
    EXPECT_FALSE(myCalendar.book(15, 25));
    EXPECT_TRUE(myCalendar.book(20, 30));
}