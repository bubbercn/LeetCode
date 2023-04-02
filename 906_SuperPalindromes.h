#pragma once
#include "Common.h"

class Solution
{
public:
    int superpalindromesInRange(string_view left, string_view right)
    {
        long ll = stol(left.data());
        long rr = stol(right.data());
        long l = sqrtl(ll);
        long r = sqrtl(rr);
        string ls = to_string(l);
        string rs = to_string(r);
        int result = 0;
        for (int i = ls.length(); i <= rs.length(); i++)
        {
            if (i & 1)
            {
                int length = i / 2 + 1;
                int limit = pow(10, length);
                for (long j = pow(10, length - 1); j < limit; j++)
                {
                    string temp = to_string(j);
                    string pre = temp.substr(0, length - 1);
                    string vs = pre + temp[length - 1];
                    reverse(pre.begin(), pre.end());
                    vs += pre;
                    long v = stol(vs);
                    v *= v;
                    if (v < ll)
                        continue;
                    if (v > rr)
                        return result;
                    if (isPalindrome(v))
                        result++;
                }
            }
            else
            {
                int length = i / 2;
                int limit = pow(10, length);
                for (long j = pow(10, length - 1); j < limit; j++)
                {
                    string pre = to_string(j);
                    string vs = pre;
                    reverse(pre.begin(), pre.end());
                    vs += pre;
                    long v = stol(vs);
                    v *= v;
                    if (v < ll)
                        continue;
                    if (v > rr)
                        return result;
                    if (isPalindrome(v))
                        result++;
                }
            }
        }
        return result;
    }

private:
    bool isPalindrome(long n)
    {
        string s = to_string(n);
        int left = 0;
        int right = s.length() - 1;
        while (left < right)
        {
            if (s[left++] != s[right--])
                return false;
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
    EXPECT_EQ(solution.superpalindromesInRange("4", "1000"), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.superpalindromesInRange("1", "2"), 1);
}