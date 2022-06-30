#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> basicCalculatorIV(string_view expression, vector<string> &evalvars, vector<int> &evalints)
    {
        unordered_map<string, int> variable2Int;
        for (int i = 0; i < evalvars.size(); i++)
        {
            variable2Int.emplace(evalvars[i], evalints[i]);
        }
        vector<string> tokens = tokenize(expression);
        return {};
    }

private:
    vector<string> tokenize(string_view expression)
    {
        vector<string> result;
        int begin = -1;
        for (int i = 0; i < expression.size(); i++)
        {
            if (expression[i] == ' ')
            {
                if (begin != -1)
                {
                    result.emplace_back(expression.substr(begin, i - begin));
                    begin = -1;
                }
            }
            else if (expression[i] >= 'a' && expression[i] <= 'z')
            {
                if (begin == -1)
                {
                    begin = i;
                }
            }
            else
            {
                if (begin != -1)
                {
                    result.emplace_back(expression.substr(begin, i - begin));
                    begin = -1;
                }
                result.emplace_back(1, expression[i]);
            }
        }
        if (begin != -1)
        {
            result.emplace_back(expression.substr(begin));
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
    vector<string> evalvars = {"e"};
    vector<int> evalints = {1};
    vector<string> output = {"-1*a", "14"};
    EXPECT_EQ(solution.basicCalculatorIV("e + 8 - a + 5", evalvars, evalints), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> evalvars = {"e", "temperature"};
    vector<int> evalints = {1, 12};
    vector<string> output = {"-1*pressure", "5"};
    EXPECT_EQ(solution.basicCalculatorIV("e - 8 + temperature - pressure", evalvars, evalints), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> evalvars = {};
    vector<int> evalints = {};
    vector<string> output = {"1*e*e", "-64"};
    EXPECT_EQ(solution.basicCalculatorIV("(e + 8) * (e - 8)", evalvars, evalints), output);
}
