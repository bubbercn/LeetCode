#pragma once
#include "Common.h"

class Solution
{
public:
    int calculate(string s)
    {
        list<string> tokens = tokenize(s);
        return calculate(tokens);
    }

private:
    list<string> tokenize(const string &s)
    {
        list<string> tokens;
        string token;
        for (const auto &c : s)
        {
            switch (c)
            {
            case '0' ... '9':
            {
                token += c;
            }
            break;
            case '(':
            case ')':
            case '+':
            case '-':
            {
                if (!token.empty())
                {
                    tokens.emplace_back(token);
                    token.clear();
                }
                tokens.push_back({c});
            }
            break;
            default:
                break;
            }
        }
        if (!token.empty())
            tokens.emplace_back(token);
        return tokens;
    }

    list<string> popExpression(stack<string> &expression)
    {
        list<string> tokenToCalculate;
        while (!expression.empty())
        {
            string temp = expression.top();
            expression.pop();
            if (temp == "(")
            {
                break;
            }
            else
            {
                tokenToCalculate.emplace_front(temp);
            }
        }
        return tokenToCalculate;
    }

    int calculate(const list<string> &tokens)
    {
        stack<string> expression;
        for (const auto &token : tokens)
        {
            if (token == ")")
            {
                list<string> tokenToCalculate = popExpression(expression);
                expression.emplace(to_string(helper(tokenToCalculate)));
            }
            else
            {
                expression.emplace(token);
            }
        }
        return helper(popExpression(expression));
    }

    int helper(const list<string> &tokens)
    {
        int op1 = 0, op2 = 0;
        bool add = true;

        if (tokens.empty())
            return 0;
        
        auto token = tokens.begin();
        op1 = atoi((*token).c_str());
        token++;
        while (token != tokens.end())
        {
            if (*token == "+")
            {
                add = true;
            }
            else if (*token == "-")
            {
                add = false;
            }
            else
            {
                op2 = atoi((*token).c_str());
                op1 = add ? op1 + op2 : op1 - op2;
            }
            token++;
        }

        return op1;
    }
};

void Test()
{
    Solution solution;

    string s = "(1+(4+5+2)-3)+(6+8)";
    assert(solution.calculate(s) == 23);
}