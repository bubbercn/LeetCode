#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> basicCalculatorIV(string_view expression, vector<string> &evalvars, vector<int> &evalints)
    {
        return {};
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
