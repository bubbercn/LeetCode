#pragma once
#include "Common.h"

class cmp
{
public:
    bool operator()(const string &v1, const string &v2) const
    {
        if (v1.length() == v2.length())
            return v1 < v2;
        return v1.length() > v2.length();
    }
};

struct Polynomial
{
    map<string, int, cmp> terms;
    Polynomial &operator+(const Polynomial &other)
    {
        return *this;
    }
    Polynomial &operator-(const Polynomial &other)
    {
        return *this;
    }
    Polynomial &operator*(const Polynomial &other)
    {
        return *this;
    }
};

class Solution
{
public:
    vector<string> basicCalculatorIV(string_view expression, vector<string> &evalvars, vector<int> &evalints)
    {
        variable2Int.clear();
        for (int i = 0; i < evalvars.size(); i++)
        {
            variable2Int.emplace(evalvars[i], evalints[i]);
        }
        vector<string> tokens = tokenize(expression);
        Polynomial result = calculate(tokens.begin(), tokens.end()).first;
        return polynomial2String(result);
    }

private:
    unordered_map<string, int> variable2Int;
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
    pair<Polynomial, vector<string>::const_iterator> calculate(vector<string>::const_iterator begin, vector<string>::const_iterator end)
    {
        vector<Polynomial> polynomials(2);
        string op;
        auto it = begin;
        while (it != end)
        {
            if (*it == "+" || *it == "-" || *it == "*")
            {
                if (op.empty())
                {
                    op = *it;
                    it++;
                }
                else if (*it == "+" || *it == "-")
                {
                    polynomials[0] = op == "+" ? polynomials[0] + polynomials[1] : polynomials[0] - polynomials[1];
                    op = *it;
                    it++;
                }
                else
                {
                    auto temp = calculate(it - 1, end);
                    polynomials[1] = temp.first;
                    it = temp.second;
                }
            }
            else if (*it == "(")
            {
                auto temp = calculate(it + 1, end);
                if (op.empty())
                {
                    polynomials[0] = temp.first;
                }
                else
                {
                    polynomials[1] = temp.first;
                }
                it = temp.second;
            }
            else if (*it == ")")
            {
                it++;
                break;
            }
            else
            {
                if (op.empty())
                {
                    polynomials[0] = token2Polynomial(*it);
                }
                else
                {
                    polynomials[1] = token2Polynomial(*it);
                }
                if (op == "*")
                {
                    polynomials[0] = polynomials[0] * polynomials[1];
                    op.clear();
                }
                it++;
            }
        }
        if (!op.empty())
        {
            polynomials[0] = op == "+" ? polynomials[0] + polynomials[1] : polynomials[0] - polynomials[1];
        }
        return {polynomials[0], it};
    }
    Polynomial token2Polynomial(string_view token)
    {
        Polynomial result;
        try
        {
            int value = stoi(token.data());
            result.terms.emplace("", value);
        }
        catch (const exception &e)
        {
            if (auto it = variable2Int.find(token.data()); it != variable2Int.end())
            {
                result.terms.emplace("", it->second);
            }
            else
            {
                result.terms.emplace(token, 1);
            }
        }
        return result;
    }
    vector<string> polynomial2String(const Polynomial &input)
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
