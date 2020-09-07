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

        unordered_set<string> result;
        string temp;
        dfs(s, 0, temp, leftParenthesesToRemove, rightParenthesesToRemove, 0, 0, result);

        return {result.begin(), result.end()};
    }

private:
    pair<int, int> getNumberOfParenthesesToRemove(const string &s)
    {
        int leftParenthesesToRemove = 0, rightParenthesesToRemove = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                leftParenthesesToRemove++;
            }
            else if (c == ')')
            {
                if (leftParenthesesToRemove == 0)
                {
                    rightParenthesesToRemove++;
                }
                else
                {
                    leftParenthesesToRemove--;
                }
            }
        }

        return {leftParenthesesToRemove, rightParenthesesToRemove};
    }

    void dfs(const string &s, int index, string &curString, int leftParenthesesToRemove, int rightParenthesesToRemove, int leftParenthesesErrorCount, int rightParenthesesErrorCount, unordered_set<string> &result)
    {
        if (rightParenthesesErrorCount > 0 || leftParenthesesToRemove < 0 || rightParenthesesToRemove < 0)
        {
            return;
        }

        if (index == s.length())
        {
            if (leftParenthesesErrorCount == 0 && rightParenthesesErrorCount == 0)
            {
                result.emplace(curString);
            }
            return;
        }
            
        size_t curStringLength = curString.length();

        if (s[index] == '(')
        {
            curString += '(';
            dfs(s, index + 1, curString, leftParenthesesToRemove, rightParenthesesToRemove, leftParenthesesErrorCount + 1, rightParenthesesErrorCount, result);
            curString.resize(curStringLength);

            dfs(s, index + 1, curString, leftParenthesesToRemove - 1, rightParenthesesToRemove, leftParenthesesErrorCount, rightParenthesesErrorCount, result);
        }
        else if (s[index] == ')')
        {
            curString += ')';
            int lPE = leftParenthesesErrorCount, rPE = rightParenthesesErrorCount;
            if (lPE == 0)
            {
                rPE++;
            }
            else
            {
                lPE--;
            }

            dfs(s, index + 1, curString, leftParenthesesToRemove, rightParenthesesToRemove, lPE, rPE, result);
            curString.resize(curStringLength);

            dfs(s, index + 1, curString, leftParenthesesToRemove, rightParenthesesToRemove - 1, leftParenthesesErrorCount, rightParenthesesErrorCount, result);
        }
        else
        {
            curString += s[index];
            dfs(s, index + 1, curString, leftParenthesesToRemove, rightParenthesesToRemove, leftParenthesesErrorCount, rightParenthesesErrorCount, result);
        }
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
    vector<string> output = {"r(())", "(r())", "r()()", "(r)()"};
    EXPECT_EQ(solution.removeInvalidParentheses(input), output);
}
