#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> removeInvalidParentheses(string s)
    {
        int leftParenthesesToRemove = 0;
        int rightParenthesesToRemove = 0;
        
        {
            auto temp = getNumberOfParenthesesToRemove(s);
            leftParenthesesToRemove = temp.first;
            rightParenthesesToRemove = temp.second;
        }
        
        return {};
    }

private:
    pair<int, int> getNumberOfParenthesesToRemove(const string& s)
    {
        list<char> parenthesesToRemove;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                parenthesesToRemove.emplace_back('(');
            }
            else if (s[i] == ')')
            {
                if (!parenthesesToRemove.empty() && parenthesesToRemove.back() == '(')
                {
                    parenthesesToRemove.pop_back();
                }
                else
                {
                    parenthesesToRemove.emplace_back(')');
                }
            }
            else
            {
                continue;
            }
        }
        
        int leftParenthesesToRemove = 0;
        int rightParenthesesToRemove = 0;
        
        for (auto i : parenthesesToRemove)
        {
            if (i == '(')
            {
                leftParenthesesToRemove++;
            }
            else
            {
                rightParenthesesToRemove++;
            }
        }
        
        return {leftParenthesesToRemove, rightParenthesesToRemove};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    string input = "()())()";
    vector<string> output = {"()()()", "(())()"};
    EXPECT_EQ(solution.removeInvalidParentheses(input), output);
}

TEST_F(LeetCodeTest, Example2)
{
    string input = "(a)())()";
    vector<string> output = {"(a)()()", "(a())()"};
    EXPECT_EQ(solution.removeInvalidParentheses(input), output);
}

TEST_F(LeetCodeTest, Example3)
{
    string input = ")(";
    vector<string> output = {""};
    EXPECT_EQ(solution.removeInvalidParentheses(input), output);
}

TEST_F(LeetCodeTest, EmptyString)
{
    string input = "";
    vector<string> output = {""};
    EXPECT_EQ(solution.removeInvalidParentheses(input), output);
}

TEST_F(LeetCodeTest, SingleLeftBracket)
{
    string input = "(";
    vector<string> output = {""};
    EXPECT_EQ(solution.removeInvalidParentheses(input), output);
}

TEST_F(LeetCodeTest, SingleRightBracket)
{
    string input = ")";
    vector<string> output = {""};
    EXPECT_EQ(solution.removeInvalidParentheses(input), output);
}

TEST_F(LeetCodeTest, NoRemove)
{
    string input = "()";
    vector<string> output = {"()"};
    EXPECT_EQ(solution.removeInvalidParentheses(input), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    string input = ")()(";
    vector<string> output = {"()"};
    EXPECT_EQ(solution.removeInvalidParentheses(input), output);
}

TEST_F(LeetCodeTest, Failure2)
{
    string input = "(()(";
    vector<string> output = {"()"};
    EXPECT_EQ(solution.removeInvalidParentheses(input), output);
}

TEST_F(LeetCodeTest, Failure3)
{
    string input = "(r(()()(";
    vector<string> output = {"r()()","r(())","(r)()","(r())"};
    EXPECT_EQ(solution.removeInvalidParentheses(input), output);
}
