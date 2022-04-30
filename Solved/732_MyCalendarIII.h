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
        left.emplace(start, end);
        points.emplace(start);
        auto lower = points.lower_bound(start);
        auto upper = points.upper_bound(end);
        for (auto it1 = lower; it1 != upper; it1++)
        {
            int result = 0;
            auto upper2 = left.upper_bound(*it1);
            for (auto it2 = left.begin(); it2 != upper2; it2++)
            {
                if (it2->second > *it1)
                {
                    result++;
                }
            }
            k = max(k, result);
        }
        return k;
    }

private:
    multimap<int, int> left;
    set<int> points;
    int k = 0;
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