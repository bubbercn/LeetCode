#pragma once
#include "Common.h"

class Solution
{
public:
    int scoreOfParentheses(string_view s)
    {
        stack<int> scores;
        int result = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                scores.emplace(0);
            }
            else
            {
                if (scores.top() == 0)
                {
                    scores.top() = 1;
                }
                else
                {
                    scores.top() *= 2;
                }
                int score = scores.top();
                scores.pop();
                if (scores.empty())
                {
                    result += score;
                }
                else
                {
                    scores.top() += score;
                }
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
    EXPECT_EQ(solution.scoreOfParentheses("()"), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.scoreOfParentheses("(())"), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.scoreOfParentheses("()()"), 2);
}