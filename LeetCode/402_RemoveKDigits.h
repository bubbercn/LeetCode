#pragma once
#include "Common.h"

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (num.length() <= k)
            return "0";

        list<char> result;
        int deletedCount = 0;
        for (auto c : num)
        {
            while (!result.empty() && result.back() > c && deletedCount < k)
            {
                result.pop_back();
                deletedCount++;
            }
            result.emplace_back(c);
        }
        while (!result.empty() && deletedCount < k)
        {
            result.pop_back();
            deletedCount++;
        }

        for (auto it = result.begin(); it != result.end();)
        {
            if (*it != '0' || result.size() == 1)
                break;
            it = result.erase(it);
        }

        return {result.begin(), result.end()};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.removeKdigits("1432219", 3), "1219");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.removeKdigits("10200", 1), "200");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.removeKdigits("10", 2), "0");
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.removeKdigits("9", 1), "0");
}

TEST_F(LeetCodeTest, Failure2)
{
    EXPECT_EQ(solution.removeKdigits("10", 1), "0");
}

TEST_F(LeetCodeTest, Failure3)
{
    EXPECT_EQ(solution.removeKdigits("112", 1), "11");
}
