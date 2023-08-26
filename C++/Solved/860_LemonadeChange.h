#pragma once
#include "Common.h"

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int count5 = 0;
        int count10 = 0;
        for (auto m : bills)
        {
            if (m == 5)
            {
                count5++;
            }
            else if (m == 10)
            {
                if (count5 == 0)
                    return false;
                count5--;
                count10++;
            }
            else
            {
                if (count10 == 0)
                {
                    if (count5 < 3)
                        return false;
                    
                    count5 -= 3;
                }
                else
                {
                    if (count5 == 0)
                        return false;
                    
                    count10--;
                    count5--;
                }
            }
        }
        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> bills = {5, 5, 5, 10, 20};
    EXPECT_EQ(solution.lemonadeChange(bills), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> bills = {5, 5, 10, 10, 20};
    EXPECT_EQ(solution.lemonadeChange(bills), false);
}