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

        vector<int> operators(digits.size() - 1, 0);

        if (operators.empty())
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

        vector<string> result;
        do
        {
            //string toEvaluate = toString(digits, operators);
            int temp = 0;
            try
            {
                temp = evaluate(digits, operators);
            }
            catch (...)
            {
                continue;
            }

            if (temp == target)
            {
                result.emplace_back(toString(digits, operators));
            }
        } while (next(operators));

        return result;
    }

private:
    vector<int> toDigits(const string &num)
    {
        vector<int> result(num.size());
        for (int i = 0; i < num.length(); i++)
        {
            result[i] = num[i] - '0';
        }
        return result;
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
    string toString(const vector<int> &digits, const vector<int> &operators)
    {
        stringstream result;
        result << digits[0];
        for (int i = 0; i < operators.size(); i++)
        {
            string op;
            switch (operators[i])
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
            result << op << digits[i + 1];
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