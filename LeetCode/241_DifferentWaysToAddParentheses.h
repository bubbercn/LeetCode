#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> diffWaysToCompute(const string &input)
    {
        Init();
        Tokenize(input);
        if (tokens.empty())
            return {};
        unordered_set<string> temp = Helper(tokens, tokens.begin(), tokens.end());
        vector<int> result;
        result.reserve(temp.size());
        for (const auto &i : temp)
        {
            result.emplace_back(lookup[i]);
        }
        return result;
    }

private:
    void Init()
    {
        tokens.clear();
        lookup.clear();
    }
    void Tokenize(const string &input)
    {
        string token;
        for (const auto &c : input)
        {
            if (c == '+' || c == '-' || c == '*')
            {
                tokens.emplace_back(token);
                token.clear();
                tokens.push_back({c});
            }
            else
            {
                token += c;
            }
        }
        tokens.emplace_back(token);
    }
    unordered_set<string> Helper(list<string> &tokens, list<string>::const_iterator begin, list<string>::const_iterator end)
    {
        auto temp = begin;
        if (++temp == end)
        {
            int value = atoi(begin->c_str());
            lookup.emplace(*begin, value);
            return {*begin};
        }
        unordered_set<string> result;
        for (auto i = begin; i != end; i++)
        {
            if (*i == "+" || *i == "-" || *i == "*")
            {
                unordered_set<string> left = Helper(tokens, begin, i);
                auto temp = i;
                unordered_set<string> right = Helper(tokens, ++temp, end);
                for (const auto &l : left)
                {
                    int ll = lookup[l];
                    for (const auto &r : right)
                    {
                        int rr = lookup[r];
                        int value = calc(ll, rr, *i);
                        string key = "(";
                        key = key + l + *i + r + ")";
                        lookup[key] = value;
                        result.emplace(key);
                    }
                }
            }
        }
        return result;
    }
    int calc(int left, int right, const string &op)
    {
        if (op == "+")
        {
            return left + right;
        }
        else if (op == "-")
        {
            return left - right;
        }
        else
        {
            return left * right;
        }
    }
    list<string> tokens;
    unordered_map<string, int> lookup;
};

void Test()
{
    string input = "2*3-4*5";
    Solution solution;
    solution.diffWaysToCompute(input);
}