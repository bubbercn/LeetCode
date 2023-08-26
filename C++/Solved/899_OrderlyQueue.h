#pragma once
#include "Common.h"

class Solution
{
public:
    string orderlyQueue(string_view s, int k)
    {
        string result(s);
        if (k == 1)
        {
            string min = result;
            for (int i = 1; i < s.length(); i++)
            {
                string temp = result.substr(i) + result.substr(0, i);
                min = ::min(temp, min);
            }
            return min;
        }
        else
        {
            sort(result.begin(), result.end());
            return result;
        }
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.orderlyQueue("cba", 1), "acb");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.orderlyQueue("baaca", 3), "aaabc");
}