#pragma once
#include "Common.h"

class str_cmp
{
public:
    bool operator()(const string &v1, const string &v2) const
    {
        if (v1.length() == v2.length())
            return v1 < v2;
        return v1.length() > v2.length();
    }
};

class map_cmp
{
public:
    bool operator()(const multiset<string, str_cmp> &v1, const multiset<string, str_cmp> &v2) const
    {
        if (v1.size() == v2.size())
            return v1 < v2;
        return v1.size() > v2.size();
    }
};

struct Polynomial
{
    map<multiset<string, str_cmp>, int, map_cmp> terms;
    Polynomial &operator+(const Polynomial &other)
    {
        for (auto &term : other.terms)
        {
            if (terms.find(term.first) == terms.end())
                terms[term.first] = term.second;
            else
                terms[term.first] += term.second;
        }
        return *this;
    }
    Polynomial &operator-(const Polynomial &other)
    {
        for (auto &term : other.terms)
        {
            if (terms.find(term.first) == terms.end())
                terms[term.first] = -term.second;
            else
                terms[term.first] -= term.second;
        }
        return *this;
    }
    Polynomial &operator*(const Polynomial &other)
    {
        Polynomial result;
        for (auto &term : other.terms)
        {
            for (auto &term2 : terms)
            {
                multiset<string, str_cmp> key = term.first;
                key.insert(term2.first.begin(), term2.first.end());
                if (result.terms.find(key) == result.terms.end())
                    result.terms[key] = term.second * term2.second;
                else
                    result.terms[key] += term.second * term2.second;
            }
        }
        result.terms.swap(terms);
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
            else if (expression[i] == '(' || expression[i] == ')')
            {
                if (begin != -1)
                {
                    result.emplace_back(expression.substr(begin, i - begin));
                    begin = -1;
                }
                result.emplace_back(1, expression[i]);
            }
            else
            {
                if (begin == -1)
                {
                    begin = i;
                }
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
        vector<Polynomial> polynomials(3);
        string op;
        string op2;
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
                    op2 = *it;
                    it++;
                }
            }
            else if (*it == "(")
            {
                auto temp = calculate(it + 1, end);
                if (op2.empty())
                {
                    if (op.empty())
                    {
                        polynomials[0] = temp.first;
                    }
                    else
                    {
                        polynomials[1] = temp.first;
                    }
                    if (op == "*")
                    {
                        polynomials[0] = polynomials[0] * polynomials[1];
                        op.clear();
                    }
                }
                else
                {
                    polynomials[2] = temp.first;
                    polynomials[1] = polynomials[1] * polynomials[2];
                    op2.clear();
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
                if (op2.empty())
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
                }
                else
                {
                    polynomials[2] = token2Polynomial(*it);
                    polynomials[1] = polynomials[1] * polynomials[2];
                    op2.clear();
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
            result.terms.insert({{}, value});
        }
        catch (const exception &e)
        {
            if (auto it = variable2Int.find(token.data()); it != variable2Int.end())
            {
                result.terms.insert({{}, it->second});
            }
            else
            {
                result.terms.insert({{token.data()}, 1});
            }
        }
        return result;
    }
    vector<string> polynomial2String(const Polynomial &input)
    {
        vector<string> result;
        for (auto &term : input.terms)
        {
            if (term.second == 0)
                continue;
            string unit;
            for (auto &key : term.first)
            {
                unit += "*" + key;
            }
            if (term.second > 0)
            {
                result.emplace_back(to_string(term.second) + unit);
            }
            else
            {
                result.emplace_back("-" + to_string(-term.second) + unit);
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

TEST_F(LeetCodeTest, Failure1)
{
    vector<string> evalvars = {};
    vector<int> evalints = {};
    vector<string> output = {"-1*a*a*b*b", "2*a*a*b*c", "-1*a*a*c*c", "1*a*b*b*b", "-1*a*b*b*c", "-1*a*b*c*c", "1*a*c*c*c", "-1*b*b*b*c", "2*b*b*c*c", "-1*b*c*c*c", "2*a*a*b", "-2*a*a*c", "-2*a*b*b", "2*a*c*c", "1*b*b*b", "-1*b*b*c", "1*b*c*c", "-1*c*c*c", "-1*a*a", "1*a*b", "1*a*c", "-1*b*c"};
    EXPECT_EQ(solution.basicCalculatorIV("((a - b) * (b - c) + (c - a)) * ((a - b) + (b - c) * (c - a))", evalvars, evalints), output);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<string> evalvars = {};
    vector<int> evalints = {};
    vector<string> output = {"137"};
    EXPECT_EQ(solution.basicCalculatorIV("137", evalvars, evalints), output);
}