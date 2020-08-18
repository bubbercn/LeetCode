#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> addOperators(string num, int target)
    {
        vector<int> digits = toDigits(num);
        if (digits.empty())
            return {};

        if (digits.size() == 1)
        {
            if (digits[0] == target)
            {
                return {num};
            }
            else
            {
                return {};
            }
        }

        list<int> operators;
        vector<string> result;

        dfs(digits[0], stack<tuple<int, long, long>>(), digits, operators, result, target);

        return result;
    }

private:
    void dfs(long value, stack<tuple<int, long, long>>& state, const vector<int> &digits, list<int> &operators, vector<string> &result, int target)
    {
        if (operators.size() < digits.size() - 1)
        {
            for (int i = 0; i < 4; i++)
            {
                long t_value = 0;
                stack<tuple<int, long, long>> t_state = state;
                try
                {
                    t_value = eval(value, t_state, i, digits, operators);
                }
                catch (const std::exception &)
                {
                    continue;
                }
                operators.emplace_back(i);
                dfs(t_value, t_state, digits, operators, result, target);
                operators.pop_back();
            }
        }
        else
        {
            if (value == target)
            {
                // string temp = toString(digits, operators);
                // assert(temp != "1*2+3*4*5-6*7+8+9");
                result.emplace_back(toString(digits, operators));
            }
        }
    }

    long eval(long value, stack<tuple<int, long, long>>& state, int op, const vector<int> &digits, const list<int> &operators)
    {
        while (!state.empty() && ((get<0>(state.top()) > op || op == 1))
        {
            state.pop();
        }

        long *left = nullptr;
        if (!state.empty())
        {
            left = &get<2>(state.top());
        }
        else
        {
            left = &value;
        }
        long right = digits[operators.size() + 1];
        *left = calc(*left, right, op);

        if (state.empty())
        {
            state.emplace(op, *left, right);
        }
        else
        {
            get<2>(state.top()) = *left;
        }
        
    }

    long calc(long left, long right, int op)
    {
        switch (op)
        {
        case 0:
            return left + right;
            break;
        case 1:
            return left - right;
            break;
        case 2:
            return left * right;
            break;
        default:
        {
            if (left == 0)
            {
                throw exception();
            }
            else
            {
                return left * 10 + right;
            }
        }
        break;
        }
    }

    vector<int> toDigits(const string &num)
    {
        vector<int> result(num.size());
        for (int i = 0; i < num.length(); i++)
        {
            result[i] = num[i] - '0';
        }
        return result;
    }

    string toString(const vector<int> &digits, const list<int> &operators)
    {
        stringstream result;
        result << digits[0];
        auto it = operators.begin();
        for (int i = 1; i < digits.size(); i++)
        {
            string op;
            switch (*(it++))
            {
            case 3:
                break;
            case 0:
                op = "+";
                break;
            case 1:
                op = "-";
                break;
            default:
                op = "*";
                break;
            }
            result << op << digits[i];
        }
        return result.str();
    }
};

void Test()
{
    Solution solution;
    vector<string> output;

    // output = {"1+2+3", "1*2*3"};
    // assert(solution.addOperators("123", 6) == output);

    // output = {"2+3*2", "2*3+2"};
    // assert(solution.addOperators("232", 8) == output);

    // output = {"1*0+5", "10-5"};
    // assert(solution.addOperators("105", 5) == output);

    // output = {"0+0", "0-0", "0*0"};
    // assert(solution.addOperators("00", 0) == output);

    // output = {};
    // assert(solution.addOperators("3456237490", 9191) == output);

    solution.addOperators("123456789", 45);
}