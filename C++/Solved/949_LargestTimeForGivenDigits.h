#pragma once
#include "Common.h"

class Solution
{
public:
    string largestTimeFromDigits(vector<int> &arr)
    {
        multiset<int, greater<int>> digits(arr.begin(), arr.end());
        int digit = -1;
        digit = getDigit(2, digits);
        if (digit == -1)
            return {};
        string result;
        result += '0' + digit;
        if (result[0] == '2')
        {
            digit = getDigit(3, digits);
        }
        else
        {
            digit = getDigit(9, digits);
        }
        if (digit == -1)
            return {};
        result += '0' + digit;
        result += ':';
        digit = getDigit(5, digits);
        if (digit == -1)
        {
            digits = multiset<int, greater<int>>(arr.begin(), arr.end());
            result.clear();
            digit = getDigit(1, digits);
            if (digit == -1)
                return {};
            result += '0' + digit;
            digit = getDigit(9, digits);
            result += '0' + digit;
            result += ':';
            digit = getDigit(5, digits);
            if (digit == -1)
                return {};
        }
        result += '0' + digit;
        result += '0' + *digits.begin();
        return result;
    }

private:
    int getDigit(int max, multiset<int, greater<int>> &digits)
    {
        for (auto it = digits.begin(); it != digits.end(); it++)
        {
            if (*it <= max)
            {
                int temp = *it;
                digits.erase(it);
                return temp;
            }
        }
        return -1;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> arr = {1, 2, 3, 4};
    EXPECT_EQ(solution.largestTimeFromDigits(arr), "23:41");
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {5, 5, 5, 5};
    EXPECT_EQ(solution.largestTimeFromDigits(arr), "");
}
TEST_F(LeetCodeTest, Failure1)
{
    vector<int> arr = {2, 0, 6, 6};
    EXPECT_EQ(solution.largestTimeFromDigits(arr), "06:26");
}
