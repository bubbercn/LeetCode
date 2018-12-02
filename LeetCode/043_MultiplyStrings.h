#pragma once
#include "Common.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> v1 = String2IntVector(num1);
        vector<int> v2 = String2IntVector(num2);
        vector<int> result = Multiply(v1, v2);
        return IntVector2String(result);
    }
private:
    vector<int> String2IntVector(const string& input)
    {
        vector<int> output;
        output.assign(input.length(), 0);
        
        auto j = output.rbegin();
        
        for (auto i : input)
        {
            *(j++) = i - '0';
        }
        
        return output;
    }
    
    string IntVector2String(const vector<int>& input)
    {
        string result;
        bool isAllZero = true;

        for (auto i = input.rbegin(); i != input.rend(); i++)
        {
            if (*i != 0)
                isAllZero = false;
            if (!isAllZero)
            {
                result += ('0' + *i);
            }
        }
        if (result.empty())
        {
            return "0";
        }
        else
        {
            return result;
        }
    }
    
    vector<int> Multiply(const vector<int>& v1, const vector<int>& v2)
    {
        vector<int> result;
        result.assign(v1.size() + v2.size(), 0);
        
        for (int i = 0; i < v2.size(); i++)
        {
            for (int j = 0; j < v1.size(); j++)
            {
                result[j + i] += v1[j] * v2[i];
            }
        }
        
        for (int i = 0; i < result.size() - 1; i++)
        {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
        
        return result;
    }
};

void Test()
{
    Solution solution;
    while (true)
    {
        string num1, num2;
        cin >> num1;
        cin >> num2;
        cout << solution.multiply(num1, num2);
    }
}
