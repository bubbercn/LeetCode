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
                case '*':
                case '/':
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
    
    list<string> popExpression(stack<string> &expression, bool popTheRest = false)
    {
        list<string> tokenToCalculate;
        while (!expression.empty())
        {
            string temp = expression.top();
            if (temp == "+" || temp == "-")
            {
                if (popTheRest)
                {
                    expression.pop();
                    tokenToCalculate.emplace_front(temp);
                }
                else
                {
                    break;
                }
            }
            else
            {
                expression.pop();
                tokenToCalculate.emplace_front(temp);
            }
        }
        return tokenToCalculate;
    }
    
    int calculate(const list<string> &tokens)
    {
        stack<string> expression;
        bool needPop = false;
        for (const auto &token : tokens)
        {
            if (token == "+" || token == "-")
            {
                if (needPop)
                {
                    list<string> tokenToCalculate = popExpression(expression);
                    expression.emplace(to_string(helper(tokenToCalculate)));
                }
            }
            else if (token == "*" || token == "/")
            {
                needPop = true;
            }
            expression.emplace(token);
        }
        if (needPop)
        {
            list<string> tokenToCalculate = popExpression(expression);
            expression.emplace(to_string(helper(tokenToCalculate)));
        }
        return helper(popExpression(expression, true));
    }
    
    int helper(const list<string> &tokens)
    {
        int num1 = 0, num2 = 0;
        enum class Operator
        {
            Add,
            Minus,
            Multiply,
            Divide,
        };
        
        Operator op = Operator::Add;
        
        if (tokens.empty())
            return 0;
        
        auto token = tokens.begin();
        num1 = atoi((*token).c_str());
        token++;
        while (token != tokens.end())
        {
            if (*token == "+")
            {
                op = Operator::Add;
            }
            else if (*token == "-")
            {
                op = Operator::Minus;
            }
            else if (*token == "*")
            {
                op = Operator::Multiply;
            }
            else if (*token == "/")
            {
                op = Operator::Divide;
            }
            else
            {
                num2 = atoi((*token).c_str());
                switch (op)
                {
                    case Operator::Add:
                        num1 = num1 + num2;
                        break;
                    case Operator::Minus:
                        num1 = num1 - num2;
                        break;
                    case Operator::Multiply:
                        num1 = num1 * num2;
                        break;
                    case Operator::Divide:
                        num1 = num1 / num2;
                        break;
                }
            }
            token++;
        }
        
        return num1;
    }
};

void Test()
{
    Solution solution;
    assert(solution.calculate(" 3+5 / 2 ") == 5);
}
