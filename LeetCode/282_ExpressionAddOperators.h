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
        operators.emplace_back(0);
        stack<int> nums;
        stack<int> ops;

        dfs(digits[0], digits, operators, nums, ops, result, target);

        return result;
    }

private:
    void dfs(int sum, const vector<int> &digits, list<int> &operators, stack<int> nums, stack<int> ops, vector<string> &result, int target)
    {
        if (operators.size() < digits.size() - 1)
        {
            for (int i = 0; i < 4; i++)
            {
                int t_sum = sum;
                stack<int> t_nums = nums;
                stack<int> t_ops = ops;
                operators.emplace_back(i);
                int right = digits[i + 1];
                if (operators.back() == 0)
                {
                    if (t_sum == 0)
                    {
                        operators.pop_back();
                        continue;
                    }
                    t_sum = t_sum * 10 + right;
                }
                else if (operators.back() == 3)
                {
                    while (!ops.empty() && ops.top() == 3)
                    {
                        t_sum *= nums.top();
                        t_ops.pop();
                        t_nums.pop();
                    }

                    t_nums.emplace(t_sum);
                    t_ops.emplace(operators.back());
                }
                else
                {
                    while (!t_ops.empty())
                    {
                        switch (t_ops.top())
                        {
                        case 1:
                            t_sum += t_nums.top();
                            break;
                        case 2:
                            t_sum = t_nums.top() - t_sum;
                            break;
                        case 3:
                            t_sum *= t_nums.top();
                            break;

                        default:
                            break;
                        }
                        t_ops.pop();
                        t_nums.pop();
                    }

                    t_nums.emplace(t_sum);
                    t_ops.emplace(operators.back());
                }
                dfs(t_sum, digits, operators, t_nums, t_ops, result, target);
                operators.pop_back();
            }
        }
        else
        {
            int temp = sum;
            while (!ops.empty())
            {
                switch (ops.top())
                {
                case 1:
                    temp += nums.top();
                    break;
                case 2:
                    temp = nums.top() - temp;
                    break;
                case 3:
                    temp *= nums.top();
                    break;
                default:
                    break;
                }
                ops.pop();
                nums.pop();
            }
            if (temp == target)
            {
                result.emplace_back(toString(digits, operators));
            }
            operators.pop_back();
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
            case 0:
                break;
            case 1:
                op = "+";
                break;
            case 2:
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

    output = {"1+2+3", "1*2*3"};
    assert(solution.addOperators("123", 6) == output);

    output = {"2*3+2", "2+3*2"};
    assert(solution.addOperators("232", 8) == output);

    output = {"1*0+5", "10-5"};
    assert(solution.addOperators("105", 5) == output);

    output = {"0+0", "0-0", "0*0"};
    assert(solution.addOperators("00", 0) == output);

    output = {};
    assert(solution.addOperators("3456237490", 9191) == output);
}