#pragma once
#include "Common.h"

class MyCalendarThree
{
public:
    MyCalendarThree()
    {
    }

    int book(int start, int end)
    {
        return 0;
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
    MyCalendarThree myCalendar;
    EXPECT_EQ(myCalendar.book(10, 20), 1);
    EXPECT_EQ(myCalendar.book(50, 60), 1);
    EXPECT_EQ(myCalendar.book(10, 40), 2);
    EXPECT_EQ(myCalendar.book(5, 15), 3);
    EXPECT_EQ(myCalendar.book(5, 10), 3);
    EXPECT_EQ(myCalendar.book(25, 55), 3);
}