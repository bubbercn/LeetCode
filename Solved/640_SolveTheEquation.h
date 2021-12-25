#pragma once
#include "Common.h"

class Solution
{
public:
    string solveEquation(string_view equation)
    {
        auto pos = equation.find('=');
        auto [leftX, leftC] = parseEquation(equation.substr(0, pos));
        auto [rightX, rightC] = parseEquation(equation.substr(pos + 1));
        int x = leftX - rightX;
        int c = rightC - leftC;

        if (x == 0 && c != 0)
            return "No solution";
        if (x == 0 && c == 0)
            return "Infinite solutions";

        stringstream result;
        result << "x=" << c / x;
        return result.str();
    }

private:
    pair<int, int> parseEquation(string_view equation)
    {
        int x = 0, c = 0;
        int begin = -1;
        int sign = 1;
        int i = 0;

        auto process = [&]()
        {
            if (begin == -1)
                return;

            if (equation[i - 1] == 'x')
            {
                string value;
                value = equation.substr(begin, i - begin - 1);
                if (value.empty())
                {
                    x += sign;
                }
                else
                {
                    x += sign * stoi(value);
                }
            }
            else
            {
                c += sign * stoi(equation.substr(begin, i - begin).data());
            }
        };

        for (i = 0; i < equation.length(); i++)
        {
            if (equation[i] != '+' && equation[i] != '-')
            {
                if (begin == -1)
                {
                    begin = i;
                }
            }
            else
            {
                process();
                begin = -1;
                sign = equation[i] == '+' ? 1 : -1;
            }
        }
        process();
        return {x, c};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.solveEquation("x+5-3+x=6+x-2"), "x=2");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.solveEquation("x=x"), "Infinite solutions");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.solveEquation("2x=x"), "x=0");
}
