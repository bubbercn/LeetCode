#pragma once
#include "Common.h"

class Solution
{
public:
    bool isRationalEqual(string_view s, string_view t)
    {
        auto [sInteger, sNumerator, sDenominator] = parseFloat(s);
        auto [tInteger, tNumerator, tDenominator] = parseFloat(t);
        if (sInteger != tInteger)
            return false;
        return static_cast<long>(sNumerator) * tDenominator == static_cast<long>(tNumerator) * sDenominator;
    }

private:
    tuple<int, int, int> parseFloat(string_view s)
    {
        int integer = 0;
        int numerator = 0;
        int denominator = 1;
        auto point = s.find('.');
        if (point != string_view::npos)
        {
            integer = stoi(string(s.substr(0, point)));
            string nonRepeat;
            string repeat;
            auto pos = s.find('(', point + 1);
            if (pos != string_view::npos)
            {
                nonRepeat = string(s.substr(point + 1, pos - point - 1));
                repeat = string(s.substr(pos + 1, s.length() - pos - 2));
                numerator = stoi(nonRepeat + repeat) - (nonRepeat.empty() ? 0 : stoi(nonRepeat));
                denominator = pow(10, nonRepeat.length()) * (pow(10, repeat.length()) - 1);
            }
            else
            {
                nonRepeat = string(s.substr(point + 1));
                if (!nonRepeat.empty())
                {
                    numerator = stoi(nonRepeat);
                    denominator = pow(10, nonRepeat.length());
                }
            }
        }
        else
        {
            integer = stoi(string(s));
        }
        if (numerator == denominator)
        {
            integer++;
            numerator = 0;
            denominator = 1;
        }
        return {integer, numerator, denominator};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.isRationalEqual("0.(52)", "0.5(25)"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.isRationalEqual("0.1666(6)", "0.166(66)"), true);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.isRationalEqual("0.9(9)", "1."), true);
}
