#pragma once
#include "Common.h"

class Solution
{
public:
    bool checkValidString(string_view s)
    {
        stack<int> leftParenthesis;
        stack<int> star;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                leftParenthesis.emplace(i);
            }
            else if (s[i] == '*')
            {
                star.emplace(i);
            }
            else
            {
                if (!leftParenthesis.empty())
                {
                    leftParenthesis.pop();
                    continue;
                }

                if (!star.empty())
                {
                    star.pop();
                    continue;
                }
                return false;
            }
        }
        while (!leftParenthesis.empty())
        {
            if (star.empty())
                return false;

            if (star.top() < leftParenthesis.top())
                return false;

            star.pop();
            leftParenthesis.pop();
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
    EXPECT_EQ(solution.checkValidString("()"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.checkValidString("(*)"), true);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.checkValidString("(*))"), true);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.checkValidString("((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()"), true);
}