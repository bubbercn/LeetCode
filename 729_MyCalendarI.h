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
    MyCalendar myCalendar;
    EXPECT_TRUE(myCalendar.book(10, 20));
    EXPECT_FALSE(myCalendar.book(15, 25));
    EXPECT_TRUE(myCalendar.book(20, 30));
}