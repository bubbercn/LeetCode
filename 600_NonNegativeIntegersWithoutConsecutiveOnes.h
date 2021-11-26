#pragma once
#include "Common.h"

class Solution
{
public:
    int findIntegers(int n)
    {
        init();
        bitset<32> bits(n);
        int result = 0;
        bool jump = false;
        for (int i = 31; i >= 0;)
        {
            if (bits.test(i))
            {
                for (int j = 0; j < i; j++)
                {
                    result += lookup[j];
                }
                if (i == 0 || bits.test(i - 1))
                {
                    result += lookup[i];
                    jump = true;
                    break;
                }
                i -= 2;
            }
            else
            {
                i--;
            }
        }
        if (!jump)
            result++;
        return result;
    }

private:
    inline static vector<int> lookup;
    static void init()
    {
        if (lookup.empty())
        {
            lookup.resize(32);
            lookup[0] = 2;
            lookup[1] = 1;
            int sum = 0;
            for (int i = 2; i < 32; i++)
            {
                sum += lookup[i - 2];
                lookup[i] = sum;
            }
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
    EXPECT_EQ(solution.findIntegers(5), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.findIntegers(1), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.findIntegers(2), 3);
}

TEST_F(LeetCodeTest, Case1)
{
    EXPECT_EQ(solution.findIntegers(1000000000), 2178309);
}

TEST_F(LeetCodeTest, Case2)
{
    EXPECT_EQ(solution.findIntegers(100), 34);
}