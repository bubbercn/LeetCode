#pragma once
#include "Common.h"

class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> toBeEvaluated;
        for (const auto& token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int p2 = toBeEvaluated.top();
                toBeEvaluated.pop();
                int p1 = toBeEvaluated.top();
                toBeEvaluated.pop();
                toBeEvaluated.emplace(calculate(token, p1, p2));
            }
            else
            {
                toBeEvaluated.emplace(atoi(token.c_str()));
            }
        }
        assert(toBeEvaluated.size() == 1);
        return toBeEvaluated.top();
    }
private:
    inline int calculate(const string& op, int p1, int p2)
    {
        if (op == "+")
        {
            return p1 + p2;
        }
        else if (op == "-")
        {
            return p1 - p2;
        }
        else if (op == "*")
        {
            return p1 * p2;
        }
        else
        {
            return p1 / p2;
        }
    }
};

void Test()
{
    Solution solution;
    vector<string> tokens;
    
    tokens = {"2", "1", "+", "3", "*"};
    assert(solution.evalRPN(tokens) == 9);
    
    tokens = {"4", "13", "5", "/", "+"};
    assert(solution.evalRPN(tokens) == 6);
    
    tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    assert(solution.evalRPN(tokens) == 22);
}
