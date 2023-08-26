#pragma once
#include "Common.h"

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        vector<int> digits;
        while (n > 0)
        {
            digits.emplace_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
        long result = helper(digits.begin(), digits.end());
        return result > numeric_limits<int>::max() ? -1 : result;
    }

private:
    long helper(vector<int>::iterator begin, vector<int>::iterator end)
    {
        if (begin + 1 == end)
        {
            return -1;
        }

        long result = 0;
        if (int next = helper(begin + 1, end); next == -1)
        {
            sort(begin + 1, end);
            if (auto upper = upper_bound(begin + 1, end, *begin); upper == end)
            {
                return -1;
            }
            else
            {
                swap(*begin, *upper);
                for (auto it = begin; it != end; it++)
                {
                    result = result * 10 + *it;
                }
            }
        }
        else
        {
            result = static_cast<long>(*begin) * pow(10, distance(begin, end) - 1) + next;
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.nextGreaterElement(12), 21);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.nextGreaterElement(21), -1);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.nextGreaterElement(101), 110);
}

TEST_F(LeetCodeTest, Failure2)
{
    EXPECT_EQ(solution.nextGreaterElement(2147483486), -1);
}