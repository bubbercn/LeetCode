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
                int temp = sum;
                operators.emplace_back(i);
                int right = digits[i + 1];
                if (operators.back() == 0)
                {
                    if (temp == 0)
                    {
                        operators.pop_back();
                        continue;
                    }
                    temp = temp * 10 + right;
                }
                else if (operators.back() == 3)
                {
                    while (!ops.empty() && ops.top() == 3)
                    {
                        temp *= nums.top();
                        ops.pop();
                        nums.pop();
                    }

                    if (i + 1 < operators.size() && operators[i + 1] == 0)
                    {
                        nums.emplace(left);
                        ops.emplace(operators[i]);
                        temp = digits[i + 1];
                    }
                    else
                    {
                        temp *= right;
                    }
                }
                else
                {
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

                    if (i + 1 < operators.size() && (operators[i + 1] == 0 || operators[i + 1] == 3))
                    {
                        nums.emplace(left);
                        ops.emplace(operators.back());
                        temp = digits[i + 1];
                    }
                    else if (operators.back() == 1)
                    {
                        temp += right;
                    }
                    else
                    {
                        temp -= right;
                    }
                }
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
        }
        operators.pop_back();
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

    void tryNextOp(list<int> &ops, list<int> &results)
    {
        while (!ops.empty() && ++ops.back() == 4)
        {
            ops.pop_back();
            results.pop_back();
        }
    }

    int evaluate(const vector<int> &digits, const vector<int> &operators)
    {
        stack<int> nums;
        stack<int> ops;
        int left = digits[0];
        for (int i = 0; i < operators.size(); i++)
        {
            int right = digits[i + 1];
            if (operators[i] == 0)
            {
                if (left == 0)
                    throw "starting with 0 is not allowed";
                left = left * 10 + right;
            }
            else if (operators[i] == 3)
            {
                while (!ops.empty() && ops.top() == 3)
                {
                    left *= nums.top();
                    ops.pop();
                    nums.pop();
                }

                if (i + 1 < operators.size() && operators[i + 1] == 0)
                {
                    nums.emplace(left);
                    ops.emplace(operators[i]);
                    left = digits[i + 1];
                }
                else
                {
                    left *= right;
                }
            }
            else
            {
                while (!ops.empty())
                {
                    switch (ops.top())
                    {
                    case 1:
                        left += nums.top();
                        break;
                    case 2:
                        left = nums.top() - left;
                        break;
                    case 3:
                        left *= nums.top();
                        break;

                    default:
                        break;
                    }
                    ops.pop();
                    nums.pop();
                }

                if (i + 1 < operators.size() && (operators[i + 1] == 0 || operators[i + 1] == 3))
                {
                    nums.emplace(left);
                    ops.emplace(operators[i]);
                    left = digits[i + 1];
                }
                else if (operators[i] == 1)
                {
                    left += right;
                }
                else
                {
                    left -= right;
                }
            }
        }

        while (!ops.empty())
        {
            switch (ops.top())
            {
            case 1:
                left += nums.top();
                break;
            case 2:
                left = nums.top() - left;
                break;
            case 3:
                left *= nums.top();
                break;

            default:
                break;
            }
            ops.pop();
            nums.pop();
        }

        return left;
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
    bool next(vector<int> &operators)
    {
        operators[0]++;
        for (int i = 0; i < operators.size() - 1; i++)
        {
            if (operators[i] == 4)
            {
                operators[i + 1]++;
                operators[i] = 0;
            }
        }
        return *operators.rbegin() != 4;
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