#pragma once
#include "Common.h"

class Solution
{
public:
    string reverseOnlyLetters(string_view s)
    {
        string result(s);
        int n = result.length();
        int left = -1;
        int right = n;
        while (true)
        {
            left++;
            while (left < n && !isalpha(result[left]))
            {
                left++;
            }
            right--;
            while (right >= 0 && !isalpha(result[right]))
            {
                right--;
            }
            if (left < right)
            {
                swap(result[left], result[right]);
            }
            else
            {
                break;
            }
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
    EXPECT_EQ(solution.reverseOnlyLetters("ab-cd"), "dc-ba");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.reverseOnlyLetters("a-bC-dEf-ghIj"), "j-Ih-gfE-dCba");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.reverseOnlyLetters("Test1ng-Leet=code-Q!"), "Qedo1ct-eeLg=ntse-T!");
}