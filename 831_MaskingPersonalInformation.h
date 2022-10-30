#pragma once
#include "Common.h"

class Solution
{
public:
    string maskPII(string_view s)
    {
        string result;
        if (auto pos = s.find('@'); pos != string::npos)
        {
            // email
            string email(s);
            transform(email.begin(), email.end(), email.begin(), ::tolower);
            auto name = email.substr(0, pos);
            result += *name.begin();
            result += "*****";
            result += *name.rbegin();
            result += email.substr(pos);
        }
        else
        {
            // phone number
            int digitCount = 0;
            list<char> last4;
            for (auto it = s.rbegin(); it != s.rend(); it++)
            {
                if (*it < '0' || *it > '9')
                    continue;
                
                digitCount++;
                if (last4.size() < 4)
                    last4.push_front(*it);
            }
            if (digitCount > 10)
                result += '+';
            result += string(digitCount - 10, '*');
            if (!result.empty())
                result += '-';
            result += "***-***-";
            result += string(last4.begin(), last4.end());
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
    EXPECT_EQ(solution.maskPII("LeetCode@LeetCode.com"), "l*****e@leetcode.com");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.maskPII("AB@qq.com"), "a*****b@qq.com");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.maskPII("1(234)567-890"), "***-***-7890");
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.maskPII("86-(10)12345678"), "+**-***-***-5678");
}