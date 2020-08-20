#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> addOperators(string num, int target)
    {
        if (num.size() == 0)
            return {};

        result.clear();
        string str;
        dfs(num, target, 0, 0, 0, str);
        return result;
    }

private:
    vector<string> result;

    void dfs(string num, int target, int idx, long total, long pre, string &path)
    {
        if (idx == num.size())
        {
            if (target == total)
                result.emplace_back(path);
            return;
        }

        size_t length = path.size();
        long curNum = 0;
        for (int i = idx; i < num.size(); i++)
        {
            string curString = num.substr(idx, i - idx + 1);
            if (curString.size() > 1 && curString[0] == '0')
                return;

            curNum = curNum * 10 + (num[i] - '0');
            if (idx == 0)
            {
                path += curString;
                dfs(num, target, i + 1, total + curNum, curNum, path);
                path.resize(length);
            }
            else
            {
                path += ("+" + curString);
                dfs(num, target, i + 1, total + curNum, curNum, path);
                path.resize(length);

                path += ("-" + curString);
                dfs(num, target, i + 1, total - curNum, -curNum, path);
                path.resize(length);

                path += ("*" + curString);
                dfs(num, target, i + 1, total - pre + pre * curNum, pre * curNum, path);
                path.resize(length);
            }
        }
    }
};

void Test()
{
    Solution solution;
    vector<string> output;

    output = {"1+2+3", "1*2*3"};
    assert(solution.addOperators("123", 6) == output);

    output = {"2+3*2", "2*3+2"};
    assert(solution.addOperators("232", 8) == output);

    output = {"1*0+5", "10-5"};
    assert(solution.addOperators("105", 5) == output);

    output = {"0+0", "0-0", "0*0"};
    assert(solution.addOperators("00", 0) == output);

    output = {};
    assert(solution.addOperators("3456237490", 9191) == output);

    // solution.addOperators("123456789", 45);
    // solution.addOperators("999999999", 80);
}