#pragma once
#include "Common.h"

class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        int countOfDashes{0};
        for (auto c : s)
        {
            if (c == '-')
                countOfDashes++;
        }
        int countOfChar = s.length() - countOfDashes;
        int sizeOfChunck = countOfChar % k;
        if (sizeOfChunck == 0)
            sizeOfChunck = k;
        stringstream result;
        int count = 0;
        for (auto c : s)
        {
            if (c == '-')
                continue;
            count++;
            result << static_cast<char>(toupper(c));
            sizeOfChunck--;
            if (sizeOfChunck == 0 && count != countOfChar)
            {
                result << '-';
                sizeOfChunck = k;
            }            
        }
        return result.str();
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.licenseKeyFormatting("5F3Z-2e-9-w", 4), "5F3Z-2E9W");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.licenseKeyFormatting("2-5g-3-J", 2), "2-5G-3J");
}