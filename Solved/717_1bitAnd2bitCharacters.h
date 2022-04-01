#pragma once
#include "Common.h"

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int n = bits.size();
        for (int i = 0; i < n;)
        {
            if (bits[i] == 1)
            {
                i += 2;
            }
            else
            {
                if (i == n - 1)
                    return true;
                i += 1;
            }
        }
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> bits = {1, 0, 0};
    EXPECT_EQ(solution.isOneBitCharacter(bits), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> bits = {1, 1, 1, 0};
    EXPECT_EQ(solution.isOneBitCharacter(bits), false);
}