#pragma once
#include "Common.h"

class StockSpanner
{
public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        int result = 1;
        while (!data.empty() && price >= data.top().first)
        {
            result += data.top().second;
            data.pop();
        }
        data.emplace(price, result);
        return result;
    }

private:
    stack<pair<int, int>> data;
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
    StockSpanner stockSpanner;
    EXPECT_EQ(stockSpanner.next(100), 1); // return 1
    EXPECT_EQ(stockSpanner.next(80), 1);  // return 1
    EXPECT_EQ(stockSpanner.next(60), 1);  // return 1
    EXPECT_EQ(stockSpanner.next(70), 2);  // return 2
    EXPECT_EQ(stockSpanner.next(60), 1);  // return 1
    EXPECT_EQ(stockSpanner.next(75), 4);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
    EXPECT_EQ(stockSpanner.next(85), 6);  // return 6
}