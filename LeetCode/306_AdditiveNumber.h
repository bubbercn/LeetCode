#pragma once
#include "Common.h"

class Solution
{
public:
    bool isAdditiveNumber(const string &num)
    {
        if (num.length() < 3)
            return false;

        size_t i1 = 0, i2 = 1, i3 = 2, i4 = 3;

        do
        {
            if (helper(num, i1, i2, i3, i4))
                return true;
        } while (next(num, i1, i2, i3, i4));
        
        return false;
    }

private:
    bool helper(const string &num, size_t i1, size_t i2, size_t i3, size_t i4)
    {
        if (num[i1] == '0')
            return false;
        
        long num1 = stol(num.substr(i1, i2 - i1));

        if (num[i2] == '0')
            return false;
        
        long num1 = stol(num.substr(i2, i3 - i2));

        if (num[i3] == '0')
            return false;
        
        long num1 = stol(num.substr(i3, i4 - i3));

        return false;
    }

    bool next(const string &num, size_t& i1, size_t& i2, size_t& i3, size_t& i4)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.isAdditiveNumber("112358"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.isAdditiveNumber("199100199"), true);
}