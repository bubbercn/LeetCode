#pragma once
#include "Common.h"

class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {
        int remainingBytes = 0;
        for (auto i : data)
        {
            if (remainingBytes == 0)
            {
                if ((i & Bit1) == 0)
                    continue;
                if ((i & Bit2) == 0)
                    return false;
                remainingBytes++;
                if ((i & Bit3) == 0)
                    continue;
                remainingBytes++;
                if ((i & Bit4) == 0)
                    continue;
                remainingBytes++;
                if ((i & Bit5) != 0)
                    return false;
            }
            else
            {
                if ((i & Bit1) == 0)
                    return false;
                if ((i & Bit2) != 0)
                    return false;
                remainingBytes--;
            }
        }
        return remainingBytes == 0;
    }

private:
    constexpr static int Bit1 = 1 << 7;
    constexpr static int Bit2 = 1 << 6;
    constexpr static int Bit3 = 1 << 5;
    constexpr static int Bit4 = 1 << 4;
    constexpr static int Bit5 = 1 << 3;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
    inline static vector<int> data;
};

TEST_F(LeetCodeTest, Example1)
{
    data = {197, 130, 1};
    EXPECT_EQ(solution.validUtf8(data), true);
}

TEST_F(LeetCodeTest, Example2)
{
    data = {235, 140, 4};
    EXPECT_EQ(solution.validUtf8(data), false);
}

TEST_F(LeetCodeTest, Failure1)
{
    data = {240, 162, 138, 147};
    EXPECT_EQ(solution.validUtf8(data), true);
}
