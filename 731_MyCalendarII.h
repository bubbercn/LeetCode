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
        return false;
    }
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
    EXPECT_FALSE(myCalendar.book(25, 55));
}