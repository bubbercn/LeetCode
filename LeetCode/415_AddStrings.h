#pragma once
#include "Common.h"

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string result(max(num1.length(), num2.length()) + 1, '0');
        int i = num1.length() - 1, j = num2.length() - 1, k = result.length() - 1;
        for (; i >= 0 && j >= 0; i--, j--, k--)
        {
            result[k] += num1[i] - '0' + num2[j] - '0';
            if (result[k] > '9')
            {
                result[k - 1]++;
                result[k] -= 10;
            }
        }

        for (; i >= 0; i--, k--)
        {
            result[k] += num1[i] - '0';
            if (result[k] > '9')
            {
                result[k - 1]++;
                result[k] -= 10;
            }
        }

        for (; j >= 0; j--, k--)
        {
            result[k] += num2[j] - '0';
            if (result[k] > '9')
            {
                result[k - 1]++;
                result[k] -= 10;
            }
        }
        
        return result[0] == '0' ? result.substr(1) : result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Case1)
{
    EXPECT_EQ(solution.addStrings("100","21"), "121");
}

TEST_F(LeetCodeTest, Case2)
{
    EXPECT_EQ(solution.addStrings("79","21"), "100");
}

TEST_F(LeetCodeTest, Case3)
{
    EXPECT_EQ(solution.addStrings("179","21"), "200");
}

TEST_F(LeetCodeTest, Case4)
{
    EXPECT_EQ(solution.addStrings("979","21"), "1000");
}

TEST_F(LeetCodeTest, Case5)
{
    EXPECT_EQ(solution.addStrings("1","999"), "1000");
}